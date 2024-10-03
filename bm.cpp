#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define NUM 95 //표현 가능한 문자 총 갯수
int skip[NUM];

int index(char c)
{
    return (c-32);
} // ASCII CODE에서 문자는 32부터 시작

void InitSkip(char *p) //skip 배열 만드는 함수
{
    int i, j, M = strlen(p);
    for(i=0;i<NUM;i++) skip[i] = M;
    for(i=0;i<M;i++) skip[index(p[i])] = M-i-1;
}

int MisChar(char *p, char *t) // BM 알고리즘 실행 함수
{
    int i, j, k, M = strlen(p), N = strlen(t);
    InitSkip(p);
    for(i=M-1, j=M-1; j>=0; i--, j--) {
        while(t[i] != p[j]) {
            k = skip[index(t[i])];
            i += (M-j > k) ? M-j : k;
            if(i>=N) return N;
            j = M-1;
        }
        
    }
    return i+1;
}

int main()
{
    char txt[2000]; // 파일에서 한 줄씩 가져올 텍스트를 저장하는 배열
    char pat[50]; // 검색할 패턴을 저장하는 배열
    int M, N, pos, j = 1; // j는 행 번호

    FILE *F = fopen("C:\\Users\\김상현\\Desktop\\과제1\\RFC2616_modified.txt", "r"); // txt파일을 읽기전용으로 불러오기

    if(F== NULL) { // 파일이 없으면 열리지 않음
        printf("파일이 열리지 않음\n");
        return 1;
    }

    printf("찾고자 하는 패턴 입력 : \n");
    gets(pat); // 찾는 패턴을 여기서 입력

    for(;;)
    {
        char *res = fgets(txt, 2000, F); // 파일에서 한 줄씩, 최대 2000바이트까지 읽어옴
        txt[strlen(txt)-1] = '\0'; // enter 키가 입력되는 것을 방지

        M = strlen(pat); N = strlen(txt);
        int i = 0;
        int previous = 0; // 아래 for 문에서 쓰일 변수들에 대한 초기화

        if(res == NULL) { // 더 이상 읽어올 줄이 없으면 그만
            break;
        }
        
        for(;;) { // 패턴이 발견되는 위치를 찾는 for 루프문
            pos = MisChar(pat, txt+i);
            pos += previous; // 한 줄에서 여러 번 패턴을 발견할 경우에, 그 직전까지 검색해 왔던 문자 수를 더하고 다시 탐색
            i = pos + M;
            if(i <= N) printf("%d번째 행에서 패턴이 발생한 위치 : %d\n", j, pos); // 패턴이 발견되었을 때에만 발견 위치 출력
            else break;
            previous = i;
        }
        j++; // 한 행에 대한 탐색이 끝나면 j가 하나 증가, for문 한번 돌 때마다 한 행에 대한 검사가 되는 것임
           
    }

    printf("텍스트 파일 탐색 종료.\n");    
    fclose(F);

    return 0;
}
