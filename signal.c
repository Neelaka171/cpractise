#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<signal.h>

int main(){
    int child_pid;
    void interuppt_handle();
    child_pid = fork();
    if ( child_pid < 0 )
    {
        printf("fork is failed\n");
        exit(1);
    }
    if ( child_pid == 0){


        printf("child process:\n");
        if(signal(SIGINT , &interuppt_handle) == SIG_ERR){
            perror("Eroor during signal handling:\n");
            exit(1);

        }
        sleep(4);
        printf("child is completed:\n");

    }else{
        printf("parent process:\n");
        sleep(2);//waiting untill child is ready to get a signal
           if (kill (child_pid,SIGINT) == -1 )
            {
                perror("eroor occured during kill:\n");
                exit(1);
            }
           
        wait(NULL);
        printf("parent process is completed:\n");

    }
    
}
void interuppt_handle(){
    printf("inturuppt signal from parent:\n");
    signal(SIGINT , SIG_DFL);
}