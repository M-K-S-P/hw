#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

unsigned int conversion(unsigned int qw){

    char* st = (char*)malloc(sizeof(char) * logt(int_to_int(qw), 0));
    uitc(st, qw);
    printf("%s\n", st);
    int co = 0; 
    for(int i = 0; i < logt(qw, 0); i++){

        if(st[i] == 1){ co++; }

    }
    char* news = (char*)malloc(sizeof(char) * (logt(qw, 0) + 1));
    memcpy(news, st, logt(qw, 0));
    //printf("%s\n", news);
    if(co % 2){

        news[logt(qw, 0)] = '1';
        news[0] = '1';
        news[1] = '1';

    } else{

        news[logt(qw, 0)] = '0';
        news[1] = '0';

    }
    //printf("%s\n", news);
    unsigned int conv = (unsigned int)strtoul(news, (char**)NULL, 2);
    printf("%u\n", conv);
    free(news);
    free(st);
    return conv;

}

int main(){

    unsigned int co1;
    for(co1 = 0; co1 < 20; co1++){

        //printf("%u", co1);
        if(conversion(co1) <= 40){ co1++; }
        else{ break; }

    }
    printf("%u\n", co1);

    int arr[2000] = {0};
    for(int i = 10; i < 1001; i++){

        char* st = (char*)malloc(sizeof(char) * logt(int_to_int(i), 0));
        uitc(st, i);
        int co = 1;
        while(st[co] != '1'){ co++; }
        char* news = (char*)malloc(sizeof(char) * (logt(int_to_int(i), 0) - co));
        memcpy(news, st + co, logt(int_to_int(i), 0) - co);
        unsigned int conv = (unsigned int)strtoul(news, (char**)NULL, 2);
        arr[conv]++;

    }
    int coo1 = 0;
    for(int i = 0; i < 2000; i++){

        //printf("%d\n", i);
        if(arr[i] != 0){ coo1++; }

    }
    printf("%d\n", coo1);

}