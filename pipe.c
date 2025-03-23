#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pipefd[2];
    pipe(pipefd);


    int pid = fork();
    if( pid < 0){
        printf("fork is failed\n");
        exit(0);
    }
    int sum = 0;
    if( pid == 0){
        printf("child process:\n");
        int sum = 0;
        for (int i = 1; i <= 5000 ; i++)
        {
                sum  += i;
        }
        printf("child process sum is:%d\n",sum);

        write(pipefd[1] , &sum , sizeof(sum));
        close(pipefd[1]);


    }else{
        printf("Parent process\n");
        int child_sum;
        printf("Parent process going to read\n");

        read(pipefd[0] ,&child_sum , sizeof(child_sum));
        close(pipefd[0]);

        printf("child sum is:%d\n",child_sum);
        int sum = child_sum;
        for (int i = 5001; i <= 10000 ; i++)
        {
            sum += i;
        }
        printf("parent process sum:%d\n",sum);
        wait(NULL);

    }












}