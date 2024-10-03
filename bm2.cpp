#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define NUM 95 //ǥ�� ������ ���� �� ����
int skip[NUM];

int index(char c)
{
    return (c-32);
} // ASCII CODE���� ���ڴ� 32���� ����

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
    int M, N, pos, j = 1; // j�� �� ��ȣ

    FILE *F = fopen("C:\\Users\\�����\\Desktop\\����1\\RFC2616_modified.txt", "r");

    if(F== NULL) {
        printf("������ ������ ����\n");
        return 1;
    }

    printf("ã���� �ϴ� ���� �Է� : \n");
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
    //     if(i <= N) printf("������ �߻��� ��ġ : %d\n", pos);
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
            if(i <= N) printf("%d��° �࿡�� ������ �߻��� ��ġ : %d\n", j, pos);
            else break;
            previous = i;
        }
        j++; // �� �࿡ ���� Ž���� ������ j�� �ϳ� ����
           
    }

    printf("�ؽ�Ʈ ���� Ž�� ����.\n");    
    
    return 0;
}
