#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>

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

    FILE *f = fopen("file1.txt", "r");
    srand(time(NULL));
    int si = getsize(f);
    char* da = (char*)malloc(sizeof(char) * si);
    fgets(da, si, f);
    printf("%s", da);
    /*for(char* c = da; *c; c++){
        printf("%s", c);
    } */
    printf("\n");
    fclose(f);
    free(da);
    int ra = rand() % 9990 + 10;
    //int* nums = (int*)malloc(sizeof(int) * ra);
    int d;
    FILE *f2 = fopen("file2.txt", "w");
    for(int i = 0; i < ra; i++){ 

        d = rand() % 2001 - 1000;
        char* st = (char*)malloc(sizeof(char) * logt(d, 0));
        sprintf(st, "%d", d);
        fputs(st, f2);
        fputs(" ", f2); 
        free(st);

    }
    fclose(f2);
    FILE *f3 = fopen("file2.txt", "r");
    int si1 = getsize(f3);
    char* buf = (char*)malloc(si1 * sizeof(char));
    fgets(buf, si1, f3);
    int co = 1;
    while(!feof(f3)){
        if(getc(f3) == ' '){ 
            co++;
        }
    }
    //int* ns = (int*)malloc(co * sizeof(int));
    //int co2 = 0;
    int mi = INT_MAX;
    int ma = INT_MIN;
    long long sum = 0;
    fseek(f3, 0, SEEK_SET);
    char *ccc = buf;
    char *pred = ccc;
    while(*ccc != '\0'){
        ccc++;
        //printf("%p %p\n", f3, orr);
        if(*ccc == ' '){ 
            char* nu = (char*)malloc(sizeof(char) * (int)(ccc - pred));
            memcpy(nu, pred, (ccc - pred));
            pred = ccc;
            int intt = (int)strtol(nu, (char **)NULL, 10);
            //printf("%s\n", nu);
            sum += intt;
            if(!(intt % 2) && intt > 0){
                ma = MAX(intt, ma);
                mi = MIN(mi, intt);
            }
            free(nu);
            //ns[co2] = (int)strtol(nu, (char **)NULL, 10);
            //co2++;
        }
    }
    printf(" %f - avg\n %d - min\n %d - max\n", (double)(sum / co), mi, ma);
    FILE *f4 = fopen("file4.txt", "w");
    char* st1 = (char*)malloc(sizeof(char) * logt(mi, 0));
    char* st2 = (char*)malloc(sizeof(char) * logt(ma, 0));
    sprintf(st1, "%d", mi);
    sprintf(st2, "%d", ma);
    fputs(st1, f4);
    fputs(" ", f4);
    fputs(st2, f4);
    fputs("\n", f4);
    fclose(f3);
    fclose(f4);
    free(st1);
    free(st2);
    free(buf);

}