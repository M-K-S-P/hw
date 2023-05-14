#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define BUFFER_SIZE 1024
#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))

int guess(int try, int div, long long res){

    if (fast_pow(try / 2, div, res) > res){



    }

}

int fast_pow(long a, long b){
    
    if (b==1) return a;
    if(b%2==1) return a * fast_pow(a, b-1);
    int tmp_exp = fast_pow(a, b/2);
    return tmp_exp * tmp_exp;

}

int gcd(int a, int b){

    c = (int)MAX(a, b);
    d = (int)MIN(a, b);
    c -= c/d * d;
    if(c != 1 & d != 1){
        
        gcd(c, d);

    } else if(c == d){

        return c;

    } else{

        return 1;

    }

}

int main(){
    //double a = 2134512.123541235;
    //char *t = NULL;
    //char *arr = (char*)realloc(t, BUFFER_SIZE*sizeof(char));
    char st[100];
    char pow[] = 12341234.123412342134;
    sprintf(st, "%.50f", pow);
    int len = sizeof(st)/sizeof(st[0]);
    char zero = '0';
    co = len - 1;
    while(zero == '0'){

        zero = st[co];
        co--;

    }
    char new[co + 1];
    char divisor[len - co - 1];
    for(char * c = st; *c; c++){

        if(c != '.'){
        
            new[c - st] = st[c];
        
        }

    }
    divisor[0] = '1';
    for(int i = 1; i < len - co - 1; i++){

        divisor[i] = '0';

    }
    printf("%d\n%d", (int)new, (int)st);
    int gcd_div_new = gcd((int)divisor, (int)new);
    int div = (int)divisor / gcd_div_new;
    int new = (int)new / gcd_div_new;
    int base = 3;
    long long first = fast_pow(base, new);
    int try = 10;
    int initial_g = guess(try, pow, first);


}