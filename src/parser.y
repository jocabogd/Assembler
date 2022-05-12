
%{
	
	#include <iostream>
	using namespace std;
	#include <vector>
	#include <string>
	#include <cstdio>
	
	#include "code.h"
	extern Code code;
	
	extern int yylex();
	extern int yyparse();
	extern FILE* yyin;
	
	void yyerror(const char* msg);
	
	extern int line_num;
	extern int first_pass;
	
	vector<string> symbol_list;
	
	short lc = 0;

	bool gloex = true;	// da li je global ili extern -> nisam koristila na kraju
	
	bool symlit;
	typedef struct sym_lit {
		string symbol;
		int literal;
	} sym_lit;
	sym_lit sl;
	vector<sym_lit> symlit_list;

	string instrukcija = "";
	string adresiranje = "";
	short val = 0x00;
	string symb = "";
	short regg = 0x00;

%}

%union {
	int ival;
	char* sval;
	long long lval;
}

%token GLOBAL EXTERN SECTION WORD SKIP EQU END
%token HALT INT IRET CALL RET JMP JEQ JNE JGT PUSH POP XCHG 
%token ADD SUB MUL DIV CMP NOT AND OR XOR TEST SHL SHR 
%token LDR STR
%token <ival> REG NUMBER
%token <sval> SYMBOL
%token PLUS MINUS MULTIPLY DIVIDE MOD 
%token COLON COMMA DOLLAR LBRACKET RBRACKET LPAREN RPAREN

%type<ival> Literal

%start Program

%%

Program: Line
		| Line Program;
		
Line: Label 
	 // | Label Instruction
	 // | Label Directive
	 | Instruction
	 | Directive;
	 
Label: SYMBOL COLON {
			// odmah se umece labela u tabelu simbola
			if (first_pass == 1) {
				if (code.table_symbol.find($1) != code.table_symbol.end()) {
					// cout << "zasto ne ovde?" << endl;
					if (code.table_symbol[$1].prom == GLOBALNA && 
						code.table_symbol[$1].section == "undefined") {
						code.table_symbol[$1].section = code.current_section;
						code.table_symbol[$1].offset = lc;
					} else {
						cout << "Greska na liniji: " << line_num << ". Simbol: " << $1 << " je vec u tabeli." << endl;
        				exit(-2);
					}
				} else {
					// cout << "zasto ovde?" << endl;
					code.addSymbol($1, code.current_section, lc, LOKALNA);
				}
			}
		};

