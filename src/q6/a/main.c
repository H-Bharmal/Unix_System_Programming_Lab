// Write a C program to remove empty files from the given directory.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

int main(){
    struct dirent *dir  ;
    DIR *d ;
    d = opendir(".");

    if(d != NULL){
        while(dir = readdir(d)){
            // fileopen
            int fd = open(dir->d_name, O_RDWR, 0777);
            int size = lseek(fd, 0, SEEK_END);
            if(size == 0){
                printf("File removed\n");
                unlink(dir->d_name);
            }
        }
    }  
}