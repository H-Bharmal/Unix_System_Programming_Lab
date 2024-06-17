// a) Write a C program to display the file content in reverse order using lseek system call.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char * argv[]){
    //Get the filename
    char * filename = argv[1];

    // open the file
    int fd = open(filename, O_RDONLY);

    if(fd == -1){
        printf("Error openingi file");
        return -1;
    }

    // set the offset
    int filesize = lseek(fd, 0, SEEK_END);

    if(filesize == -1){
        printf("Error setting the offset");
        return -1 ;
    }
    else{
        printf("The file Size is : %d\n", filesize);
    }

    //read the file in reverse
    for(int i=filesize-1; i>=0 ; i--){
         //set the offset to end - i;
        int temp = lseek(fd, i, SEEK_SET);
        if(temp == -1) return -1;        

        //read the byte
        //read (filediscriptor, buffer, bytes to read) returns bytes read
        char buf ;
        int bytesRead = read(fd, &buf, 1);
        printf("%c", buf);

    }

    //close the file
    close(fd);
    printf("\nReading Done. Bye\n");

}