Instruction: InstrWithoutReg
			| InstrWithReg REG {
				if (first_pass == 0) {
					short reg = $2 << 4;
					short sp = 0x06;
					if (instrukcija == "int") {
						code.addByteToCode(reg | 0x0f);
					} else if (instrukcija == "push") {
						code.addByteToCode(reg | sp);
						code.addByteToCode((0x01 << 4) | 0x02);
					} else if (instrukcija == "pop") {
						code.addByteToCode(reg | sp);
						code.addByteToCode((0x04 << 4) | 0x02);
					} else if (instrukcija == "not") {
						code.addByteToCode(reg | 0x0f);
					}
				}
			}
			| InstrOperand OperandJump
			| InstrRegs REG COMMA REG {
				if (first_pass == 0) {
					short regD = $2 << 4;
					short regS = $4;
					code.addByteToCode(regD | regS);
				}
			}
			| InstrRegOp REG COMMA Operand {
				short regD = $2 << 4;
				if (first_pass == 0) {
					if (adresiranje == "immedL") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x00);
						code.addByteToCode((val >> 8) & 0xff);
						code.addByteToCode(val & 0x00ff);
					} else if (adresiranje == "immedS") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x00);
						// relokacioni zapis
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_32", symb, 0};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else if (adresiranje == "memL") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x04);
						code.addByteToCode((val >> 8) & 0xff);
						code.addByteToCode(val & 0x00ff);
					} else if (adresiranje == "memS") {
						code.addByteToCode(regD | 0x0f);
						code.addByteToCode(0x04);
						// relokacioni zapis
						cout << "ovde 1: " << symb << " i " << lc << endl;
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_32", symb, 0};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else if (adresiranje == "pcrel") {
						short pc = 0x07;
						code.addByteToCode(regD | pc);
						code.addByteToCode(0x03);
						// relokacioni zapis
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_PC32", symb, -2};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else if (adresiranje == "regdir") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x01);
					} else if (adresiranje == "regind") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x02);
					} else if (adresiranje == "regindpomL") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x03);
						code.addByteToCode((val >> 8) & 0xff);
						code.addByteToCode(val & 0x00ff);
					} else if (adresiranje == "regindpomS") {
						code.addByteToCode(regD | regg);
						code.addByteToCode(0x03);
						// relokacioni zapis
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc-2), "R_X86_64_32", symb, 0};
						if (code.table_symbol.find(symb) != code.table_symbol.end()) {
							if (code.table_symbol[symb].section == "absolute") {
								code.addByteToCode((code.table_symbol[symb].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[symb].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol(symb, "undefined", (short)((int)lc-2), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					}
				}
			};
			
InstrWithoutReg: HALT {
					if (first_pass == 0) {
						//cout << "jesam li ovde?" << endl;
						code.addByteToCode(0x00);
						//code.current_code.push_back(0x00);
						//cout << code.current_code.length() << endl;
					}
					lc += 1;
				}
				| IRET {
					if (first_pass == 0) {
						code.addByteToCode(0x20);
					}
					lc += 1;
				}
				| RET {
					if (first_pass == 0) {
						code.addByteToCode(0x40);
					}
					lc += 1;
				};

InstrWithReg: INT {
				if (first_pass == 0) {
					instrukcija = "int";
					code.addByteToCode(0x10);
				}
				lc += 2;
			}
			| PUSH {
				if (first_pass == 0) {
					instrukcija = "push";
					code.addByteToCode(0xb0);	
				}
				lc += 3;
			}
			| POP {
				if (first_pass == 0) {
					instrukcija = "pop";
					code.addByteToCode(0xa0);	
				}
				lc += 3;
			}
			| NOT {
				if (first_pass == 0) {
					instrukcija = "not";
					code.addByteToCode(0x80);
				}
				lc += 2;
			};

InstrOperand: CALL {
				if (first_pass == 0) {
					code.addByteToCode(0x30);
				}
			}
			| JMP {
				if (first_pass == 0) {
					code.addByteToCode(0x50);
				}
			}
			| JEQ {
				if (first_pass == 0) {
					code.addByteToCode(0x51);
				}
			}
			| JNE {
				if (first_pass == 0) {
					code.addByteToCode(0x52);
				}
			}
			| JGT {
				if (first_pass == 0) {
					code.addByteToCode(0x53);
				}
			};

InstrRegs: XCHG {
				if (first_pass == 0) {
					code.addByteToCode(0x60);
				}
				lc += 2;
			}
		 | ADD {
			if (first_pass == 0) {
				code.addByteToCode(0x70);
			}
			lc += 2;
		 }
		 | SUB {
			if (first_pass == 0) {
				code.addByteToCode(0x71);
			}
			lc += 2;
		 }
		 | MUL {
			if (first_pass == 0) {
				code.addByteToCode(0x72);
			}
			lc += 2;
		 }
		 | DIV {
			if (first_pass == 0) {
				code.addByteToCode(0x73);
			}
			lc += 2;
		 }
		 | CMP {
			if (first_pass == 0) {
				code.addByteToCode(0x74);
			}
			lc += 2;
		 }
		 | AND {
			if (first_pass == 0) {
				code.addByteToCode(0x81);
			}
			lc += 2;
		 }
		 | OR {
			if (first_pass == 0) {
				code.addByteToCode(0x82);
			}
			lc += 2;
		 }
		 | XOR {
			if (first_pass == 0) {
				code.addByteToCode(0x83);
			}
			lc += 2;
		 }
		 | TEST {
			if (first_pass == 0) {
				code.addByteToCode(0x84);
			}
			lc += 2;
		 }
		 | SHL {
			if (first_pass == 0) {
				code.addByteToCode(0x90);
			}
			lc += 2;
		 }
		 | SHR {
			if (first_pass == 0) {
				code.addByteToCode(0x91);
			}
			lc += 2;
		 };

InstrRegOp: LDR {
				if (first_pass == 0) {
					code.addByteToCode(0xa0);
				}
			}
		  | STR {
			if (first_pass == 0) {
				code.addByteToCode(0xb0);
			}
		  };
		  
OperandJump: Literal {
				// neposredno: jmp broj
				if (first_pass == 0) {
					code.addByteToCode(0xff);	// 1111 ssss
					code.addByteToCode(0x00);	// uuuu aaaa
					// dodamo taj broj u code
					code.addByteToCode(((short)$1 >> 8) & 0xff);
					code.addByteToCode((short)$1 & 0x00ff);
				}
				lc += 5;
			}
		   | SYMBOL {
				// neposredno: jmp X
				if (first_pass == 0) {
						code.addByteToCode(0xff);	// 1111 ssss
						code.addByteToCode(0x00);	// uuuu aaaa
						// relokacioni zapis?
						code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_32", $1, 0};
						if (code.table_symbol.find($1) != code.table_symbol.end()) {
							if (code.table_symbol[$1].section == "absolute") {
								code.addByteToCode((code.table_symbol[$1].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[$1].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol($1, "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   }
		   | MOD SYMBOL {
			   	short pc = 0x07;
			   	// pc relativno: jmp %X je l' ovako bese... (saberu se pc i X)
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | pc);
					code.addByteToCode(0x05);	// 0000 0101
					// relokacioni zapis
					code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_PC32", $2, -2};
						if (code.table_symbol.find($2) != code.table_symbol.end()) {
							if (code.table_symbol[$2].section == "absolute") {
								code.addByteToCode((code.table_symbol[$2].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[$2].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol($2, "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   }
		   | MULTIPLY Literal {
			   	// memorijsko: jmp *broj
				if (first_pass == 0) {
					code.addByteToCode(0xff);
					code.addByteToCode(0x04); 	// 0000 0100
					code.addByteToCode(((short)$2 >> 8) & 0xff);
					code.addByteToCode((short)$2 & 0x00ff);
				}
				lc += 5;
		   }
		   | MULTIPLY SYMBOL {
			   	// memorijsko: jmp *X
				if (first_pass == 0) {
					code.addByteToCode(0xff);
					code.addByteToCode(0x04);
					// relokacioni zapis
					code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_32", $2, 0};
						if (code.table_symbol.find($2) != code.table_symbol.end()) {
							if (code.table_symbol[$2].section == "absolute") {
								code.addByteToCode((code.table_symbol[$2].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[$2].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol($2, "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   }
		   | MULTIPLY REG {
			   	// registarsko direktno: jmp reg
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | $2);
					code.addByteToCode(0x01);	// 0000 0001
				}
				lc += 3;
		   }
		   | MULTIPLY LBRACKET REG RBRACKET {
			   	// registarsko indirektno: jmp [reg]
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | $3);
					code.addByteToCode(0x02);	// 0000 0010
				}
				lc += 3;
		   }
		   | MULTIPLY LBRACKET REG PLUS Literal RBRACKET {
			   	// registarsko indirektno sa pomerajem: jmp [reg + broj]
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | $3);
					code.addByteToCode(0x03);	// 0000 0011
					code.addByteToCode(((short)$5 >> 8) & 0xff);
					code.addByteToCode((short)$5 & 0x00ff);
				}
				lc += 5;
		   }
		   | MULTIPLY LBRACKET REG PLUS SYMBOL RBRACKET {
			   	// registarsko indirektno sa pomerajem: jmp [reg + X]
				if (first_pass == 0) {
					code.addByteToCode(0xf0 | $3);
					code.addByteToCode(0x03);
					// relokacioni zapis
					code.current_relocation = {code.current_section, code.current_section, (short)((int)lc+3), "R_X86_64_32", $5, 0};
						if (code.table_symbol.find($5) != code.table_symbol.end()) {
							if (code.table_symbol[$5].section == "absolute") {
								code.addByteToCode((code.table_symbol[$5].offset >> 8) & 0xff);
								code.addByteToCode(code.table_symbol[$5].offset & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							} 
						} else {
							code.addSymbol($5, "undefined", (short)((int)lc+3), GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
				}
				lc += 5;
		   };

Operand: DOLLAR Literal {
			// neposredno: ldr reg, $broj
			if (first_pass == 0) {
				adresiranje = "immedL";
				val = $2;
			}
			lc += 5;
		}
	   | DOLLAR SYMBOL {
		   // neposredno: ldr reg, $X 
		   if (first_pass == 0) {
			   adresiranje = "immedS";
			   symb = $2;
		   }
		   lc += 5;
	   }
	   | Literal {
		   // memorijsko: ldr reg, broj
		   if (first_pass == 0) {
			   adresiranje = "memL";
			   val = $1;
		   }
		   lc += 5;
	   }
	   | SYMBOL {
		   // memorijsko: ldr reg, X
		   if (first_pass == 0) {
			   adresiranje = "memS";
			   symb = $1;
		   }
		   lc += 5;
	   }
	   | MOD SYMBOL {
		   // pc relativno: ldr reg, %X 
		   if (first_pass == 0) {
			   adresiranje = "pcrel";
			   symb = $2;
		   }
		   lc += 5;
	   }
	   | REG {
		   // registarsko direktno: ldr regD, regS
		   if (first_pass == 0) {
			   adresiranje = "regdir";
			   regg = $1;
		   }
		   lc += 3;
	   }
	   | LBRACKET REG RBRACKET {
		   // registarsko indirektno: ldr regD, [regS]
		   if (first_pass == 0) {
			   adresiranje = "regind";
			   regg = $2;
		   }
		   lc += 3;
	   }
	   | LBRACKET REG PLUS Literal RBRACKET {
		   // registarsko indirektno sa pomerajem: ldr regD, [regS + broj]
		   if (first_pass == 0) {
			   adresiranje = "regindpomL";
			   regg = $2;
			   val = $4;
		   }
		   lc += 5;
	   }
	   | LBRACKET REG PLUS SYMBOL RBRACKET {
		   // registarsko indirektno sa pomerajem: ldr regD, [regS + X]
		   if (first_pass == 0) {
			   adresiranje = "regindpomS";
			   regg = $2;
			   symb = $4;
		   }
		   lc += 5;
	   };

Directive: GLOBAL SymbolList {
				// ne radi se nista u prvom prolazu
				if (first_pass == 1) {
					// cout << "ovde?" << endl;
					gloex = true;
					for (int i = 0; i < symbol_list.size(); i++) {
						// cout << "hm?" << endl;
						code.addSymbol(symbol_list[i], "undefined", lc, GLOBALNA);
					}
				}
				/*if (first_pass == 0) {
					gloex = true;
					for (int i = 0; i < symbol_list.size(); i++) {
						code.table_symbol[symbol_list[i]].prom = GLOBALNA;
					}
				}*/
			}
		 | EXTERN SymbolList {
			 // isto ko GLOBAL 
			 if (first_pass == 0) {
				gloex = false;
				for (int i = 0; i < symbol_list.size(); i++) {
					if (code.table_symbol.find(symbol_list[i]) == code.table_symbol.end()) {
						code.addSymbol(symbol_list[i], "undefined", 0, GLOBALNA);
					}
				}
			 }
		 }
		 | SECTION SYMBOL {
			if (first_pass == 1) {
				//if (code.current_section != "") {
					// cout << "current section: " << code.current_section << "; size = " << lc << endl;
				//}
				// postavim size prethodne sekcije
				code.set_size(code.current_section, lc);
				lc = 0;
				// tekuca vrednost simbola je tekuca vrednost pc-a
				// kazem da je current section ova SYMBOL
				code.current_section = $2;
				// dodam simbol u tabelu simbola
				code.addSymbol($2, code.current_section, 0, LOKALNA);
			} else {
				// dodam sekciju u tabelu sekcija
				code.addSection(code.current_section, lc, code.current_code);
				// reset
				lc = 0;
				code.current_code.clear();
				// stavim da je current section ova SYMBOL
				code.current_section = $2;
			}
		 }
		 | WORD SymbolLiteralList {
			for (int i = 0; i < symlit_list.size(); i++) {
				if (first_pass == 0) {
					// radi se nesto u zavisnosti da li je simbol ili ne
					if (symlit == true) {
						code.current_relocation = {code.current_section, code.current_section, lc, "R_X86_64_32", symlit_list[i].symbol, 0};
						// code.current_relocation = rel;
						if (code.table_symbol.find(symlit_list[i].symbol) != code.table_symbol.end()) {
							// ako vec postoji simbol u tabeli
							if (code.table_symbol[symlit_list[i].symbol].section == "absolute") {
								// znaci da je konstanta
								short constt = code.table_symbol[symlit_list[i].symbol].offset;
								code.addByteToCode((constt >> 8) & 0xff);
								code.addByteToCode(constt & 0x00ff);
							} else {
								code.addRelocation(code.current_relocation);
							}
						} else {
							code.addSymbol(symlit_list[i].symbol, "undefined", lc, GLOBALNA);
							code.addRelocation(code.current_relocation);
						}
					} else {
						code.addByteToCode((((short)symlit_list[i].literal) >> 8) & 0xff);
						code.addByteToCode(((short)symlit_list[i].literal) & 0x00ff);
					}
				}
				// location counter se uvek povecava za 2 (za svaki word)
				lc += 2;
			}
		 }
		 | SKIP Literal {
			if (first_pass == 0) {
				for (int i = 0; i < $2; i++) {
					// alocira se prostor sa onoliko 0 koliko je vrednost literala
					code.addByteToCode(0x00);
				}
			}
			lc += $2;
		 }	
		 | EQU SYMBOL COMMA Literal {
			// cout << "lit: " << $4 << endl;
			if (first_pass == 1) {
				if (code.table_symbol.find($2) != code.table_symbol.end()) {
					if (code.table_symbol[$2].section == "undefined" &&
						code.table_symbol[$2].prom == GLOBALNA) {
						code.table_symbol[$2].section = "absolute";
						code.table_symbol[$2].offset = $4;
					} else {
						cout << "Greska na liniji: " << line_num << ". Simbol: " << $2 << " je vec u tabeli." << endl;
        				exit(-2);
					}
				} else {
					code.addSymbol($2, "absolute", (unsigned short)$4, LOKALNA);
				}
			}
		 }
		 | END {
			if (first_pass == 1) {
				code.set_size(code.current_section, lc);
			} else {
				code.addSection(code.current_section, lc, code.current_code);
				code.current_code.clear();
				lc = 0;
			}
			// YYACCEPT;
		 };
		 
SymbolList: SYMBOL {
				if (first_pass == 1) {
					symbol_list.clear();
					symbol_list.push_back($1);
				}
			}
		  | SYMBOL COMMA SymbolList {
			    if (first_pass == 1) {
					symbol_list.push_back($1);
				}
			};

SymbolLiteralList: SymbolLiteral {
						symlit_list.clear();
						symlit_list.push_back(sl);
				    }
				 | SymbolLiteral COMMA SymbolLiteralList {
					 	symlit_list.push_back(sl);
				    };
				 
SymbolLiteral: SYMBOL {
					symlit = true;
					sl = { $1 };
			    }
			 | Literal {
				 	symlit = false;
					sl = { "", $1 };
			    };

Literal: NUMBER { $$ = $1; }
	   | PLUS NUMBER { $$ = $2; }
	   | MINUS NUMBER { $$ = (-1) * $2; }; 
	   
%%

void yyerror(const char* msg) {
	cout << "Greska u parseru: " << msg << " i to na liniji: " << line_num << endl;
	exit(-1);
}