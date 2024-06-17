#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
int main(){
    int pid = fork();

    if(pid == 0){
        //child section
        printf("deamon creating...\n");
        umask(0);
        //change directory
        chdir("/");
        setsid();
        printf("deamon created\n");
    }
    else if(pid > 0){
        printf("PID of child : %d\n", pid);
        exit(0);
    }
}