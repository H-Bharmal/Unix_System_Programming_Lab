// Write a C program that takes the file descriptor as an argument and prints the description of selected file flags for that descriptor.
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char * argv[]){
    int fd = atoi(argv[1]);

    int flags = fcntl(fd, F_GETFL);

    if(flags == -1){
        printf("Error getting the file flags\n");
        return -1;
    }
    printf("File descriptor: %d\n", fd);
    printf("File flags:\n");
    if(flags & O_ACCMODE & O_RDONLY) printf("File is open in read only mode\n");
    if(flags & O_ACCMODE & O_WRONLY) printf("File is open in write only mode\n");
    if(flags & O_ACCMODE & O_RDWR) printf("File is open in read write mode\n");

    if(flags & O_SYNC) printf("File is sync writes\n");
    if(flags & O_APPEND) printf("File is Append\n");
    if(flags & O_NONBLOCK)printf("File is Non Blocking\n");
    if(flags & O_TRUNC)printf("File is Truncate\n");
    if(flags & O_CREAT)printf("Create\n");
}