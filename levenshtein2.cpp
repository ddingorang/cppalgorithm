#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

double min(double a, double b, double c)
{
    if (a <= b && a <= c) return a;
    else if (b <= c && b <= a) return b;
    else return c;
}

double editdistance(char* s, char* t, int m, int n) {
    double D[50][50] = { 0 };
    double cost, ins, del, sub;
    int temp;

    D[0][0] = 0; // i가 target index, j가 source index!!
    for (int i = 1; i <= n; i++) { // 0열 : 삽입비용
        D[i][0] = D[i - 1][0] + 0.7;
    }

    for (int j = 1; j <= m; j++) { // 0행 : 삭제비용
        D[0][j] = D[0][j - 1] + 0.5;
    }

    for (int j = 1; j <= m; j++) { // D 배열 완성
        double minimum = 10000;
        for (int i = 1; i <= n; i++) {
            ins = D[i - 1][j] + 0.7;
            del = D[i][j - 1] + 0.5;
            cost = (s[i - 1] == t[j - 1]) ? 0 : 0.3;
            sub = D[i - 1][j - 1] + cost;
            D[i][j] = min(ins, del, sub);
        }

    }
    cout << endl;

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         //cout << D[i][j] << " ";
    //         printf("%.1f ", D[i][j]);
    //     }
    //     cout << endl;
    // }

    int k = n; int l = m;
    int arr[50] = { 0 }; // 삽입, 삭제, 교환 상태를 저장할 배열
    int index = 0;
    while (1) // D 배열의 오른쪽 아래 구석에서부터 시작한다. (D[n][m]에서부터)
    {
        cout << k << " " << l << endl;
        if (k == 0 || l == 0) break; // 배열의 끝까지 갔다면 그만하기
        else if (min(D[k - 1][l], D[k][l - 1], D[k - 1][l - 1]) == D[k - 1][l]) { // 바로 위가 최소인 경우
            if ((D[k][l] - D[k - 1][l]) < 0.6 ) { // 삽입 연산을 하였다면, 둘의 차이가 0.7은 나야 삽입 연산을 한 것
                k -= 1; l -= 1; // 그렇지 않으면 0의 비용인 교환 연산을 한 것 (열, 행 번호가 각각 1씩 감소)
                arr[index] = 4;
                index++;
                
            }
            else { // 둘의 차이가 0.7이 난다면, 삽입 연산을 한 것
                arr[index] = 1; // 삽입 연산을 하였다는 정보 저장
                index++; // arr 배열의 인덱스 올리기
                k -= 1; // 한 칸 위로 올라간 것임(행 번호가 1 감소)
            }

        }
        else if (min(D[k - 1][l], D[k][l - 1], D[k - 1][l - 1]) == D[k][l - 1]) { // 바로 왼쪽이 최소인 경우
            if ((D[k][l] - D[k][l - 1]) < 0.4){ //  삭제 연산을 하였다면, 둘의 차이가 0.5는 나야 삭제 연산을 한 것
                k -= 1; l -= 1; // 그렇지 않으면 0의 비용인 교환 연산을 한 것 (열, 행 번호가 각각 1씩 감소)
                arr[index] = 4;
                index++;
                
            }
            else { // 둘의 차이가 0.5가 난다면, 삭제 연산을 한 것
                arr[index] = 2; // 삭제 연산을 하였다는 정보 저장
                index++; // arr 배열의 인덱스 올리기
                l -= 1; // 한 칸 왼쪽으로 옮긴 것임(열 번호가 1 감소)
            }
        }
        else if (min(D[k - 1][l], D[k][l - 1], D[k - 1][l - 1]) == D[k - 1][l - 1]) { // 왼쪽 대각선 위가 최소인 경우
            if (D[k][l] > D[k - 1][l - 1]) { // 비용이 0.3인 교환 연산을 한 경우
                arr[index] = 3; // 그 연산의 정보를 저장
                index++; // arr 배열의 인덱스 올리기
                k -= 1; l -= 1; // 열, 행 번호가 각각 1씩 감소
                
            }
            else { // 비용이 0인 교환 연산을 한 것
                k -= 1; l -= 1; // 열, 행 번호가 각각 1씩 감소
                arr[index] = 4;
                index++;
            }
        }


    }

    for (int i = n + m; i >= 0; i--) {
        switch (arr[i])
        {
        case 1: cout << "삽입연산 0.7 "; break;
        case 2: cout << "삭제연산 0.5 "; break;
        case 3: cout << "교환연산 0.3 "; break;
        default:; // 아무 정보가 없는 배열의 원소는 출력 x, 비용이 0인 교환연산도 출력 x
        }
    }

    return D[n][m];
}



int main() {

    char s[19] = "데이타마이닝"; // 소스
    char t[25] = "데이터베이스설계"; // 타깃

    int m = strlen(s);
    int n = strlen(t);

    double res = editdistance(s, t, m, n);

    cout << "스트링 편집 거리 = " << res << endl;
}