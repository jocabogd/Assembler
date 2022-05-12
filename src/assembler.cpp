#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "code.h"
#include <cstring>

extern FILE* yyin;
extern int yyparse();

extern int line_num;
int first_pass;

Code code;

int main(int argc, char* argv[]) {

    const char* out = NULL;

    if (argc < 4) {
        cout << "Greska: Nedostaju argumenti." << endl;
        exit(-3);
    } else {
        out = argv[2];
        yyin = fopen(argv[3], "r");
        if (yyin == NULL) {
            cout << "Greska: Nije otvoren fajl." << endl;
            exit(-4);
        }
    }

    // prvi prolaz
    first_pass = 1;
    while (1) {
        yyparse();
        if (feof(yyin)) {
            break;
        }
    }

    // reset
    line_num = 1;
    rewind(yyin);

    // drugi prolaz
    first_pass = 0;
    while (1) {
        yyparse();
        if (feof(yyin)) {
            break;
        }
    }

    // prikaz
    code.print_table_symbol();
    code.print_table_section();
    code.print_table_relocation();

    // upis u izlazni fajl:
    code.write_in_output_file(out);

    fclose(yyin);
    return 0;
	
}