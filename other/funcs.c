#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h> 

bool xor1(bool a, bool b) {return a ^ b;}
bool election(bool a, bool b, bool c) {return (a & b) | (a & c) | (b & c);} 

int min(int a, int b){

    if (a >= b){ return a; }
    else { return b; }

}
int min(int a, int b, int c, int d){

    return min(a, min(b, min(c, d)));

}

int fast_pow(double a, int b) {

  if (b == 1)
    return a;
  if (b % 2 == 1)
    return a * fast_pow(a, b - 1);
  int tmp_exp = fast_pow(a, b / 2);
  return tmp_exp * tmp_exp;
}

bool is_Prime(int n, int ch){

  if(n == 1){ return true;}
  if(n % ch && ch != 1){

    return is_Prime(n, ch - 1);
    /*if(!is_Prime(n, ch - 1)){ return false; }
    else{ return is_Prime(n, ch - 1); } */
  }
  if(ch == 1){

    return true;

  } else{

    return false;

  }

}

int main(){

  int num = 110;
  if(is_Prime(num, num - 1)){

    printf("Prime\n");

  } else{

    printf("composite\n");

  }

}
