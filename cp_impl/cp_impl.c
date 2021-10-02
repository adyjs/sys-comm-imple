#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
open
read
write
lseek
close

*/

#define RD_BUF 128

int main(int argc, char *argv[]){
    // struct stat status;
    // char *file = "makefile";
    // stat(argv[1], &status);
    // printf("stat_ret : %d\n", stat_ret);
    // printf("mode_t : %o\n", status.st_mode);
    // int source_stat_mode = status.st_mode & 0777;
    // printf("%o\n", bits);
    // printf("regular file : %d\n", S_ISREG(status.st_mode));
    // printf("directory : %d\n", S_ISDIR(status.st_mode));
    // printf("char device: %d\n", S_ISCHR(status.st_mode));
    // printf("block device : %d\n", S_ISBLK(status.st_mode));
    // printf("FIFO : %d\n", S_ISFIFO(status.st_mode));
    // printf("symbolic file : %d\n", S_ISLNK(status.st_mode));
    // printf("socket file : %d\n", S_ISSOCK(status.st_mode));
    // return 0;



    if(argc != 3){
        perror("cp_impl: [copy_source] [target]");
        exit(1);
    }

    char *copy_source = argv[1];
    if((access(copy_source, F_OK)) == -1){
        perror("cp_impl: copy_source is not exist.");
        exit(1);
    }
    
    struct stat status;
    stat(copy_source, &status);
    int source_stat_mode = status.st_mode & 0777;
    
    char *target = argv[2];
    if((access(target, F_OK)) == 0){
        perror("cp_impl: target is already exist.");
        perror("cp_impl: try another file name for target file.");
        exit(1);
    }

    int target_fd = open(target, O_CREAT | O_RDWR, source_stat_mode);
    if(target_fd == -1){
        perror("cp_impl: file create failed.");
        exit(1);
    }

    char buf[RD_BUF+1];
    memset(buf, '\0', sizeof(buf));

    int copy_source_fd = open(copy_source, O_RDONLY);
    
    ssize_t rd_count = -1;
    ssize_t wt_count = -1;
    while((rd_count = read(copy_source_fd, buf, RD_BUF)) != 0){
        wt_count = write(target_fd, buf, rd_count);
        printf("wt_count : %ld\n", wt_count);
    }

    int close_ret;
    if((close_ret = close(copy_source_fd)) != 0){
        perror("copy source file descriptor close failed");
        exit(1);
    }
    
    if((close_ret = close(target_fd)) != 0){
        perror("target file descriptor close failed");
        exit(1);
    }

    printf("Copy operation is OK\n");
    return 0;
}