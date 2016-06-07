CC= gcc
CFLAGS= -lcrypt

all: md5gen bfgen

md5gen: md5gen.c
	$(CC) $(CFLAGS) md5gen.c -o md5gen

ow_libs:
	(cd ow_bcrypt; make)

bfgen: ow_libs bfgen.c
	$(CC) $(CFLAGS) bfgen.c ow_bcrypt/*.o ow_bcrypt/x86.S -o bfgen

clean:
	rm -rf *.o
	(cd ow_bcrypt; make clean)
