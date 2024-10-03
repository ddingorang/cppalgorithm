#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if(a>=b && a>=c) return a;
    else if(b>=c && b>=a) return b;
    else return c;
}

int main() 
{
    int rows = 8;
    int cols = 9;

    int arr[8][9] = {
        {3, 4, 9, -2, 2, 51, -23, 2, -1},
        {223, 7, 8, -11, 5, -99, 2, 3, -4},
        {2, 51, -23, -23, 6, 3, 2, 4, 5},
        {5, -99, 2, -1, 32, 2, 5, -99, 2},
        {6, 3, 3, -4, 2, -1, 6, 3, 3},
        {32, 2, 4, 5, 3, -4, 2, -1, 4},
        {4, 4, 23, 6, 2, -1, 3, -4, 34},
        {78, 32, 1, 7, 3, -4, -23, -23, 6}
    };

    int arr2[8][9];
    for(int k=0;k<8;k++) { // 배열 복사
        for(int l=0;l<9;l++) {
            arr2[k][l] = arr[k][l];
        }
    }

    int maxnum[8];

    for(int i=1;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(j==0) {
                arr[i][j] = max(arr[i-1][j], arr[i-1][j+1], arr[i-1][j+1]) + arr[i][j];
            }
            else if(j==cols-1) {
                arr[i][j] = max(arr[i-1][j-1], arr[i-1][j], arr[i-1][j]) + arr[i][j];
            }
            else {
                arr[i][j] = max(arr[i-1][j-1], arr[i-1][j], arr[i-1][j+1]) + arr[i][j];
            }
        }
        
    }

    int maximum=0;
    int index = 0;
    for(int k=0;k<cols-1;k++) {
        if(maximum<max(arr[rows-1][k], arr[rows-1][k+1])) {
            maximum = max(arr[rows-1][k], arr[rows-1][k+1]);
            if(arr[rows-1][k] >= arr[rows-1][k+1]) index = k;
            else if(arr[rows-1][k] < arr[rows-1][k+1]) index = k+1;
        }
    }

    maxnum[7] = arr2[rows-1][index];
    for(int n=6;n>=0;n--) {
        if(index==0) {
            maxnum[n] = max(arr2[n][0], arr2[n][1], arr2[n][1]);
        }
        else if(index=cols-1) {
            maxnum[n] = max(arr2[n][cols-1], arr2[n][cols-2], arr2[n][cols-1]);
        }
        else {
            maxnum[n] = max(arr2[n][index-1], arr2[n][index], arr2[n][index+1]);
        }
    }
    
    for(int m=0;m<8;m++)
    {
        cout << m+1 << " 행에서 : " << maxnum[m]  << " 선택" << endl;
    }

    cout << "최대값은 : " << maximum << endl;

    return 0;
    
}