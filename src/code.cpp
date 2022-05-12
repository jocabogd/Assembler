#include "code.h"

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#include <fstream>

extern int line_num;

void Code::addSymbol(string label, string section, short offset, Prom prom) {
    //cout << label << endl;
    if (table_symbol.find(label) == table_symbol.end()) {
        //cout << "Hello " << label << endl;
        Symbol symbol = Symbol(label, section, offset, prom, 0);
        table_symbol[label] = symbol;
    } else {
        cout << "Greska na liniji: " << line_num << ". Simbol: " << label << " je vec u tabeli." << endl;
        exit(-2);
    }
}

void Code::set_size(string label, int size) {
    table_symbol[label].size = size;
}

void Code::addByteToCode(short c) {
    string temp;
    sprintf(&temp[0], "%02x", c);
    current_code += &temp[0];
}

void Code::addSection(string name, short offset, string code) {
    // if (table_section.find(name) == table_section.end()) {
        Section section = Section(name, offset, code);
        table_section[name] = section;
    /* } else {
        cout << "Greska na liniji: " << line_num << ". Sekcija: " << name << " je vec u tabeli." << endl;
        exit(-5);
    } */
}

void Code::addRelocation(Relocation rel) {
    Symbol symbol = table_symbol[rel.symbol];
    if (rel.type == "R_X86_64_PC32") {
        // pc relativno
        if (symbol.prom == LOKALNA) {
            short off = symbol.offset - rel.addend;
            addByteToCode((off >> 8) & 0xff);
            addByteToCode(off& 0x00ff);
            // ako je ista sekcija: upise se sve, a za istu sekciju ne pravi se rel.zapis
            if (rel.section == symbol.section) {
                return;
            } else {
            // ako nije ista sekcija: upise se addend i kreira se rel.zapis za sekciju
                rel.symbol = symbol.section;
            }
        } else if (symbol.prom == GLOBALNA) {
            // upise se addend i napravi se rel.zapis za taj simbol
            addByteToCode((rel.addend >> 8) & 0xff);
            addByteToCode(rel.addend & 0x00ff);
        }
    } else if (rel.type == "R_X86_64_32") {
        // apsolutno 
        if (symbol.prom == LOKALNA) {
            // upise se offset a kreira se rel.zapis za sekciju
            addByteToCode((symbol.offset >> 8) & 0xff);
            addByteToCode(symbol.offset & 0x00ff);
            rel.symbol = symbol.section;
        } else if (symbol.prom == GLOBALNA) {
            // ne moze nista da se upise ako nije definisan
            addByteToCode(0x00);
            addByteToCode(0x00);
        }
    }
    table_relocation[rel.rel_section].push_back(rel);
}

void Code::print_table_symbol() const {
    // cout << "===============================================================================" << endl;
    cout << endl;
    cout << "Tabela simbola: " << endl;
    cout << "===============================================================================" << endl;
    cout << "RBr    | Labela     | Sekcija       | Ofset        | Lokalna?      | Velicina  " << endl;
    cout << "===============================================================================" << endl;
    string lokglo = "";
    for (auto i = table_symbol.begin(); i != table_symbol.end(); i++) {
        Symbol symbol = i->second;
        if (symbol.prom == 1) {
            lokglo = "globalna";
        } else if (symbol.prom == 2) {
            lokglo = "lokalna";
        }
        if (lokglo == "globalna") {
            if (symbol.label.length() > 7) {
                if (symbol.section.length() > 7) {
                    cout << symbol.rbr << "\t" << symbol.label << "\t" << symbol.section << "\t" << symbol.offset << "\t\t" << lokglo << "\t" << symbol.size << endl;  
                } else {
                    cout << symbol.rbr << "\t" << symbol.label << "\t" << symbol.section << "\t\t" << symbol.offset << "\t\t" << lokglo << "\t" << symbol.size << endl;  
                }
            } else {
                if (symbol.section.length() > 7) {
                    cout << symbol.rbr << "\t" << symbol.label << "\t\t" << symbol.section << "\t" << symbol.offset << "\t\t" << lokglo << "\t" << symbol.size << endl;
                } else {
                    cout << symbol.rbr << "\t" << symbol.label << "\t\t" << symbol.section << "\t\t" << symbol.offset << "\t\t" << lokglo << "\t" << symbol.size << endl;
                }
            }
        } else if (lokglo == "lokalna") {
            if (symbol.label.length() > 7) {
                if (symbol.section.length() > 7) {
                    cout << symbol.rbr << "\t" << symbol.label << "\t" << symbol.section << "\t" << symbol.offset << "\t\t" << lokglo << "\t\t" << symbol.size << endl;
                } else {
                    cout << symbol.rbr << "\t" << symbol.label << "\t" << symbol.section << "\t\t" << symbol.offset << "\t\t" << lokglo << "\t\t" << symbol.size << endl;
                }
            } else {   
                if (symbol.section.length() > 7) {         
                    cout << symbol.rbr << "\t" << symbol.label << "\t\t" << symbol.section << "\t" << symbol.offset << "\t\t" << lokglo << "\t\t" << symbol.size << endl;
                } else {
                    cout << symbol.rbr << "\t" << symbol.label << "\t\t" << symbol.section << "\t\t" << symbol.offset << "\t\t" << lokglo << "\t\t" << symbol.size << endl;
                }
            }
        }
    } 
    cout << "===============================================================================" << endl;
    cout << endl;
    cout << endl;
}

