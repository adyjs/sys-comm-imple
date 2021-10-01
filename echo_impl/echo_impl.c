#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARG_SIZE 100

int main(int argc, char *argv[]){
    if(argc == 1)
        exit(1);

    if(argc > 2){
        printf("echo_impl: accept only 1 string.\n");
        printf("echo_impl: or it may need to quotation marks like this \"your input string\".\n");
        exit(1);
    }
    if(strlen(argv[1]) > ARG_SIZE){
        printf("echo_impl: the max sizeo of string is 100 bytes\n");
        exit(1);
    }

    ssize_t str_len = strlen(argv[1]);
    
    write(1, argv[1], str_len);
    write(1, "\n", 1);



    return 0;
}

