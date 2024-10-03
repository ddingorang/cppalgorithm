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
    int rows = 3;
    int cols = 4;

    int arr[3][4] = { // 조약돌을 놓을 배열
        {1, 10, 4, 2}, // 행, 열 번호는 0부터 시작
        {8, -2, 3, 7},
        {2, 6, 1, 5}
    };

    int pat[cols+1][5] = {0}; //  점화식에 따라 계산한 결과를 저장할 배열, 행,열 번호는 1부터 시작

    int maximum = 0;
    int curpat[cols+1] = {0};  // 각 열에서 선택된 패턴을 저장할 배열, 배열 번호는 1부터 시작

    for(int p=1; p<=4; p++) { // 1열에 대해서 먼저 계산
        pat[1][p] = arr[p-1][0];
        if(p==4) pat[1][p] = arr[p-4][0] + arr[p-2][0];
        if(pat[1][p] >= maximum) {
            maximum = pat[1][p];
            curpat[1] = p;
        }
    }
    

    for(int i=2; i<=cols; i++) { // 일단 pat 배열을 전부 다 채워보기
        for(int k = 1; k<=4; k++) {
            if(k==1) {
                pat[i][k] = max(pat[i-1][2], pat[i-1][3], pat[i-1][3]) + arr[k-1][i-1];
            }
            else if(k==2) {
                pat[i][k] = max(pat[i-1][1], pat[i-1][3], pat[i-1][4]) + arr[k-1][i-1];
            }
            else if(k==3) {
                pat[i][k] = max(pat[i-1][1], pat[i-1][2], pat[i-1][2]) + arr[k-1][i-1];
            }
            else if(k==4) {
                pat[i][k] = pat[i-1][2] + arr[0][i-1] + arr[2][i-1];
            }
            
        }
        
    }

    for(int j=2; j<=cols+1; j++) // 그 다음에 제약조건에 따라 최대값 구해보기
    {
        int x = curpat[j-1]; // 이전 열에서 선택된 패턴 : x
        if(x==1) { // 이전 열에서 패턴 1이 선택되었다면, 이번 열에서는 패턴 2, 3 중 큰 것을 선택
            curpat[j] = pat[j][2] >= pat[j][3] ? 2 : 3;
        }
        else if(x==2) { // 이전 열에서 패턴 2가 선택되었다면, 이번 열에서는 패턴 1, 3, 4 중 큰 것을 선택
            curpat[j] = (pat[j][1] >= pat[j][3] && pat[j][1] >= pat[j][4]) ? 1 : (pat[j][3] >= pat[j][4] ? 3 : 4);   
        }
        else if(x==3) { // 이전 열에서 패턴 3이 선택되었다면, 이번 열에서는 패턴 1, 2 중 큰 것을 선택
            curpat[j] = pat[j][1] >= pat[j][2] ? 1 : 2;
        }
        else if(x==4) { // 이전 열에서 패턴 4가 선택되었다면, 이번 열에서는 패턴 2만 가능
            curpat[j] = 2;
        }
    }

    for(int n=1;n<=4;n++) { // pat 배열 출력
        for(int m=1;m<=4;m++) {
            cout << pat[n][m] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int l=1;l<=4;l++) {
        cout << l << "번째 열에서 선택된 패턴 : " << curpat[l] << endl;;
    }

    cout << "최대값 : " << pat[cols][curpat[4]] << endl; // 최대값 출력
}