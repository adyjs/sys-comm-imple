
CC = gcc
CFLAGS = -Wall -Werror -std=c99

libstr-octal-parse-path = -L./str_octal_parse/ -lstr-octal-parse
libmath = -lm

all: libstr-octal-parse-static-lib mkdir_impl

libstr-octal-parse-static-lib:
	$(MAKE) -C ./str_octal_parse

mkdir_impl:	mkdir_impl.c
	${CC} ${CFLAGS} -o $@ ./mkdir_impl.c ${libstr-octal-parse-path} ${libmath}

.PHONY: clean
clean:
	rm mkdir_impl 