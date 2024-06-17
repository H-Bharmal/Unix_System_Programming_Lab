#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int pid1 = fork();

    if(pid1 == 0){
        printf("Inside child one");
        sleep(3);
        exit(0);
    }
    else if(pid1 > 0){
        printf("Inside parent process\n");
        int pid2 = fork();
        if(pid2 == 0){
            printf("Inside child 2\n");
            sleep(5);
            exit(0);
        }

        //make parent wait for any child
        int status ;
        wait(&status);
        if(WIFEXITED(status)){
            printf("A child process exits with status %d\n", WIFEXITED(status));
        }

        //waiting for child 2 specifically
        waitpid(pid2, &status, 0);
        if(WIFEXITED(status)){
            printf("Second child process exits with status %d\n", WIFEXITED(status));
        }
            printf("Parent process finished.\n");

    }
}