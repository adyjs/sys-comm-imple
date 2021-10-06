#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "./str_octal_parse/str_octal_parse.h"

typedef unsigned int dir_mode_t;

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("ERROR : mkdir_impl dir_name dir_mode\n");
        exit(1);
    }
    
    char *dir_name = argv[1];
    dir_mode_t mode = str_octal_to_decimal(argv[2]);

    if(-1 == mkdir(dir_name, mode)){
        printf("ERROR : directory create failed\n");
        exit(1);
    }

    printf("Directory %s created success, mode : %o\n", dir_name, mode);

    return 0;
}