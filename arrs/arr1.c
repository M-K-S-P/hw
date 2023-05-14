#include<stdio.h>
#include<stdlib.h>
//#include <bits/stdc++.h>
#include<limits.h>
#define BUFFER_SIZE 1024

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

struct stack{

    int cap;
    int top;
    int items[];

}; typedef struct stack *stack;

stack* new_stack(int capacity){

    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
    pt->cap = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * cap);
    return pt;

}

int sized_stack(stack pt){

    return pt->cap + 1;

}

void push(stack pt, int x){

    pt->items[++pt->cap] = x;

}

int pop(stack pt){

    return pt->items[pt->cap--];

}

int binary_search(int arr[], int el, int s){
    int lef = 0;
    //int r = sizeof(arr) / sizeof(arr[0]) % 2 ? ((sizeof(arr) / sizeof(arr[0]) + 1) / 2) : (sizeof(arr) / sizeof(arr[0]) / 2);
    int rig = s - 1;
    int k = el;
    while(rig >= lef){

        int mid = (rig + lef) / 2;
        if(arr[mid] == k){

            return mid;

        } else if(arr[mid] > k){

            rig = mid - 1;

        } else{

            lef = mid + 1;

        }

    }
    return -1;

}

int rev_binary_search(int arr[], int el, int s){
    int size = s;
    int k = el;
    int lef = 0;
    //int r = sizeof(arr) / sizeof(arr[0]) % 2 ? ((sizeof(arr) / sizeof(arr[0]) + 1) / 2) : (sizeof(arr) / sizeof(arr[0]) / 2);
    int rig = size - 1;
    while(rig >= lef){

        int mid = (rig + lef) / 2;
        if(arr[mid] == k){

            return mid;

        } else if(arr[mid] > k){

            rig = mid - 1;

        } else{

            lef = mid + 1;

        }

    }
    return -1;

}

int revd_rev_binsearch(int arr[], int el, int s){
    int size = s;
    int k = el;
    int lef = 0;
    int rig = size - 1;
    while(rig >= lef){

        int mid = (rig + lef) / 2;
        if(arr[mid] == k){

            return mid;

        } else if(arr[mid] < k){

            rig = mid - 1;

        } else{

            lef = mid + 1;

        }

    }
    return -1;

}

int not_accurate_bin_s(int arr[], int el, int s){
    int size = s;
    int k = el;
    if(k > arr[0]){

        return 0;

    } else if(k < arr[size - 1]){

        return size;

    } else{

        int lef = 0;
        int rig = size - 1;
        while(rig >= lef){

            if(rig == lef + 1){

                return lef + 1;

            }
            int mid = (rig + lef) / 2;
            if(arr[mid] == k){

                return revd_rev_binsearch(arr, k, size);

            } else if(arr[mid] < k){

                lef = mid + 1;

            } else{

                rig = mid - 1;

            }

        }
        return -1;
    
    }

}

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

