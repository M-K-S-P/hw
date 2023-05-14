#include<stdio.h>
#include<stdlib.h>

unsigned int int_to_int(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_int(k / 2)));
}

int logt(unsigned int a, int co){
    if(a < 10){
        return co + 1;
    } else{
        logt(a / 10, co++);
    }
}

void uitc(char *st, unsigned int q){

    unsigned int qw = int_to_int(q);    
    sprintf(st, "%u", qw);

}