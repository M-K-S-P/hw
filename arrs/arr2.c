#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"mtwist.h"

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
    printf("task number from 1 to 4");
    scanf("%d", &task_num);
    if(task_num == 1){

        mt_seed();
        int arr[100];
        for(int i = 0; i < 100; i++){

            int a = mt_ldrand % 21 - 10;
            arr[i] = a;
            printf("%d\n", a);

        }

    } else if(task_num == 2){

        int size;
        int *arr = read_arr(&size);
        int find;
        printf("what number would you like to find?\n");
        scanf("%d", &find);
        for(int i = 0; i < size; i++){

            if (arr[i] == find){

                printf("%d", i);
                return 0;

            }

        }
        printf("no");

    } else if(task_num == 3){

        return 0;
        //done earlier

    } else{ //that was fast

        int size;
        int *arr = read_arr(&size);
        int arr_sorted[size];
        for(int i = 0; i < size; i++){
            int min = INT_MAX;
            for(int j = 0; j < size; j++){

                if(arr[j] < min){

                    min = arr[j];

                }

            }

            arr_sorted[i] = min;
            printf("%d", min);

        }

    }

}