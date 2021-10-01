CC = gcc
CFLAGS = -Wall -Werror -std=c99 

all: touch_impl

touch_impl:	touch_impl.c
	${CC} -o $@ ./$< ${CFLAGS}


.PHONY : clean
clean:	
	@rm touch_impl

