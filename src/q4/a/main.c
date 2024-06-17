#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>

void printFileStats(char *link, char *whichLink){
    printf("\n\nFile stats for link %s\n", whichLink);
    struct stat fileStat ;
    stat(link, &fileStat);
    printf("Inode: %ld\n", (long)fileStat.st_ino);
    printf("Hard link count: %ld\n", (long)fileStat.st_nlink);
    printf("Size: %ld bytes\n", (long)fileStat.st_size);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last access: %s", ctime(&fileStat.st_atime));
    printf("Last modification: %s", ctime(&fileStat.st_mtime));
    printf("Last status change: %s\n", ctime(&fileStat.st_ctime));
}
int main(int argc, char * argv[]){
    if(argc == 3){
        char * originalFile = argv[1];
        char * hardlink = argv[2];
        //create a hardlink
        //link function is used for the puropse
        if(link(originalFile, hardlink) != 0){
            printf("Error craeting hardlink");
        }
        else{
            printf("hardlink created");
        }
        printFileStats(originalFile, "OriginalLink");
        printFileStats(hardlink, "Hardlink");

    }
    else if(argc == 4){
        char * originalFile = argv[1];
        char * softlink = argv[3];
        //create a hardlink
        //link function is used for the puropse
        if(symlink(originalFile, softlink) != 0){
            printf("Error craeting softlink");
        }
        else{
            printf("softlink created");
        }
        printFileStats(originalFile, "OriginalLink");
        printFileStats(softlink, "Softlink");
    }
    return 0;
}