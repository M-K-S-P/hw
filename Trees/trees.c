#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include"itp.h"
#include<ctype.h>
#include<limits.h>
#include<unistd.h>
#define SIZE 100
//#define REINTERPRET(new_type, var) (*((new_type*)&var)) does not works or I am not capable to make it work
struct node {

  long long da;
  int ch;
  struct node* plink;
  struct node* left;
  struct node* right;

} *top, *top1, *temp;//typedef struct node *node;

int count = 0;

struct node* nn(int dat){
  struct node* nod = (struct node*)malloc(sizeof(struct node));
  nod->da = dat;
  nod->ch = 0;
  nod->left = NULL;
  nod->right = NULL;
  nod->plink = NULL;
  return nod;
}

void push(struct node* x){
  if(top == NULL){
    top = x;
  } else{
    (x)->plink = top;
    top = x;
  }
}

struct node* pop(){
  struct node* p = top;
  top = top->plink;
  return p;
}
int back(){
  if(top != NULL){
    return top->da;
  } else{
    return -1;
  }
}

void printInorder(struct node* nod)
{
  if (nod == NULL)
      return;
  else{
  printInorder(nod->left);
  if(nod->ch){
    printf("%c ", nod->da);
  } else{
    printf("%lld ", nod->da);
  }
  printInorder(nod->right);
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

int logt(int a, int co){
    if(a < 10){
        return co + 1;
    } else{
        logt(a / 10, co++);
    }
}

struct node* items[SIZE];
int rear = -1, front = -1;

void enQueue(struct node* nod) {
  if (rear == SIZE - 1)
    return -1;
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = nod;
  }
}

struct node* deQueue() {
  if (front == -1)
    return -1;
  else {
    struct node* nod = items[front];
    front++;
    if (front > rear){
      front = rear = -1;
    }
    return nod;
  }
}

int display() {
  if (rear == -1)
    return 0;
  else {
    return 1;
  }
}

int sio(char* ch)
{
  return (!strcmp(ch, "+") || !strcmp(ch, "-") || !strcmp(ch, "*") || !strcmp(ch, "/") || !strcmp(ch, "^"));
}

void bfs(struct node* nod){

  enQueue(nod);
  while(display()){
    bfs(nod->right);
    if(nod->right->left != NULL){
      enQueue(nod->right->left);
    }
    if(nod->right->right != NULL){
      enQueue(nod->right->right);
    }
    printf("%d ", nod->da);
    fflush(stdout);
  }

}

int main(){

  FILE* f1 = fopen("tree1.txt", "r");
  int i, j, k;
  int pred = 0; 
  char exp[100];
  fgets(exp, 100, f1);
  struct pair* postf = inftopos(exp);
  int co = 0;
  for(int i = 0; i < strlen(exp); i++){
    if(isOperator(exp[i])){
      co++;
    }   
  }
  char** words = (char**)malloc(sizeof(*words) * (co * 2 + 1)); 
  int l = strlen(postf->post);
  //i need to 1. make char** postfix expression where every char* is either a number or an operator since postf now only is char* with no spaces
  //The hypothesis for this appeared out of non-usage of brackets
  for(i = 0, j = 0, k = 0; i < l; i++){
    if(isOperator(postf->post[i])){
      words[k] = (char*)calloc(sizeof(char), 1);
      memcpy(words[k], &postf->post[i], 1);
      pred = i + 1;
      k++;
    } else{
      int va = postf->val[j];
      if(va == stoi(postf->post, i + 1, pred)){
        words[k] = (char*)calloc(logt(va, 0), sizeof(char));
        sprintf(words[k],"%d",va);
        pred = i + 1;
        j++;        
        k++;
      }
      //lots of debugging done, be grateful for all the patience old you had through these two days
    }
  }
  pred = 0;
  struct node *x, *y, *z;
  x = (struct node*)calloc(sizeof(struct node), 1); //yeah ik it is not necessary
  y = (struct node*)calloc(sizeof(struct node), 1);
  for(i = 0, j = 0; i < l - 1; i++){
      if(sio(words[i])){
        z = nn(words[i][0]);
        x = pop();
        y = pop();    
        z->left = y;  
        z->right = x;
        z->ch = 1;
        push(z);
      } else{
        z = nn(stoi(words[i], strlen(words[i]), 0));
        z->ch = 0;
        push(z);
      } 
  }
  char buf[255] = "echo $((";
  char* clo = "))";
  char buf1[255] = {0};
  freopen("/dev/null", "a", stdout);
  setbuf(stdout, buf1);
  printInorder(z);
  printf("\n");
  freopen("/dev/tty", "a", stdout);
  strcat(buf, buf1);
  strcat(buf, clo);
  system(buf);
  return 0;
  
}