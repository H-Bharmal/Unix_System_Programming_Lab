// Write a C program to display various details of a file using stat structure (Atleast 5 fields).

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[]){
    char * filename = argv[1];

    //open the file
    //int fd = open(filename, O_RDONLY);

    // declear a stat struct 
    struct stat filestats ;

    //populate the structure
    int val = stat(filename, &filestats);
    if(val == -1){
        printf("Error reading file stat\n");
        return -1;
    }

    printf("The file information is :\n\n");

    printf("The filesize :  %ld\n", filestats.st_size);
    printf("The userID : %d\n", filestats.st_uid);
    printf("The groupID : %d\n", filestats.st_gid);
    printf("The block_size : %ld\n", filestats.st_blocks);
    printf("The lastAccessTime : %ld\n", filestats.st_atime);
    printf("The File Permissions : %o\n", filestats.st_mode);
}