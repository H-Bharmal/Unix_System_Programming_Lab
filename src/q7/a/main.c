// Write a C program to illustrate the effect of setjmp and longjmp functions on register and volatile variables.

#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

static jmp_buf jmpbuffer ;
void f1(int a, int b, int c);

int main(){

    //create register and volatile variables
    register int regival = 1;
    volatile int volival = 2;
    int normalval = 3 ;

    //set a jump
    if(setjmp(jmpbuffer) != 0){
        //long jump is called
        printf("Values after long jump \n");
        printf("RegisterValue:%d\nVolatileValue:%d\nNormalValue:%d\n", regival, volival, normalval);
        exit(0);
    }

    volival= 20;
    regival = 10 ;
    normalval = 30 ;
    f1(regival,volival, normalval);
    exit(0);
}
void f1(int a, int b, int c){
    printf("in f1():\n");
    printf("regival = %d, volaval = %d, normalval = %d\n",a,b,c);
    longjmp(jmpbuffer, 53);
}