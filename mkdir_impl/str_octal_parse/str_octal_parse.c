#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// void display_parse_result(const char *input, const char *output){
//     printf("%s : %s\n", input, output);
// }

unsigned int str_octal_to_decimal(const char *str_octal){

    unsigned int str_octal_len = strlen(str_octal);
    
    if(str_octal_len < 1 || str_octal_len > 11){
        printf("octal string length must be between 1 ~ 4 digits\n");
        exit(1);
    }
    
    unsigned int num = 0;
    unsigned int sum = 0;
    unsigned int power = (str_octal_len - 1);

    double pow_base = 8.0;

    for(int i=0 ; i<str_octal_len ; i++){

        char ch = *(str_octal+i);

        if(ch >= 48 && ch <= 57){
            num = ch - 48;
            sum += num * (unsigned int) pow(pow_base, (double)(power-i));
        }
        else{
            printf("input characters must only contains digit number\n");
            exit(1);
        }
    }
    return sum;
}



// int main(int argc, char *argv[]){

//     unsigned int num = str_octal_to_decimal(argv[1]);
//     printf("num : %u\n", num);
    // if(argc != 2){
    //     printf("str_octal_parse: octal_string\n");
    //     exit(1);
    // }

    // char *str_octal = argv[1];
    // unsigned int str_octal_len = strlen(str_octal);
    
    // if(str_octal_len < 1 || str_octal_len > 4){
    //     printf("octal string length must be between 1 ~ 4 digits\n");
    //     exit(1);
    // }
    
    // unsigned int num = 0;
    // unsigned int sum = 0;
    // unsigned int power = str_octal_len - 1;
    // double pow_base = 8.0;

    // for(int i=0 ; i<str_octal_len ; i++){
    //     char ch = *(str_octal+i);

    //     if(ch >= 48 && ch <= 57){
    //         num = ch - 48;
    //         sum += num * (unsigned int)pow(pow_base, (double)(power-i));
    //     }
    //     else{
    //         printf("input characters must only contains digit number\n");
    //         exit(1);
    //     }
    // }
    

    // printf("decimal : %u\n", sum);
//     return 0;
// }