void Code::print_table_section() const {
    cout << "Sekcije i kodovi: " << endl;
    cout << "===============================================================================" << endl;
    for (auto i = table_section.begin(); i != table_section.end(); i++) {
        cout << "> " << i->first << "(" << i->second.offset << "): ";
        for (int j = 0; j < i->second.code.size(); j++) {
            cout << i->second.code[j];
            if (j % 2 == 1) cout << " ";
        }
        cout << endl;
    }
    /*for (int i = 0; i < current_code.size(); i++) {
        cout << current_code[i];
        if (i % 2 == 1) cout << " ";
    }*/
    cout << "===============================================================================" << endl;
    cout << endl;
    cout << endl;
}

void Code::print_table_relocation() const {
    int brojac = 0;
    cout << "Relokacioni zapisi: " << endl;
    cout << "===============================================================================" << endl;
    for (auto i = table_relocation.begin(); i != table_relocation.end(); i++) {
        brojac++;
        cout << "> " << i->first << ":" << endl;
        cout << "**********************************************************************" << endl;
        cout << "Sekcija    | Ofset    | Tip relokacije      | Simbol        | Addend  " << endl;
        cout << "**********************************************************************" << endl;
        for (int j = 0; j < i->second.size(); j++) {
            Relocation rel = i->second[j];
            if (rel.section.length() > 7) {
                if (rel.symbol.length() > 7) {
                    cout << rel.section << "\t" << rel.offset << "\t" << rel.type << "\t\t" << rel.symbol << "\t" << rel.addend << endl;
                } else {
                    cout << rel.section << "\t" << rel.offset << "\t" << rel.type << "\t\t" << rel.symbol << "\t\t" << rel.addend << endl;
                }
            } else {
                if (rel.symbol.length() > 7) {
                    cout << rel.section << "\t\t" << rel.offset << "\t" << rel.type << "\t\t" << rel.symbol << "\t" << rel.addend << endl;
                } else {
                    cout << rel.section << "\t\t" << rel.offset << "\t" << rel.type << "\t\t" << rel.symbol << "\t\t" << rel.addend << endl;
                }
            }
        }
        if (brojac != table_relocation.size()) cout << endl;
    }
    cout << "===============================================================================" << endl;
    cout << endl;
}

void Code::write_in_output_file(const char* out) const {
    ofstream file;
    file.open(out, ios::out);

    file << "Tabela simbola: \n";
    file << "RBr, Labela, Sekcija, Ofset , Lokalna?, Velicina\n";

    string lokglo = "";
    for (auto i = table_symbol.begin(); i != table_symbol.end(); i++) {
        Symbol symbol = i->second;
        if (symbol.prom == 1) {
            lokglo = "globalna";
        } else if (symbol.prom == 2) {
            lokglo = "lokalna";
        }
        if (symbol.rbr != 0) {
            file << symbol.rbr << ", " << symbol.label << ", " << symbol.section << ", " << symbol.offset << ", " << lokglo << ", " << symbol.size << "\n";
        }
    }

    file << "\n";

    file << "Sekcije i kodovi: \n";

    for (auto i = table_section.begin(); i != table_section.end(); i++) {
        // > naziv(velicina): code
        file << "> " << i->first << "(" << i->second.offset << "): ";
        for (int j = 0; j < i->second.code.size(); j++) {
            file << i->second.code[j];
            if (j % 2 == 1) file << " ";
        }
        file << "\n";
    }

    file << "\n";

    file << "Relokacioni zapisi: \n";

    for (auto i = table_relocation.begin(); i != table_relocation.end(); i++) {
        // Naziv sekcije:
        file << "> " << i->first << ":" << "\n";
        file << "Sekcija, Ofset, Tip relokacije , Simbol, Addend\n";
        for (int j = 0; j < i->second.size(); j++) {
            Relocation rel = i->second[j];
            file << rel.section << ", " << rel.offset << ", " <<rel.type << ", " << rel.symbol << ", " << rel.addend << "\n";
        }
        file << "\n";
    }

    file.close();
} 
