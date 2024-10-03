#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
}

void selectionsort(int a[], int n) {
    int i, j, min;
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1; j<n;j++)
            if(a[j]<a[min])
                min=j;
        swap(a,min,i);
    }
}

void checksort(int a[], int n) {
    int i, sorted;
    sorted = true;
    for(i=0;i<n;i++) {
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

int main()
{
    int i;
    cin >> i;
    int *a = new int[i];
    for(int k = 0; k<i;k++) {
        cin >> a[k];
    }

    selectionsort(a, i);
    //checksort(a, i);
    int sum = 0;
    for(int l = 0;l<i;l++) {
        for(int m = 0; m<=l; m++) {
            sum += a[m];
        }
    }

    cout << sum;

    return 0;   
}