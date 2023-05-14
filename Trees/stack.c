#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include <bits/stdc++.h>
#include<limits.h>
#define BUFFER_SIZE 1024

struct node {

    int da;
    struct node* plink;

} *top, *top1, *temp;//typedef struct node *node;

int count = 0;

void push(int dat){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->plink = top;
  temp->da = dat;
  top = temp;
  count++;
}

int pop(){
  top1 = top;
  if(top1 == NULL){
    return -1;
  } else{
    top1 = top1->plink;
    int pp = top->da;
    top = top1;
    count--;
    return pp;
  }
}
int back(){
  if(top != NULL){
    return top->da;
  } else{
    return -1;
  }
}

int size(){
  top1 = top;
  if(top1 == NULL){
    return -1;
  } else{
    while(top1->plink != NULL){
      top1 = top1->plink;
    }
    return 0;
  }
}

int find(char* li, char el, int size){
  for(int i = 0; i < size; i++){
    if(el == li[i]){
      return i;
    }
  }
  return -1;
}

void clear(){
  top1 = top;
  while(top1->plink){
    temp = top1;
    top1 = top1->plink;
    free(temp);
  }
}

int main(int argc, char* argv){

  FILE *f = fopen("2.txt", "r");
  for(int i = 0; i < 13; i++){
    char st[100];
    int integ = atoi(fgets(st, 10, f));
    printf("%d\n", integ);
    push(integ);
  }
  printf("push ended\n");
  //printf("%d %d\n", size(), back());
  for(int i = 0; i < 13; i++){

    int ou = pop();
    printf("%d\n", ou);

  }
  char op[] = "[{(<";
  char cl[] = "]})>";
  FILE* f2 = fopen("3.txt", "r");
  char sk[100];
  fgets(sk, 100, f2);
  int size = strlen(sk);
  char prev = '0';
  for(int i = 0; i < size; i++){

    if(sk[i] != '\0'){

      if(op[find(cl, sk[i], size)] == prev){
        char thr = pop();
        prev = pop();
        push(prev);
      }else{
        push(sk[i]);
        prev = sk[i];
      }

    }

  }
  int ch = pop();
  if(ch == -1){
    printf("yes\n");
  } else{
    printf("no\n");
  }
  //clear();
  FILE* f4 = fopen("4.txt", "r");
  char exp1[100];
  int pred = 0;
  int prev1 = 0;
  int prev2 = 0;
  fgets(exp1, 100, f4);
  char exp[200];
  char exp2[200] = " ";
  strcat(exp2, exp1);
  strcpy(exp, exp2);
  char sig[] = "+-/*";
  for(int i = 0; i < strlen(exp); i++){
    
    if(exp[i] == ' '){

      char* el = (char*)malloc(sizeof(char) * (i - pred));
      memcpy(el, &exp[pred], (i - pred));
      pred = i;
      if(find(sig, el[1], sizeof(sig) / sizeof(sig[0])) == -1){
        int intt = (int)strtol(el, (char **)NULL, 10);
        //printf("%d\n", intt);
        push(intt);
      } else{

        prev1 = pop();
        prev2 = pop();
        //printf("%d %d\n", prev1, prev2);
          if(el[1] == '+'){
            //printf("%d+\n", prev1 + prev2);
            push(prev1 + prev2);} 
          else if(el[1] == '-'){
            //printf("%d-\n", prev2 - prev1);
            push(prev2 - prev1);}
          else if(el[1] == '/'){
            //printf("%d/\n", prev2 / prev1);
            push(prev2 / prev1);}
          else if(el[1] == '*'){
            //printf("%d*\n", prev1 * prev2);
            push(prev1 * prev2);}
        }        
      }
    }    

  int ouq = pop();
  printf("%d\n", ouq);
  return 0;
}
