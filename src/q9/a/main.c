#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

void printPermission(char * filename){
    struct stat mystat ;
    stat(filename, &mystat);
    printf("The permission are : %o\n\n", mystat.st_mode & 0777);
}
int main(){
    char * filename = "tempfile";
    umask(0022);

    //create a new file
    open(filename, O_WRONLY | O_CREAT, 0666);
    printPermission(filename);

    //update permissions
    chmod(filename, 0777);
    printf("new permissins\n");
    printPermission(filename);

    //unlink the file
    unlink(filename);
}