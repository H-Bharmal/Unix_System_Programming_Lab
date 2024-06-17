// Consider the last 100 bytes as a region. Write a C program to check whether the region is locked or not. If the region is locked, print pid of the process which has locked. If the region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char * argv[]){
    char * filename = argv[1];
    //open a file
    int fd = open(filename, O_RDWR);
    //first go 100bytes back
    if(lseek(fd, -100, SEEK_END) != -1){
        struct flock fc ;
        fc.l_whence = SEEK_CUR ;
        fc.l_start=0;
        fc.l_len=100;


        //check if lock is already there
        if(fcntl(fd, F_GETLK, &fc) == 0){
            printf("File already locked \n");
            printf("File locked by : %d Process\n", fc.l_pid);
        }
        else{
            //lock the file
            // lseek(fd, -100, SEEK_END);
            // fc.l_whence = SEEK_CUR ;

            fc.l_whence = SEEK_END ;
            fc.l_start=0;
            fc.l_len=100;
            fc.l_type = F_WRLCK ;
            if(fcntl(fd, F_SETLK, &fc) != -1){
                printf("File locked\n");
                lseek(fd, -50, SEEK_END);
                char buf[50];
                read(fd, buf, 50);

                //Now read the last 50 bytes
                printf("The bytes read are :\n%s\n", buf);

                //unlock the lock
                fc.l_type = F_UNLCK ;
                // fc.l_whence = SEEK_CUR ;
                fc.l_whence = SEEK_END;
                fc.l_start=0;
                fc.l_len = 100 ;
                fcntl(fd, F_SETLKW, &fc);
                printf("File unlocked again !");
            }

        }
    }
}
