#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    //create a child process
    int pid = fork();
    if(pid < 0){
        printf("Error creating child\n");
        return -1;
    }
    else if(pid == 0){
        //child section
        printf("Child section, PID:%d", getpid());
        //check if a file can be accessed
        char * filepath = "/etc/passwd";

        if(access(filepath, R_OK) == 0){
            printf("File is readable\n");
        }
        else{
            printf("File is not readable\n");
        }
        exit(0);
    }
    else{
        printf("Parent section, PID:%d", getpid());
        int status ;
        waitpid(pid, &status, 0);
        printf("Child compleeted with status : %d", status);
    }
    return 0 ;
}