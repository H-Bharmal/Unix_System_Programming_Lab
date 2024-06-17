#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[]){
    char * source = argv[1];
    char * destination = argv[2];

    int f1 = open(source, O_RDONLY);

    int f2 = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0666) ;

    int datasize = lseek(f1, 0, SEEK_END);
    lseek(f1, 0, SEEK_SET);

    char *readBuffer ;
    read(f1, readBuffer, datasize);

    write(f2, readBuffer, datasize);
    printf("File copied successfully !");
    return 0;
}