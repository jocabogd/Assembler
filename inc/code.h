#ifndef _CODE_H_
#define _CODE_H_

#include <iostream>
#include <cstdio>
using namespace std;

#include <map>
#include <vector>

enum Prom {GLOBALNA = 1, LOKALNA = 2};	

static int br = 0;

typedef struct Symbol {
	string label;
	string section;
	short offset;		// u donosu na pocetak sekcije
	Prom prom;
	int size;		// koliko sekcija zauzima mesta u memoriji
	int rbr;
	// prava pristupa
	Symbol() {
		// empty
	}
	Symbol(string label, string section, short offset, Prom prom = LOKALNA, int size = 0) {
		this->label = label;
		this->section = section;
		this->offset = offset;
		this->prom = prom;
		this->size = size;
		this->rbr = ++br;
	}
} Symbol;

typedef struct Section {
	string name;
	short offset;		
	// sadrzaj treba
	string code;
	Section() {
		// empty
	}
	Section(string name, short offset, string code) {
		this->name = name;
		this->offset = offset;
		this->code = code;
	}
} Section;

typedef struct Relocation {
	string rel_section;	// za sekciju u kojoj se nalazi simbol
	string section;		// za sekciju gde treba da se napravi rel.zapis
	short offset;		// lokacija ciji se sadrzaj prepravlja
	string type;		// apsolutna ili pc relativna
	string symbol;		// koji je simbol (ili sekcija) u pitanju
	short addend;		// kao const pomeraj
	Relocation() {
		// empty
	}
	Relocation(string rel_section, string section, short offset, string type, string symbol, short addend) {
		this->rel_section = rel_section;
		this->section = section;
		this->offset = offset;
		this->type = type;
		this->symbol = symbol;
		this->addend = addend;
	}
} Relocation;

/*	Tipovi relokacije:
 * R_X86_64_PC32 (pc relativno): 
 * R_X86_64_32 (apsolutno): samo se u code doda offset simbola
*/

class Code {
public:
	map<string, Symbol> table_symbol;
	map<string, Section> table_section;
	map<string, vector<Relocation>> table_relocation;
	// char *current_code = (char*)malloc(64 * sizeof(char));
	string current_code;
	string current_section;
	Relocation current_relocation;
	
	void addSymbol(string label, string section, short offset, Prom prom);
	void set_size(string label, int size);

	void addByteToCode(short c);
	void addSection(string name, short offset, string code);

	void addRelocation(Relocation rel);
	
	void print_table_symbol() const;
	void print_table_section() const;
	void print_table_relocation() const;

	void write_in_output_file(const char* out) const;
};

#endif