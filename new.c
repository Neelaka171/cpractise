#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    int b;
    b = fork();
        if( b < 0){
            printf("Fork failed:\n");
            exit(0);
        }
        if(b == 0){
            printf("child here.pid:%d ppid : %d \n",getpid(),getppid());
            sleep(15);
            printf("child is completed:\n");
        }else{
            printf("parent here.pid:%d  \n",getpid());
            wait(NULL);
            printf("parent is completed:\n");
        }






}