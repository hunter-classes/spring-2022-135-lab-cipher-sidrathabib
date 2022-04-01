main: main.o funcs.o
    g++ -o main main.o funcs.o

tests: tests.o funcs.o
    g++ -o tests tests.o funcs.o


funcs.o: funcs.cpp funcs.h
    g++ -c -std=c++11 -Wall funcs.cpp

main.o: main.cpp funcs.h
    g++ -c -std=c++11 -Wall main.cpp

tests.o: tests.cpp doctest.h funcs.h
    g++ -c -std=c++11 -Wall tests.cpp


clean:
    rm -f main.o funcs.o tests.o