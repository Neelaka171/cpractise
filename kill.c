#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<signal.h>

int main(){
    int child_pid;
    child_pid = fork();
    if ( child_pid < 0 )
    {
        printf("fork is failed\n");
        exit(1);
    }
    if ( child_pid == 0){


        printf("child process:\n");
        sleep(4);
        printf("child is completed:\n");

    }else{
        printf("parent process:\n");
           /* if (kill (child_pid,SIGKILL) == -1 )
            {
                perror("eroor occured during kill:\n");
                exit(1);
            }
            */
           if(kill(child_pid , SIGSTOP) == -1){
            perror("error during stop:\n");
            exit(1);
           }
           printf("told child to stop 2 second\n");
           sleep(2);


           if(kill(child_pid , SIGCONT) == -1){
            perror("error during continue child:\n");
            exit(1);
           }
        wait(NULL);
        printf("parent process is completed:\n");

    }
}