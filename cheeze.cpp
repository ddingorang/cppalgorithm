#include <iostream>
using namespace std;

int max(int a, int b)
{
    if(a>=b) return a;
    else return b;
}

int main() 
{
    int rows = 9;
    int cols = 9;

    int arr[9][9] = { // 치즈 배열
        {-1,-1,1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,1,-1,2,-1},
        {1,-1,2,-1,-1,-1,-1,1,-1},
        {-1,-1,-1,-1,1,2,-1,-1,-1},
        {-1,1,-1,1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,2,1,2,-1},
        {-1,1,-1,-1,1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1}
    }; // 아무것도 없으면 -1, 치즈는 1, 쥐 덫은 2

    for(int i=rows-1;i>=0;i--) { // 맨 아래 행부터 시작
        for(int j=0;j<cols;j++) { //0->9열 순서대로 계산
            if(arr[i][j]==2) { // 쥐 덫이 있는 경우
                arr[i][j] = -1; // -1으로 바꾸어 넣고
                continue; // 아래 조건문은 실행하지 않고 넘김
            }
            if(i==rows-1) { // 맨 아래 행인 경우
                if(j==0) break; // 시작은 일단 건너뜀
                else if(arr[i][j]==1) { // 그 칸에 치즈가 있으면 1을 더함
                    arr[i][j] += max(arr[i][j], arr[i][j-1]);
                }
                else { //  없으면 0을 더함
                    arr[i][j] = max(arr[i][j], arr[i][j-1]);
                }
            }
            else if(j==0) { // 첫 열인 경우
                if(arr[i][j]==1) { // 그 칸에 치즈가 있으면 1을 더함
                    arr[i-1][j] += max(arr[i-1][j], arr[i][j]);
                }
                else { //  없으면 0을 더함
                    arr[i-1][j] = max(arr[i-1][j], arr[i][j]);
                }
            }
            else {
                if(arr[i][j]== 1) { // 그 칸에 치즈가 있으면 1을 더함
                    arr[i][j] += max(arr[i][j-1], arr[i+1][j]);
                }
                else { //  없으면 0을 더함
                    arr[i][j] = max(arr[i][j-1], arr[i+1][j]);
                }
                
            }
        }
        
    }

    for(int k=0;k<9;k++) { 
        for(int l=0;l<9;l++) {
            cout << arr[k][l] << " ";
        }
        cout << endl;
    }

    cout << "치즈의 최대값 : " << arr[0][cols-1] + 1 << endl; // 출구에서의 값이 최대값
    return 0;
    
}