CC= gcc
CFLAGS= -lcrypt -c

all: crypt_blowfish.o crypt_gensalt.o wrapper.o

crypt_blowfish.o: crypt_blowfish.c crypt_blowfish.h
	$(CC) $(CFLAGS) crypt_blowfish.c -o crypt_blowfish.o

crypt_gensalt.o: crypt_gensalt.c crypt_gensalt.h
	$(CC) $(CFLAGS) crypt_gensalt.c -o crypt_gensalt.o

wrapper.o: wrapper.c 
	$(CC) $(CFLAGS) wrapper.c -o wrapper.o

clean:
	rm -rf *.o
