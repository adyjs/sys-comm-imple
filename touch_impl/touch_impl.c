#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_SIZE 10

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("touch_impl: missing file operand\n");
        exit(1);
    }

    for(int i=1 ; i<argc ; i++){
        if(strlen(argv[i]) > ARG_SIZE){
            printf("%s : file name size must less then 11.\n", argv[i]);
            exit(1);
        }
    }

    int fd;
    for(int i=1 ; i<argc ; i++){
        fd = open(argv[i], O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
        // printf("fd : %d\n", fd);
        if( fd == -1){
            printf("open file failed, maybe %s is already exist.\n", argv[i]);
            exit(1);
        }
        close(fd);
    }

    return 0;
}