#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<time.h>
#include<utime.h>
#include<sys/stat.h>

int main(int argc, char * argv[]){
    char * file1 = argv[1];
    char * file2 = argv[2];

    struct stat file1stat ;
    struct stat file2stat ;

    if(stat(file1, &file1stat) < 0){
        printf("Error getting stats");
        return -1 ;
    }
    if(stat(file2, &file2stat) < 0){
        printf("Error getting stats");
        return -1 ;
    }
    printf("Access Time : %s\nModfication Time: %s\n", ctime(&file2stat.st_atime),ctime(&file2stat.st_mtime));

    struct utimbuf times ;

    times.actime = file1stat.st_atime ;
    times.modtime = file1stat.st_mtime ;

    // Copy the times using utime funciton
    if(utime(file2, &times) < 0){
        printf("Error setting time");
        return -1 ;
    }
    if(stat(file2, &file2stat) < 0){
        printf("Error getting stats");
        return -1 ;
    }
    printf("Access Time : %s\nModfication Time: %s\n", ctime(&file2stat.st_atime),ctime(&file2stat.st_mtime));


}