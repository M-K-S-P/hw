
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct pair{

    char* post;
    int* val;

};

static struct node {

    int da;
    struct node* plink;

} *top, *top1, *temp;//typedef struct node *node;

static int count = 0;

static void push(int dat){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->plink = top;
  temp->da = dat;
  top = temp;
  count++;
}

static int pop(){
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
static int back(){
  if(top != NULL){
    return top->da;
  } else{
    return -1;
  }
}

static int size(){
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

static int find(char* li, char el, int size){
  for(int i = 0; i < size; i++){
    if(el == li[i]){
      return i;
    }
  }
  return -1;
}

static void clear(){
  top1 = top;
  while(top1->plink){
    temp = top1;
    top1 = top1->plink;
    free(temp);
  }
}

int stoi(char* exp, int i, int pred){
  char* el = (char*)malloc(sizeof(char) * (i - pred));
  memcpy(el, &exp[pred], (i - pred));
  int intt = (int)strtol(el, (char **)NULL, 10);
  free(el);
  return intt;
}

static int precedence(char operator)
{
  switch (operator) {
  case '+':
  case '-':
      return 1;
  case '*':
  case '/':
      return 2;
  case '^':
      return 3;
  default:
      return -1;
  }
}
  
int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

struct pair* inftopos(char* inff){
  int i, j, k;
  int len = strlen(inff);
  char* postf = (char*)malloc(sizeof(char) * (2 + len));
  int* vals = (int*)malloc(sizeof(int) * len);
  int topo = -1;
  int pred = 0;
  for(i = 0, j = 0, k = 0; i < len; i++){

      if(inff[i] == ' ' || inff[i] == '\t'){
          continue;
      }
      if(isalnum(inff[i])){
          postf[j++] = inff[i];
      } else if(isOperator(inff[i])){
          //printf("%d %d\n", pred, i);
          vals[k++] = stoi(inff, i, pred);
          pred = i + 1;
          int ch = 1;
          while(ch){
              if(topo > -1){
                  char op = pop();
                  if(precedence(op) >= precedence(inff[i])){
                      postf[j++] = op;
                      topo--;
                  } else{ ch = 0; }
              } else{ ch = 0; }
          }
          push(inff[i]);
          ++topo;

      } 
  }
  while(topo > -1){
      char op = pop();
      if(op != -1){
          postf[j++] = op;
      } else{
          postf[j++] = '-';
      }
      topo--;
  }
  vals[k] = stoi(inff, len, pred);
  struct pair* re = (struct pair*)malloc(sizeof(int*) + sizeof(char*));
  re->val = vals;
  re->post = postf;
  return re;  
}

int solv(char* exp1){
  int pred = 0;
  int prev1 = 0;
  int prev2 = 0;
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
        push(intt);
      } else{
        prev1 = pop();
        prev2 = pop();
          if(el[1] == '+'){
            push(prev1 + prev2);} 
          else if(el[1] == '-'){
            push(prev2 - prev1);}
          else if(el[1] == '/'){
            push(prev2 / prev1);}
          else if(el[1] == '*'){
            push(prev1 * prev2);}
        }        
      }
    }    

  int ouq = pop();
  return ouq;

}