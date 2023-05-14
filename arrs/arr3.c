#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//#include"./mtwist-1.5/mtwist.h"

struct pair{

    int el;
    int ind;

}; typedef struct pair* pair;

int part(int arr[], int lo, int hi){

    int pi = arr[hi];
    int i = lo - 1;
    for(int j = lo; j < hi; j++){

        if(arr[j] < pi){

            i++;
            arr[i] += arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] -= arr[j];

        }

    }

    arr[i + 1] += arr[hi];
    arr[hi] = arr[i + 1] - arr[hi];
    arr[i + 1] -= arr[hi];
    return i + 1;

}

void quicksort(int* arr, int lo, int hi){

    if(lo < hi){

       int ind = part(arr, lo, hi);
       quicksort(arr, lo, ind - 1);
       quicksort(arr, ind + 1, hi);  

    }


}

void merge(int arr[], int l, int m, int r){

    int n1 =  m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){

        L[i] = arr[l + i];

    } 
    for(int i = 0; i < n2; i++){

        R[i] = arr[m + 1 + i];
        
    }
    int k = l;
    int j2, j1 = 0; 
    while(j1 < n1 && j2 < n2){

        if(L[j1] < R[j2]){

            arr[k] = L[j1];
            j1++;

        } else{

            arr[k] = R[j2];
            j2++;

        }
        k++;

    }
    while(j1 < n1){

        arr[k] = L[j1];
        j1++;
        k++;

    }
    while(j2 < n2){

        arr[k] = R[j2];
        j2++;
        k++;

    }

}

void mergesort(int arr[], int l, int r){

    if(l < r){

        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);    
        merge(arr, l, m, r);

    }

}

int* new_arr(){

    int *arr = (int*)malloc(sizeof(int) * 100);
    for(int i = 0; i < 100; i++){

        int k = (int)rand() % 2001 - 1000;
        arr[i] = k;
        //printf("%d\n", k);
        
    }
    return arr;

}

int main(){

    int task_num;
    printf("task number from 1 to 8\n");
    scanf("%d", &task_num);
    if(task_num == 1 || task_num == 2){

        int *arr = new_arr();
        for(int outer = 0; outer < 100; outer++){

            int check = 0;

            for(int inner = 0; inner < 99; inner++){

                if(arr[inner] > arr[inner + 1]){

                    arr[inner] += arr[inner + 1];
                    arr[inner + 1] = arr[inner] - arr[inner + 1];
                    arr[inner] -= arr[inner + 1];
                    check = 1;

                }

            }

            if(!check){

                printf("array is sorted:\n");
                for(int i = 0; i < 100; i++){

                    printf("%d ", arr[i]);

                }

                printf("\n");

            }

        }

    } else if(task_num == 3){

        int *arr = new_arr();
        for(int ou = 1; ou < 100; ou++){

            for(int inn = 0; inn < ou; inn++){

                if(arr[inn] > arr[ou]){

                    for(int sw = ou; sw > inn + 1; sw--){

                        arr[sw] += arr[sw - 1];
                        arr[sw - 1] = arr[sw] - arr[sw - 1];
                        arr[sw] -= arr[sw - 1];

                    }

                }                

            }

        }

    } else if(task_num == 4){

        return 0;
        //done in arr1.c (functions)

    } else if(task_num == 5){

        int *arr = new_arr();
        int ind;
        for(int i = 0; i < 100; i++){

            int max = -1001;
            ind = 0;
            for(int j = 0; j < 100; j++){

                if(max < arr[j]){

                    max = arr[j];
                    ind = j;

                }

            }

            for(int sw = 99; sw > 1; sw--){

                arr[sw] += arr[sw - 1];
                arr[sw - 1] = arr[sw] - arr[sw - 1];
                arr[sw] -= arr[sw - 1];

            }

        }

    } else if(task_num == 6){

        int *arr = new_arr();
        pair last_el[100]; 
        for(int i = 0; i < 100; i++){

            if(arr[i] < 0){

                last_el[i]->el = 10 - arr[i] % 10;
                last_el[i]->ind = i;

            } else{

                last_el[i]->el = arr[i] % 10;
                last_el[i]->ind = i;

            }

        }

        for(int outer = 0; outer < 100; outer++){

            int check = 0;

            for(int inner = 0; inner < 99; inner++){

                if(last_el[inner]->el > last_el[inner + 1]->el){

                    last_el[inner]->el += last_el[inner + 1]->el;
                    last_el[inner + 1]->el = last_el[inner]->el - last_el[inner + 1]->el;
                    last_el[inner]->el -= last_el[inner + 1]->el;
                    check = 1;

                }

            }

            if(!check){

                printf("array is sorted by the last digit of number:\n");
                for(int i = 0; i < 100; i++){

                    printf("%d ", arr[last_el[0]->ind]);

                }

                printf("\n");

            }

        }            

    } else if(task_num == 7){

        int *arr = new_arr();
        int f_half[50];
        int s_half[50];
        for(int i = 0; i < 50; i++){

            f_half[i] = arr[i];
            s_half[i] = arr[i + 50];

        }

        quicksort(arr, 0, 50);
        mergesort(arr, 50, 100);
        for(int i = 50; i < 74; i++){

            arr[i] += s_half[49 - i];
            s_half[49 - i] = s_half[i] - s_half[49 - i];
            s_half[i] -= s_half[49 - i];

        }


    } else{

        int *arr = new_arr();
        int co[2000] = {0};
        for(int i = 0; i < 100; i++){

            co[arr[i] + 1000]++;

        }
        
        for(int i = 0; i < 100; i++){

            if(co[arr[i] + 1000] == 1){

                arr[i] = 0;

            }

        }
        quicksort(arr, 0, 100);

    }

}
