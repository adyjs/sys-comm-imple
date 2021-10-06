CC = gcc
CFLAGS = -Wall -Werror -std=c99

all: str_octal_parse.o libstr-octal-parse.a 

str_octal_parse.o: str_octal_parse.c
	${CC} ${CFLAGS} -c $<
 
libstr-octal-parse.a: str_octal_parse.o
	ar -rc $@ ./str_octal_parse.o

.PHONY: clean
clean:
	rm str_octal_parse.o libstr-octal-parse.a