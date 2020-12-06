CC = gcc
W = -Wall
AR = ar
Bank = myBank.o
fPIC = -fPIC


all: mains maind


mains: main.o myBank.a
	$(CC) $(FLAG) -g -o mains main.o myBank.a

	
maind: main.o myBank.so
	$(CC) $(FLAG) -g -o maind main.o ./myBank.so

	
myBank.a: $(Bank)
	$(AR) rcs -o myBank.a myBank.o
	
myBank.so: $(Bank)
	$(CC) -shared $(Bank)  -o myBank.so
	
myBank.o : myBank.c myBank.h
	$(CC) $(FLAG) $(fPIC) -g -c myBank.c
	
main.o : myBank.h main.c
	$(CC) $(FLAG) -g -c main.c
	
.PHONY: clean all
clean:
	rm -f *.o *.a *.so mains maind
