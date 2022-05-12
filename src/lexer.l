
%option noyywrap

%{
	#include <iostream>
	using namespace std;

	#include <string>
	
	#include "bison.hpp"

	int line_num = 1; 
%}

%%

[ \t\r\f]+	{}
\n		{ line_num += 1; }

".global"	{ return GLOBAL; }
".extern"	{ return EXTERN; }
".section"	{ return SECTION; }
".word"		{ return WORD; }
".skip"		{ return SKIP; }
".equ"		{ return EQU; }
".end"		{ return END; }
"halt"		{ return HALT; }
"int"		{ return INT; }
"iret"		{ return IRET; }
"call"		{ return CALL; }
"ret"		{ return RET; }
"jmp"		{ return JMP; }
"jeq"		{ return JEQ; }
"jne"		{ return JNE; }
"jgt"		{ return JGT; }
"push"		{ return PUSH; }
"pop"		{ return POP; }
"xchg"		{ return XCHG; }
"add"		{ return ADD; }
"sub"		{ return SUB; }
"mul"		{ return MUL; }
"div"		{ return DIV; }
"cmp"		{ return CMP; }
"not"		{ return NOT; }
"and"		{ return AND; }
"or"		{ return OR; }
"xor"		{ return XOR; }
"test"		{ return TEST; }
"shl"		{ return SHL; }
"shr"		{ return SHR; }
"ldr"		{ return LDR; }
"str"		{ return STR; }
(r[0-7])	{ yylval.ival = atoi(yytext + 1); return REG; }
"sp"		{ yylval.ival = 6; return REG; }
"pc"		{ yylval.ival = 7; return REG; }
"spw"		{ yylval.ival = 8; return REG; }
"+"			{ return PLUS; }
"-"			{ return MINUS; }
"*"			{ return MULTIPLY; }
"/"			{ return DIVIDE; }
"%"			{ return MOD; }
":"			{ return COLON; }
","			{ return COMMA; }
"$"			{ return DOLLAR; }
"["			{ return LBRACKET; }
"]"			{ return RBRACKET; }
"("			{ return LPAREN; }
")"			{ return RPAREN; }

[0-9]+		{ yylval.ival = atoi(yytext); return NUMBER; }
([a-z]|[A-Z])[a-z|A-Z|0-9|_]*	{ yylval.sval = strdup(yytext); return SYMBOL; }
0[xX][0-9a-fA-F]{1,4}			{ yylval.ival = stoi(yytext, nullptr, 16); return NUMBER; }

#.*\n		{ line_num += 1; }		

.		{ cout << "Greska na liniji: " << line_num << endl; exit(-1); }	

%%