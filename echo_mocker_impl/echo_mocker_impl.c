#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARG_SIZE 5

int main(int argc, char *argv[]){

    char *beginningWord = "Just type-in what you want to say.\n\n";
    write(1, beginningWord, strlen(beginningWord));

    char rd_buf[ARG_SIZE+1] = {0};
    char c;
    ssize_t rd_count = 0;

    while(1){
        memset(rd_buf, '\0', ARG_SIZE+1);
        
        do{
            read(0, &c, 1);
        
            if(c == '\n')
                break;

            rd_buf[rd_count++] = c;
        
        }while(rd_count < ARG_SIZE);

        rd_buf[rd_count] = '\0';
        write(1, rd_buf, rd_count);
        
        if(c == '\n')
            write(1, "\n\n", 2);
        
        rd_count = 0;
    }

    return 0;
}

