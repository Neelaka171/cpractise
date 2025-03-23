#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    int file_fd;
    if((file_fd = open("test3.txt" , O_WRONLY | O_CREAT)) == -1){
        perror("error creating:");
        exit(1);
    }

    int new_file_fd;
    if((new_file_fd = dup2(file_fd , 1 )) == -1){
        perror("eroor in dup 2:\n");\
        exit(1);
    }
    printf("haaii  ankanmk jandadk kamdk\n");
    printf("djijdn wjnsfjn fnjfkfnfkk\n");

}