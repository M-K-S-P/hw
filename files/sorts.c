#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++){

        printf("%d ", A[i]);

    }
    printf("\n");
}

void sw(int *a, int *b){

    int c = *a;
    *a = *b;
    *b = c;

}

void merge(int* arr, int l, int m, int r){

    int n1 =  m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){ L[i] = arr[l + i]; } 
    for(int q = 0; q < n2; q++){ R[q] = arr[m + 1 + q]; }
    int k = l;
    int i = 0;
    int q = 0; 
    while (i < n1 && q < n2) {
        if (L[i] <= R[q]) {
            arr[k] = L[i];
            i++;
        } else{
            arr[k] = R[q];
            q++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (q < n2) {
        arr[k] = R[q];
        q++;
        k++;
    }

}

int part(int arr[], int lo, int hi){

    int pi = arr[hi];
    int i = lo - 1;
    //int ch = 0;
    for(int j = lo; j <= hi - 1; j++){

        if(arr[j] <= pi){

            i += 1;
            //printf("%d %d\n", arr[i], arr[j]);
            sw(&arr[i], &arr[j]);
            //printf("%d %d\n", arr[i], arr[j]);

        }

    }
    i += 1;
    sw(&arr[hi], &arr[i]);
    return i;

}

void quicksort(int arr[], int lo, int hi){

    if(lo > hi){ return; }
    int ind = part(arr, lo, hi);
    quicksort(arr, lo, ind - 1);
    quicksort(arr, ind + 1, hi);  

}

void mergesort(int* arr, int l, int r){

    if(l < r){

        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);    
        merge(arr, l, m, r);

    } else{ return; }

}

void heap(int a[], int si, int n){

    int l = 2 * n + 1;
    int r = 2 * n + 2;
    int lar = n;
    if(l < si && a[l] > a[lar]){ lar = l; }
    if(r < si && a[r] > a[lar]){ lar = r; }
    if(lar != n){ 
        
        sw(&a[lar], &a[n]); 
        heap(a, si, lar);

    }

}

void heapsort(int a[], int si){

    for(int i = si / 2 - 1; i >= 0; i--){ heap(a, si, i); }
    for(int i = si - 1; i >= 0; i--){

        sw(&a[0],&a[i]);
        heap(a, i, 0);

    }

}
