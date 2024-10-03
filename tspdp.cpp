#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <climits>
#include <time.h>
using namespace std;

int N;
int W[30][30]; 


int dp[25][1<<24];
    
int tsp(int node, int v){
          	if(v == ((1<<N)-1)) { // 다 방문한 경우 = 모든 비트가 1임
          		if(W[node][1] != 0)
          			return W[node][1]; 
          	}
          	int &ret = dp[node][v];
          	if(ret != 0) return ret;
          	ret = 10000000;

          	for(int i=1;i<=N;i++){
          		if(!(v & (1<<(i-1))) && W[node][i] != 0){ 
          			ret = min(ret, W[node][i] + tsp(i, v | (1<<(i-1)))); 
          		}
          	}

          	return ret;
          }
    
int main(){
    scanf("%d", &N);
    srand(1);

    for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++){
					W[i][j] = rand()%101; 
                    if(i==j) W[i][j] = 0;
				}
	}

    clock_t start = clock();  		
	tsp(1,1);
	clock_t end = clock();

	double res = double(end-start);
	printf("소요 시간 : %.2f ms\n", res);

    printf("%d\n", tsp(1,1));


    return 0;
 
 }


// int W[11][11] =
//    {
// 	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//       {0,0, 13, 41, 20, 19, 18, 44, 82, 33, 16},
//       {0,28, 0, 50, 60, 26, 59, 35, 45, 71, 25},
//       {0,39, 32, 0, 29, 38, 41, 10, 37, 81, 15},
//       {0,20, 27, 39, 0, 44, 36, 24, 48, 45, 23},
//       {0,20, 41, 16, 28, 0, 68, 18, 13, 71, 67},
//       {0,28, 45, 34, 37, 51, 0, 25, 30, 36, 18},
//       {0,78, 27, 44, 15, 60, 11, 0, 29, 31, 12},
//       {0,21, 19, 25, 40, 16, 45, 33, 0, 20, 35},
//       {0,47, 17, 22, 53, 38, 23, 19, 16, 0, 49},
//       {0,67, 38, 72, 26, 13, 12, 48, 55, 10, 0}
//    };