int main(){

    int task_num;
    scanf("%d", &task_num);
    if(task_num == 1){

        //int arsize;
        //scanf("%d", &arsize);
        //int *arr = (int*)malloc(size*sizeof(int));
        int arr[6] = {1, 2, 3, 4, 5, 6};
        for(int i = 1; i < sizeof(arr) / sizeof(arr[0]); i += 2){

            printf("%d\n", arr[i]);

        }
        return 0;

    } else if(task_num == 2){

        int arr[6] = {1, 2, 3, 4, 5, 6};
        for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i += 1){

            if (arr[i] % 2 == 0) {printf("%d\n", arr[i]);}

        }

    }
     else if(task_num == 3){

        int size;        
        int *arr = read_arr(&size);
            int pos = 0;
            for(int i = 0; i < size; ++i){

                if(arr[i]  > 0){pos += 1;}

            }

            printf("%d\n", pos);
            return 0;

    } else if(task_num == 4){

        printf("letter a is condition, when array ends\n");
        char cond = 'q';
        int max = INT_MIN;
        while(cond != 'a'){

            scanf("%c", &cond);
            if(cond != 'a'){ 
                
                if((int)cond > max){

                    max = (int)cond;

                }

            }

        }        

    } else if(task_num == 5){

        int size;        
        int *arr = read_arr(&size);
        for(int i = 0; i < size / 2; i++){

            arr[i] += arr[size - i - 1];
            arr[size - i] = arr[i] - arr[size - i - 1];
            arr[i] -= arr[size - i - 1];

        }

    } else if(task_num == 6){

        int co = 0;
        int size;        
        int *arr = read_arr(&size);
        for(int i = 1; i < size; i++){

            if(arr[i] > arr[i - 1]){

                co++;

            }

        }
        printf("%d", co);
        return 0;

    } else if(task_num == 7){

        int size;        
        int *arr = read_arr(&size);
        for(int i = 0; i < size - 1; ++i){

            if(arr[i] * arr[i + 1] > 0){

                printf("YES");
                return 0;

            }

        }

        printf("NO");
        return 0;

    } else if(task_num == 8){

        int size;        
        int *arr = read_arr(&size);
        for(int i = 1; i < size - 1; ++i){

            if(arr[i] - arr[i - 1] > 0 && arr[i] - arr[i + 1] > 0){

                printf("YES");
                return 0;

            }
            printf("NO");
            return 0;

        }

    } else if(task_num == 9){

        int size;        
        int *arr = read_arr(&size);
        if(size % 2 == 0){
            for(int i = 0; i < size - 1; i += 1){

                arr[i] += arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                arr[i] = arr[i] - arr[i + 1];

            }
        } else{

            for(int i = 0; i < size - 2; i += 1){

                arr[i] += arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                arr[i] = arr[i] - arr[i + 1];

            }            

        }

        for(int i = 0; i < size; i++){

            printf("%d\n", arr[i]);

        }

    } else if(task_num == 10){

        int size;        
        int *arr = read_arr(&size);
        int co = 0;
        for(int i = 0; i < INT_MAX; i++){
            
            int l = binary_search(arr, l, size);
            int r = rev_binary_search(arr, r, size);
            size -= (l - r + 1);
            co++;
            if(co == size){

                return co;

            }

        }

    } else if(task_num == 11){

        int size;
        int *arr = read_arr(&size);
        struct node* ll = linked_list(arr, size); 
        struct node* last_ptr = go_to(ll, size - 1);
        struct node* pre_last_ptr = go_to(ll, size - 2);
        last_ptr->plink = ll->plink;
        pre_last_ptr->plink = NULL;
        /*
        
        might be go_to(ll, size - 1)->plink = ll->plink;
        and same for pre_last_ptr
        use in case of error here
        
        */

        
    } else if(task_num == 12){

        int size;
        int *arr = read_arr(&size);
        printf("Enter a digit, array will be shifted for\n");
        int shift;
        scanf("%d", &shift);
        if(shift % size == 0){

            printf("same\n");

        } else{

            shift = shift % size;

        }
        struct node* ll = linked_list(arr, size); 
        struct node* first_node = go_to(ll, 0);
        struct node* last_node = go_to(ll, size - 1);
        struct node* after_cut = go_to(ll, size - shift);
        struct node* before_cut = go_to(ll, size - (shift - 1));
        last_node->plink = first_node->plink;
        after_cut->plink = ll->plink;
        before_cut->plink = NULL;

    } else if(task_num == 13){

        int size;
        int *arr = read_arr(&size);
        int height;
        printf("Petya's height:\n");
        scanf("%d", &height);
        not_accurate_bin_s(arr, height, size);

    } else{ //fuck yeah

        char *t = NULL;
        char *st = (char*)realloc(t, BUFFER_SIZE*sizeof(char));
        scanf("%s", st);
        int co = 0;
        int num = 0;
        while(st[co] != " "){

            num = num * 10 + (int)st[co];
            co++;

        }
        int co1 = 0;
        stack fir = new_stack(num);
        stack sec = new_stack(num);
        for(int i = co + 1; i < num + 1; i += 2){

            push(fir, (int)st[i]);

        }
        int check = 0;
        int trio[3];
        while(check){

            while(!check){

                if(!!size(fir)){

                    trio[0] = pop(fir);
                    trio[1] = pop(fir);
                    trio[2] = pop(fir);

checker1:

                    if(trio[0] == trio[1] && trio[0] == trio[2]){

                        goto exit1;

                    } else{

                        push(sec, trio[0]);
                        trio[0] = trio[1];
                        trio[1] = trio[2];
                        trio[2] = pop(fir);
                        goto checker1;

                    }

                }else{

                    trio[0] = pop(sec);
                    trio[1] = pop(sec);
                    trio[2] = pop(sec);

checker2:

                    if(trio[0] == trio[1] && trio[0] == trio[2]){

                        goto exit1;

                    } else{

                        push(fir, trio[0]);
                        trio[0] = trio[1];
                        trio[1] = trio[2];
                        trio[2] = pop(fir);
                        goto checker2;

                    }

                }

                check = 1;

exit1:

            }

        }

    }

}