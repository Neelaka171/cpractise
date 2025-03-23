#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){
    printf("Helo World\n");
    int pid = fork();
    if(pid < 0){
        printf("fork failee:");
        exit(1);
    }
    if (pid == 0){
        printf("child process\n");
        execlp("./new" ,"",NULL);
        printf("Ending child process");
    }else{
        printf("parent process:\n");
        wait(NULL); 
        printf("Parent process ending\n");
    }
    
    


}