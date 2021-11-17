TARGET=calculadora
all: ${TARGET}

${TARGET}: main.o ${TARGET}parser.o ${TARGET}_lexer.o ast.o
	g++ -std=c++11 -g -o $@ $^ 

ast.o: ast.cpp ast.h
	g++ -std=c++11 -g -c -o $@ $<

main.o: main.cpp ${TARGET}parser.h
	g++ -std=c++11 -g -c -o $@ $<

${TARGET}parser.o: ${TARGET}parser.c ${TARGET}parser.h
	g++ -std=c++11 -g -c -o $@ $<

${TARGET}parser.h ${TARGET}parser.c: ${TARGET}parser.y
	lemon $<

${TARGET}_lexer.o: ${TARGET}_lexer.cpp
	g++ -std=c++11 -g -c -o $@ $<

${TARGET}_lexer.cpp: ${TARGET}.l
	flex -o $@ $<

%.c: %.y

clean:
	rm -f *.o
	rm -f ${TARGET}parser.h ${TARGET}parser.c ${TARGET}parser.out ${TARGET}_lexer.cpp
	rm -f ${TARGET}