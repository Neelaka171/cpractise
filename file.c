#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    int file_fd;
    if((file_fd = open("test.txt" , O_WRONLY | O_CREAT)) == -1){
        perror("error creating:");
        exit(1);
    }

    char * buffer ="abc hutta pakaya yo yo neelaka\n";
    if(write(file_fd , buffer , strlen(buffer)) == -1)
    {
        perror("write error:");
        exit(1);
    }


    int new_file_fd;
    if((new_file_fd = dup(file_fd)) == -1)
    {
        perror("error on dup:\n");
        exit(1);

    }

    char * buffer_2 ="write from new file dis\n";
    if(write(new_file_fd , buffer_2 , strlen(buffer_2)) == -1)
    {
        perror("write error:");
        exit(1);
    }

    int new_file1_fd;
    if((new_file1_fd = dup(file_fd)) == -1)
    {
        perror("error on dup:\n");
        exit(1);

    }

    char * buffer_3 ="write from new1 file dis\n";
    if(write(new_file_fd , buffer_3 , strlen(buffer_3)) == -1)
    {
        perror("write error:");
        exit(1);
    }

}