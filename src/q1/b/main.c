// Write a C program to create a child process and show how parent and child  processes will share the text file and justify that both parent and child shares the same file offset

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char * argv []){
    // Logic : Let the parent read the file
    // then without changing anything, let the child also read the same file
    // since they are sharing, offset wont be changed and hence next bytes will be read

    //open a file
    char * filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if(fd == -1 ){
        printf("Error oprining file\n");
        return -1;
    }

    // create a child
    int pid = fork();

    if(pid < 0){
        printf("Error craeting a child\n");
        return -1 ;
    }
    else if(pid == 0){
        printf("Entering the child section\n");
        //read the file
        char buf[6] ;
        buf[5] = '\0';
        ssize_t bytesRead = read(fd, buf, 5);
        if(bytesRead == -1){
            printf("error reading in child\n");
            return -1;
        }
        else{
            printf("Read %ld bytes in child\n", bytesRead);
        }

        printf("Reading as per child : %s\n", buf);
        printf("Exiting child section..\n");
    }
    else{
        wait(NULL);
        printf("Entering parent process, Reading 10bytes\n");
        char  buf[11] ;
        read(fd, buf, 10);
        buf[10] = '\0';
        printf("Reading as per Parent : %s\n",buf);
        printf("Exiting the parent section\n");
    }
    close(fd);
    printf("Done.");
}