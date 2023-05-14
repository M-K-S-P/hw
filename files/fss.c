#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include"sorts.c"
/*
char* st = (char*)malloc(sizeof(char) * logt(d, 0));
sprintf(st, "%d", d);
*/
#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))

int logt(int a, int co){
    if(a < 10){
        return co + 1;
    } else{
        logt(a / 10, co++);
    }
}

int getsize(FILE *f){

    fseek(f, 0, SEEK_END);
    int si = ftell(f);
    fseek(f, 0, SEEK_SET);
    return si;

}

int main(){

    FILE *f5 = fopen("file5.txt", "w");
    FILE *f6 = fopen("file6.txt", "w");
    srand(time(NULL));
    int ra1 = rand() % 9991 + 10;
    int ra2 = rand() % 9991 + 10;
    int mx = MAX(ra1, ra2);
    int mn = MIN(ra1, ra2);
    int* f = (int*)malloc(sizeof(int) * mx);
    int* s = (int*)malloc(sizeof(int) * mn);
    for(int i = 0; i < mx; i++){

        if(i < mn){ s[i] = rand(); }
        f[i] = rand();

    }
    mergesort(f, 0, mx - 1);
    quicksort(s, 0, mn - 1);
    for(int i = 0; i < mx; i++){

        if(i < mn){ 

            char* st = (char*)malloc(sizeof(char) * logt(s[i], 0));
            sprintf(st, "%d", s[i]);
            fputs(st, f5);
            fputs(" ", f5);
            free(st);

        }
        
        char* st = (char*)malloc(sizeof(char) * logt(f[i], 0));
        sprintf(st, "%d", s[i]);
        fputs(st, f6);
        fputs(" ", f6);
        free(st);

    }
    //7 я делать не буду - мне в падлу
    

}