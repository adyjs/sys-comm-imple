CC = gcc
CFLAGS = -Wall -Werror -std=c99 

all: cp_impl

cp_impl:	cp_impl.c
	${CC} -o $@ ./$< ${CFLAGS}


.PHONY : clean
clean:	
	@rm cp_impl

