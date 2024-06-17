#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    int pid = fork();

    if(pid < 0){
        printf("Error creating child\n");
        return -1 ;
    }
    else if(pid == 0){
        char * envp[] = {"env1=key1", "env2=key2", NULL };
        execve("./interpreter.sh", argv, envp);
        printf("child Error");
    }
    else{
        wait(NULL);
        char * envp[] = {"./interpreter.sh","env1=key1", "env2=key2", NULL };
        char * argv[] = {"./interpreter.sh", "parent argument 1", "parent argument 2", NULL };
        execve("./interpreter.sh", argv, envp);
        printf("parent Error");
    }
}