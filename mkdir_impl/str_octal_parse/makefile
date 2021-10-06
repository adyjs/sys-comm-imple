CC = gcc
CFLAGS = -Wall -Werror -std=c99

OBJS = str_octal_parse.o
LIBS = libstr-octal-parse.a

all: ${OBJS} ${LIBS}

${OBJS}: str_octal_parse.c
	${CC} ${CFLAGS} -c $<

${LIBS}:	${OBJS}
	ar -rc $@ ${OBJS}

.PHONY: clean
clean:
	rm str_octal_parse ${OBJS} ${LIBS}