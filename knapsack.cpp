#include <iostream>
using namespace std;
#define itemnum 8
#define maxweight 30

int max(int a, int b) // 대소 비교 함수
{
    if(a>=b) return a;
    else return b;
}

// int knapsack(int itn, int mxw, int item[][2])
// {
//     int p[itn+1][mxw+1] = {0}; // 최고 이익 저장 배열

//     for(int i=1; i<=itn; i++) {
//         for(int w = 0; w<=mxw; w++)
//         {
//             if(i==1 && item[i][1] <= w) { // 첫 번째 아이템만을 이용하여 담는 최대 이득은 
//                 p[i][w] = item[i][1]; // 그냥 그 아이템 하나의 가치임
//             }
//             if(item[i][0] <= w) { // 넣고자 하는 아이템을 넣어도 최대 중량을 초과하지 않으면
//                 p[i][w] = max(p[i-1][w], item[i][1] + p[i-1][w-item[i][0]] ); // 넣는 경우와 넣지 않는 경우 중 큰 것을 택
//             }
//             else { // 아이템을 넣으면 중량이 초과함
//                 p[i][w] = p[i-1][w]; // 넣지 않고 그 전 아이템까지의 최대 이득으로 값을 갱신
//             }
//         }
//     }

//     return p[itn][mxw];
// }

int main()
{
    int item2[7][2] = { // 0열은 무게, 1열은 가치
        {0, 0}, {5, 5}, {10, 7}, {7, 10}, {3, 6}, {4, 8}, {11, 20}
    };

    int item[9][2] = {
        {0, 0}, {3, 5}, {7, 7}, {8, 10}, {5, 6}, {6, 8}, {13, 20}, {11, 18}, {2, 5}
    };

    int p[itemnum+1][maxweight+1] = {0}; // 최고 이익 저장 배열

    for(int i=1; i<=itemnum; i++) {
        for(int w = 0; w<=maxweight; w++)
        {
            if(i==1 && item[i][1] <= w) { // 첫 번째 아이템만을 이용하여 담는 최대 이득은 
                p[i][w] = item[i][1]; // 그냥 그 아이템 하나의 가치임
            }
            if(item[i][0] <= w) { // 넣고자 하는 아이템을 넣어도 최대 중량을 초과하지 않으면
                p[i][w] = max(p[i-1][w], item[i][1] + p[i-1][w-item[i][0]] ); // 넣는 경우와 넣지 않는 경우 중 큰 것을 택
            }
            else { // 아이템을 넣으면 중량이 초과함
                p[i][w] = p[i-1][w]; // 넣지 않고 그 전 아이템까지의 최대 이득으로 값을 갱신
            }
        }
    }

    // cout << "입력 1에 대하여 가방에 담은 보석의 최대 가치 = " << knapsack(6, 15, item1); // 6번째 아이템까지 판단한 후의 최종 최대 이득
    // cout << "입력 2에 대하여 가방에 담은 보석의 최대 가치 = " << knapsack(8, 30, item2); 

    // cout << "입력 1에 대하여 가방에 담은 보석의 최대 가치 = " << p[6][15];
    cout << "입력 2에 대하여 가방에 담은 보석의 최대 가치 = " << p[8][30];
    return 0;
}


