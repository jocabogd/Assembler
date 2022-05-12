all: assembler

clean:
	rm -rf src/bison.cpp inc/bison.hpp src/flex.cpp assembler *.o
src/bison.cpp inc/bison.hpp: src/parser.y
	bison -o src/bison.cpp --defines=inc/bison.hpp src/parser.y
src/flex.cpp: src/lexer.l src/bison.cpp
	flex -o src/flex.cpp src/lexer.l
assembler: src/flex.cpp
	g++ -std=c++17 -o assembler src/*.cpp -Iinc

test: assembler
	./assembler -o tests/main.o tests/main.s
	./assembler -o tests/interrupts.o tests/interrupts.s