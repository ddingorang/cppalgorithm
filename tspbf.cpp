#include <cstdio>
#include <algorithm>
#include <climits>
#include <time.h>

using namespace std;

int N;
int W[20][20];
bool v[20]; // 노드 방문 여부를 저장
int res = 1000000;

void tsp(int n, int cost, int count){
        if(count == N) { // 다 돌았으면
        	if(W[n][1] != 0) 
        		res = min(res, cost+W[n][1]);
			return;
        }
        
        v[n] = true;
        for(int i=1;i<=N;i++){
        	if(!v[i] && W[n][i] != 0) {
        			tsp(i, cost+W[n][i], count+1); // 재귀
          	}
        }

        v[n] = false;
}

int main() {
	
	scanf("%d", &N);
	srand(1);
	
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++){
					W[i][j] = rand()%101; 
					if(i==j) W[i][j] == 0;
				}
	}
	

	//printf("%d\n", W[1][1]);
    clock_t start = clock();  		
	tsp(1,0,1);
	clock_t end = clock();

	double tm = double(end-start);
	printf("소요 시간 : %.2f ms\n", tm);
	printf("%d", res);

	return 0;
}        
        

    