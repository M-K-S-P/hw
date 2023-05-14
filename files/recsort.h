#ifndef RECSORT_H
#define RECSORT_H
void sw(int *a, int *b);
void heapsort(int a[], int si);
void mergesort(int* arr, int l, int r);
void quicksort(int arr[], int lo, int hi);
int part(int arr[], int lo, int hi);
void merge(int* arr, int l, int m, int r);
void heap(int a[], int si, int n);
#endif