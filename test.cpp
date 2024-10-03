#include <iostream>
#include <algorithm>
using namespace std;

/*void swap(int a[], int k, int l) {
    int t = a[k]; a[k] = a[l]; a[l] = t;
}

void bubble(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--) {
            if(a[j-1]>a[j]) {
                swap(a, j-1, j);
            }
        }
    }
}*/
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << '\n';
    }
    
    return 0;
    
}
