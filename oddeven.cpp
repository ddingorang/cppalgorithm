#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap(int a[], int i, int j)
{
    int t = a[i]; a[i] = a[j]; a[j] = t;
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
        printf("정렬 실패.\n");
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    clock_t start, end;

    //srand(time(NULL));
    for(int i=0;i<n;i++) {
        //arr[i] = rand();
        cin >> arr[i];
    }

   
    start = clock();
    for(int j=0;j<n/2;j++) {
        for(int k=0;k<n/2;k++) {
            if(arr[2*k] > arr[2*k+1]){
                swap(arr, 2*k, 2*k+1);
            }
        }
        cout << "odd index" << endl;
        for(int m=0;m<n;m++)
        {
            cout << arr[m] << " ";
        }
        cout << endl;
           
        
        for(int l=0;l<(n/2)-1;l++){
            if(arr[2*l+1] > arr[2*l+2]) {
                swap(arr, 2*l+1, 2*l+2);
            }
        }
        cout << "even index" << endl;
        for(int m=0;m<n;m++)
        {
            cout << arr[m] << " ";
        }
        cout << endl;

        
    }
    end = clock();
    cout << "최종 배열 결과" << endl;
    for(int m=0;m<n;m++)
        {
            cout << arr[m] << " ";
        }
        cout << endl;
    //checksort(arr, n);
    //float tm = end - start;
    //cout << "소요 시간: " << tm << "ms" << endl;
    return 0;

}