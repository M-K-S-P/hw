#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"sorts.c"
#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))


int getsize(FILE *f){
    fseek(f, 0, SEEK_END);
    int si = ftell(f);
    fseek(f, 0, SEEK_SET);
    return si;
}
/*The magic happens in the sscanf() call,
it takes a pointer to a char* string as the first parameter. 
The second parameter says you should read one integer into c
and the amount of bytes read into br. 
You use br to increment the pointer input1. 
That way you change the position where you read the next integer. */
int main(){

    FILE* f = fopen("1.txt", "r");
    int si;
    int ln = 0;
    int c = 0; 
    int br = 0;
    fscanf(f, "%d", &si);
    int* ar = (int*)malloc(sizeof(int) * si);
    int sit = getsize(f);
    char* da = (char*)malloc(sizeof(char) * sit);
    char* dan = (char*)malloc(sizeof(char) * sit);
    fgets(dan, sit, f);
    fgets(da, sit, f);
    //printf("%s", da);
    while(sscanf(da, "%d%n", &c, &br) > 0){
        ar[ln++] = c;
        da += br;
    }
    mergesort(ar, 0, si - 1);
    printArray(ar, si);
    free(ar);
    printf("-----------------------------------------------------------------------------------------\n");
    char inp[1000];
    fgets(inp, sizeof(inp), stdin);
    char* ch = inp;
    int co = 0;
    int sist = 0;
    while(*ch != '0'){
        if(*ch == ' '){
            co++;
        }
        sist++;
        ch++;
    }
    printf("%d %d\n", co, sist);
    br = 0;
    ln = 0;
    int* ar1 = malloc(co * sizeof(int));
    char* inp1 = inp;
    while(sscanf(inp1, "%d%n", &c, &br) > 0){
        ar1[ln++] = c;
        inp1 += br;
    }
    quicksort(ar1, 0, co - 1);
    printArray(ar1, co);

}