#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void customHandler(int val){
    printf("Custom Handler invoked\nReseting to default action\n");
    struct sigaction newsig ;
    newsig.sa_flags = 0;
    sigemptyset(&newsig.sa_mask);
    newsig.sa_handler = SIG_DFL ;

    sigaction(SIGINT,&newsig,NULL);
    printf("Resetted to default\n");
}
int main(){
    struct sigaction mysig ;
    //initialize the mask with 0, similar to mmset(0)
    sigemptyset(&mysig.sa_mask);

    // sa flags to zero
    mysig.sa_flags = 0;

    //set the handler
    mysig.sa_handler = customHandler ;

    //// Set the signal action for SIGINT
    sigaction(SIGINT, &mysig, NULL);

    printf("Custom Handler set");
    while(1){
        printf("Process Waiting for interrupt\n");
        sleep(1);
    }

    return 0 ;
}