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

void InitSkip(char *p) //skip �迭 ����� �Լ�
{
    int i, j, M = strlen(p);
    for(i=0;i<NUM;i++) skip[i] = M;
    for(i=0;i<M;i++) skip[index(p[i])] = M-i-1;
}

int MisChar(char *p, char *t) // BM �˰��� ���� �Լ�
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
    char txt[2000]; // ���Ͽ��� �� �پ� ������ �ؽ�Ʈ�� �����ϴ� �迭
    char pat[50]; // �˻��� ������ �����ϴ� �迭
    int M, N, pos, j = 1; // j�� �� ��ȣ

    FILE *F = fopen("C:\\Users\\�����\\Desktop\\����1\\RFC2616_modified.txt", "r"); // txt������ �б��������� �ҷ�����

    if(F== NULL) { // ������ ������ ������ ����
        printf("������ ������ ����\n");
        return 1;
    }

    printf("ã���� �ϴ� ���� �Է� : \n");
    gets(pat); // ã�� ������ ���⼭ �Է�

    for(;;)
    {
        char *res = fgets(txt, 2000, F); // ���Ͽ��� �� �پ�, �ִ� 2000����Ʈ���� �о��
        txt[strlen(txt)-1] = '\0'; // enter Ű�� �ԷµǴ� ���� ����

        M = strlen(pat); N = strlen(txt);
        int i = 0;
        int previous = 0; // �Ʒ� for ������ ���� �����鿡 ���� �ʱ�ȭ

        if(res == NULL) { // �� �̻� �о�� ���� ������ �׸�
            break;
        }
        
        for(;;) { // ������ �߰ߵǴ� ��ġ�� ã�� for ������
            pos = MisChar(pat, txt+i);
            pos += previous; // �� �ٿ��� ���� �� ������ �߰��� ��쿡, �� �������� �˻��� �Դ� ���� ���� ���ϰ� �ٽ� Ž��
            i = pos + M;
            if(i <= N) printf("%d��° �࿡�� ������ �߻��� ��ġ : %d\n", j, pos); // ������ �߰ߵǾ��� ������ �߰� ��ġ ���
            else break;
            previous = i;
        }
        j++; // �� �࿡ ���� Ž���� ������ j�� �ϳ� ����, for�� �ѹ� �� ������ �� �࿡ ���� �˻簡 �Ǵ� ����
           
    }

    printf("�ؽ�Ʈ ���� Ž�� ����.\n");    
    fclose(F);

    return 0;
}
