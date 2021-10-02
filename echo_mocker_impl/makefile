CC = gcc
CFLAGS = -Wall -Werror -std=c99 

all: echo_mocker_impl

echo_mocker_impl:	echo_mocker_impl.c
	${CC} -o $@ ./$< ${CFLAGS}


.PHONY : clean
clean:	
	@rm echo_mocker_impl

