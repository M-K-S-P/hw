#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define BUFFER_SIZE 1024


int* read_arr(int *si){

    char *t = NULL;
    int *arr = (int*)realloc(t, BUFFER_SIZE*sizeof(int));
    printf("letter a is condition, when array ends\n");
    char cond = 'q';
    int co = 0;
    while(cond != 'a'){

        scanf("%c", &cond);
        if(cond != 'a'){ 
        
            arr[co] = (int)cond;
            co += 1;

        }

    }
    *si = co;
    return arr;

}

struct node {

    int da;
    struct node* plink;

}; typedef struct node *node;

node linked_list(int* narr, int n){

    static int i = 0;
    struct node* t = NULL;
    if(n != 0){
        
        t = (struct node*)malloc(sizeof(struct node*));
        t->da = narr[i++];
        t->plink = linked_list(narr, --n);
        
    }

    return t;

}

node go_to(struct node *ll, int number){

    while(number){

        ll = ll->plink;
        number--;

    }
    
    return ll;

}



int main(){

    int size = 10;
    /*int *arr = read_arr(&size);
    for(int i = 0; i < size; i++){

        printf("%d\n", arr[i]);

    }*/
    int arr[size];
    for(int i =0; i < size; i++){

        scanf("%d", &arr[i]);

    }
    printf("Enter a digit, array will be shifted for\n");
    int shift;
    scanf("%d", &shift);
    if(shift % size == 0){

        printf("same\n");

    } else if(shift > 0){

        shift = shift % size;

    } else{

        shift += 10;

    }
    struct node* ll = linked_list(arr, size); 
    struct node* first_node = go_to(ll, 0);
    struct node* last_node = go_to(ll, size - 1);
    struct node* before_cut = go_to(ll, size - shift - 1);
    struct node* after_cut = go_to(ll, size - (shift - 1) - 1);
    //node old = after_cut->plink;
    ll = after_cut;
    //printf("1\n");
    last_node->plink = first_node;
    //printf("2\n");
    before_cut->plink = NULL;
    //printf("3\n");
    for(int i = 0; i < size; i++){

        printf("%d ", go_to(ll, i)->da);
        printf("%d\n", i);

    }

}