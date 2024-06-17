// Write a C program to simulate system function.
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
    //create a child process
    int pid = fork();
    if(pid < 0){
        printf("Error creating child\n");
    }
    else if(pid == 0){
        printf("Child Process, now executing the command using execl");

        char *pathtoexe = "/bin/ls";

        int success = execl(pathtoexe, "-l", (char *)NULL);

        printf("Failed to execute the command");
    }
    else{
        printf("Inside the parent section\n");
        int status ;
        if(waitpid(pid, &status, 0) == -1){
            printf("wait pid failed\n");
            return -1;
        }
        printf("Command executed with status : %d", status);
        return 0;
    }
}