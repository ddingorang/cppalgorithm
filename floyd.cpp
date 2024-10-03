#include <iostream>
using namespace std;
#define num 5 // 정점의 수

int W[6][6] = { // 인접행렬
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 100000, 1, 5}, 
    {0, 9, 0, 3, 2, 100000},
    {0, 100000, 100000, 0, 4, 100000},
    {0, 100000, 100000, 2, 0, 3},
    {0, 3, 100000, 100000, 100000, 0}
};

int D[6][6];
int P[6][6];

void floyd2(int n, int W[6][6], int D[6][6], int P[6][6]) {
    int i, j, k;
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) { // 초기화
            P[i][j] = 0;
            D[i][j] = W[i][j];
        }
    }

    for(k=1; k<=n; k++) {
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++) {
                if(D[i][k] + D[k][j] < D[i][j]) { // 하나 거치고 가는 것이 더 짧은 경우
                    P[i][j] = k; // 그 정점의 인덱스 값을 P 배열에 저장
                    D[i][j] = D[i][k] + D[k][j]; // 값 업데이트
                }
            }
        }
    }
}

void path(int q, int r) { // 경로 출력 함수
    if(P[q][r] != 0) {
        path(q, P[q][r]);
        cout << " v" << P[q][r] << " ->";
        path(P[q][r], r);
    }
}


int main() {

    floyd2(5, W, D, P);

    for(int i=1; i<=num; i++) { // 행렬 D 출력
        for(int j=1; j<=num; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=1; i<=num; i++) { // 행렬 P 출력
        for(int j=1; j<=num; j++) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The shortest path(5, 3) is v5 ->" ; // v5 -> v3
    path(5, 3);
    cout << " v3" << endl;

    cout << "The shortest path(1, 3) is v1 ->" ; // v1 -> v3
    path(1, 3);
    cout << " v3" << endl;

    cout << "The shortest path(2, 5) is v2 ->" ; // v2 -> v5
    path(2, 5);
    cout << " v5";

    return 0;

}