#ifndef ITP_H
#define ITP_H

#include<ctype.h>

struct pair{

    char* post;
    int* val;

};
int isOperator(char ch);
struct pair* inftopos(char* inff);
int stoi(char* exp, int i, int pred);
int solv(char* exp1);

#endif