#include<stdio.h>

void myswap(int* a, int* b){

    int* c = b;
    b = a;
    a = c;
    printf("%d %d\n %p %p\n", *a, *b, a, b);

}

void third(int* a){

    printf("%ld %p\n", sizeof(a), a);

}

void fourth(int *a, int size){

    for(int* b = a; *b; b++){

        printf("%d\n", *b);

    }

}

int main(){

    int a;
    int b = 10;
    int* c = &a;
    int* d = &b;
    *c = 1234;
    printf("%d %d\n %p %p\n", a, b, c, d);
    int* q = c;
    c = d;
    d = q;
    myswap(&a, &b);
    printf("%d %d\n %p %p\n", *c, *d, c, d);
    int k[10] = {[0 ... 9] = 8};
    third(k);
    fourth(k, sizeof(k) / sizeof(k[0]));
    

}