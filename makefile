CC=gcc
CFLAGS=-I. -Wall -Wextra 

arc4: ARC4.cpp
	$(CC) -c ARC4.cpp $(CFLAGS)