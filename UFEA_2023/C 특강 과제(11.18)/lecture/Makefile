CCO = gcc -shared -o
CCC = gcc -fPIC -c -o
CC = gcc -g -o

LIB = -L./
LDADD = -lm

main : libtest-1.so main.o
	$(CC) main main.o $(LDADD) $(LIB) -ltest-1

libtest-1.so : test-1.o
	$(CCO) libtest-1.so test-1.o

test-1.o : test-1.cpp
	$(CCC) test-1.o test-1.cpp

main.o : main.cpp
	$(CCC) main.o main.cpp

clean:
	re -f *.o libtest-1.so
