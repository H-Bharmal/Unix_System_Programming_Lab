// Write a C program to implement ls –li command which list the files in a specified directory. Your program should Print 5 attributes of files.
// Logic : 
/*
    First : we use struct dirent pointer to get current directory using opendir('.')

    Second : we traverse every file in the dirent and print the necessary
    // inode, mode, uid, gid, atime, dirname
 */

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>

int main(){
    struct stat filestat ;
    struct dirent *dir ;

    //open the directory stream
    DIR *dp = opendir(".");
    if(dp){
        while(dir = readdir(dp)){
            stat(dir->d_name,&filestat);
			printf("%ld %o %d %d %s %s\n",filestat.st_ino,filestat.st_mode,filestat.st_uid,filestat.st_gid,ctime(&filestat.st_atime),dir->d_name);
        }
    }

}