#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))

int log_not_precised(int num, int bas){

    int co = 0;
    int ch = 1;
    while(ch < num){
        ch *= bas;
        co++;
    }
    return co;

}

//just be sure to set n2 and n1 to 1
int fib(int n, int n1, int n2){

    if(n != 1){
        int sum = n1 + n2;
        n2 = n1;
        n1 = sum;
        fib(n--, n1, n2);
    } else{

        return n1 + n2;

    }

}
//int* S = (int*)malloc(log_not_precised(number, 3, 0) * sizeof(int));
void turning(int n, char* S){
    

    if(n > 2){

        *S = (char)(n % 3); 
        //printf("%d\n", n % 3);         //prolly doesnt work
        turning(n / 3, S + sizeof(char)); //might be S + sizeof(int)

    } else{
        //printf("%d\n", n % 3);   
        *S = (char)(n % 3);

    }

}

int func(int n){

    if(n < 3){

        return n;
    
    } else if(n % 2){

        return 2 * (n + 1) + func(n - 2) - 5;

    } else{

        return 2 * (n - 1) + func(n - 1) + 2;

    }

}

int decrementor(int n, int* pr, int edg){
    //printf("%d", n);
    if(n > edg){ return 0; }
    if(n == edg){ return 1; }
    //int* pr = (int*)malloc((n + 1) * sizeof(int));
    return decrementor(n + 1, pr, edg) + decrementor(n * 2, pr, edg) + decrementor(n * 2 + 1, pr, edg);
    //return *(pr + 50);
    
}

int main(){

    
    int n = 1;
    int edg1 = 20;
    int edg2 = 50;
    int* pr1 = (int*)calloc((edg1 + 1), sizeof(int));
    int* pr2 = (int*)calloc((edg2 + 1), sizeof(int));
    //int pr[51] = {0};
    int a = decrementor(n, pr1, edg1);
    int b = decrementor(edg1, pr2, edg2);
    printf("%d", a * b);   
    free(pr1);
    free(pr2);
    /*char* S = (char*)malloc(log_not_precised(number, 3) * sizeof(char));
    //printf("%d", log_not_precised(number, 3));
    turning(number, S);
    for(int i = 0; i < log_not_precised(number, 3); i++){

        printf("%d", S[i]);

    }*/

}

