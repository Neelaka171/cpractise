
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){

    int b;
    b = fork();
        if(b<0){
            printf("Fork failed:\n");
            exit(0);
        }
        if(b == 0){
            printf("child here.pid:%d ppid : %d \n",getpid(),getppid());
            sleep(5);
           /* if (){
                exit(1);
            }else if
            {
                exit(2);
            }else{
                exit(0);
            }*/
            
            exit(4);
            printf("child is completed:\n");
        }else{
            int waitval;
            printf("parent here.pid:%d  \n",getpid());
            wait(&waitval);
            printf("parent is completed:child exit value:%d\n",WEXITSTATUS(waitval));
        }






}