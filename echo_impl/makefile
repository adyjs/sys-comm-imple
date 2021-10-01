CC = gcc
CFLAGS = -Wall -Werror -std=c99 

all: echo_impl

echo_impl:	echo_impl.c
	${CC} -o $@ ./$< ${CFLAGS}


.PHONY : clean
clean:	
	@rm echo_impl

