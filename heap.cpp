#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define N 1000000

void swap(int a[], int k, int l) {
    int t = a[k]; a[k] = a[l]; a[l] = t;
}

void checksort(int a[], int n) {
    int i, sorted;
    sorted = true;
    for(i=1;i<n+1;i++) {
        if(a[i] > a[i+1]) {
            sorted = false;
        }
        if(!sorted) {
            break;
        }
    }

    if(!sorted) {
        printf("정렬 성공.\n");

    }
    else {
        printf("정렬 오류.\n");
    }
}

void heapifymax(int a[], int h, int m)
{
    int j, v;
    v = a[h];
    for(j=2*h; j<=m; j *= 2) {
        if(j<m && a[j] < a[j+1]) j++;
        if(v>=a[j]) break;
        else a[j/2] = a[j];
    }
    a[j/2] = v;
}

void heapifymin(int a[], int h, int m)
{
    int j, v;
    v = a[h];
    for(j=2*h; j<=m; j *= 2) {
        if(j<m && a[j] > a[j+1]) j++;
        if(v<=a[j]) break;
        else a[j/2] = a[j];
    }
    a[j/2] = v;
}

void heapsort(int a[], int n, int k)
{
    int i;
    switch(k)
    {
        case 1:
            for(i = n/2; i>=1; i--)
            heapifymax(a, i, n);
            for(i = n-1; i>=1; i--) {
            swap(a, 1, i+1);
            heapifymax(a, 1, i);
            }
            break;
    
        case 2:
            for(i = n/2; i>=1; i--)
            heapifymin(a, i, n);
            for(i = n-1; i>=1; i--) {
            swap(a, 1, i+1);
            heapifymin(a, 1, i);
            }
            break;
    
    }
}

int main()
{
    clock_t start1, start2, end1, end2;

    int* a = new int[N+1];
    int* b = new int[N+1];
    srand(time(NULL));

    for(int i=1; i<=N; i++) {
        a[i] = rand();
    }

    for(int i=1;i<=N;i++)
    {
        b[i] = a[i];
    }
    start1 = clock();
    heapsort(a, N, 1);
    end1 = clock();
    float tm1 = end1 - start1;
    checksort(a, N);
    printf("Maxheap sorting complete!\n");
    printf("Maxheap sorting (N=%d) time cost: %.0f\n", N, tm1);
    
    start2 = clock();
    heapsort(b, N, 2);
    end2 = clock();
    float tm2 = end2 - start2;
    checksort(a, N);
    printf("Minheap sorting complete!\n");
    printf("Minheap sorting (N=%d) time cost: %.0f\n", N, tm2);

    return 0;
}
