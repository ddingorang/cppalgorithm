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

void InitSkip(char *p) 
{
    int i, j, M = strlen(p);
    for(i=0;i<NUM;i++) skip[i] = M;
    for(i=0;i<M;i++) skip[index(p[i])] = M-i-1;
}

int MisChar(char *p, char *t)
{
    int i, j, k, M = strlen(p), N = strlen(t);
    InitSkip(p);
    for(i=M-1, j=M-1; j>=0; i--, j--) {
        while(t[i] != p[j]) {
            k = skip[index(p[i])];
            i += (M-j > k) ? M-j : k;
            if(i>=N) return N;
            j = M-1;
        }
        
    }
    return i+1;
}

int main()
{
    char txt[2000];
    char pat[50];
    int M, N, pos, j = 1; // j는 행 번호

    FILE *F = fopen("C:\\Users\\김상현\\Desktop\\과제1\\RFC2616_modified.txt", "r");

    if(F== NULL) {
        printf("파일이 열리지 않음\n");
        return 1;
    }

    printf("찾고자 하는 패턴 입력 : \n");
    cin >> pat;

    //char *res = fgets(txt, 500, F);
    //txt[strlen(txt)-1] = '\0';
        
    // if(res == NULL) {
    //     break;
    // }
    //cout << txt << endl;

    

    // for(;;)
    // {
    //     pos = MisChar(pat, txt+i);
    //     pos += previous;
    //     i = pos + M;
    //     if(i <= N) printf("패턴이 발생한 위치 : %d\n", pos);
    //     else break;
    //     previous = i;
    // }
    
    
    for(;;)
    {
        char *res = fgets(txt, 2000, F);
        txt[strlen(txt)-1] = '\0';

        M = strlen(pat); N = strlen(txt);
        int i = 0;
        int previous = 0;

        if(res == NULL) {
            break;
        }
        
        for(;;) {
            pos = MisChar(pat, txt+i);
            pos += previous;
            i = pos + M;
            if(i <= N) printf("%d번째 행에서 패턴이 발생한 위치 : %d\n", j, pos);
            else break;
            previous = i;
        }
        j++; // 한 행에 대한 탐색이 끝나면 j가 하나 증가
           
    }

    printf("텍스트 파일 탐색 종료.\n");    
    
    return 0;
}
