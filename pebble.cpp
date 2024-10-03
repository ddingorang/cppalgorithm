#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if(a>=b && a>=c) return a;
    else if(b>=c && b>=a) return b;
    else return c;
}

int main()
{
    int rows = 3;
    int cols = 4;

    int arr[3][4] = { // ���൹�� ���� �迭
        {1, 10, 4, 2}, // ��, �� ��ȣ�� 0���� ����
        {8, -2, 3, 7},
        {2, 6, 1, 5}
    };

    int pat[cols+1][5] = {0}; //  ��ȭ�Ŀ� ���� ����� ����� ������ �迭, ��,�� ��ȣ�� 1���� ����

    int maximum = 0;
    int curpat[cols+1] = {0};  // �� ������ ���õ� ������ ������ �迭, �迭 ��ȣ�� 1���� ����

    for(int p=1; p<=4; p++) { // 1���� ���ؼ� ���� ���
        pat[1][p] = arr[p-1][0];
        if(p==4) pat[1][p] = arr[p-4][0] + arr[p-2][0];
        if(pat[1][p] >= maximum) {
            maximum = pat[1][p];
            curpat[1] = p;
        }
    }
    

    for(int i=2; i<=cols; i++) { // �ϴ� pat �迭�� ���� �� ä������
        for(int k = 1; k<=4; k++) {
            if(k==1) {
                pat[i][k] = max(pat[i-1][2], pat[i-1][3], pat[i-1][3]) + arr[k-1][i-1];
            }
            else if(k==2) {
                pat[i][k] = max(pat[i-1][1], pat[i-1][3], pat[i-1][4]) + arr[k-1][i-1];
            }
            else if(k==3) {
                pat[i][k] = max(pat[i-1][1], pat[i-1][2], pat[i-1][2]) + arr[k-1][i-1];
            }
            else if(k==4) {
                pat[i][k] = pat[i-1][2] + arr[0][i-1] + arr[2][i-1];
            }
            
        }
        
    }

    for(int j=2; j<=cols+1; j++) // �� ������ �������ǿ� ���� �ִ밪 ���غ���
    {
        int x = curpat[j-1]; // ���� ������ ���õ� ���� : x
        if(x==1) { // ���� ������ ���� 1�� ���õǾ��ٸ�, �̹� �������� ���� 2, 3 �� ū ���� ����
            curpat[j] = pat[j][2] >= pat[j][3] ? 2 : 3;
        }
        else if(x==2) { // ���� ������ ���� 2�� ���õǾ��ٸ�, �̹� �������� ���� 1, 3, 4 �� ū ���� ����
            curpat[j] = (pat[j][1] >= pat[j][3] && pat[j][1] >= pat[j][4]) ? 1 : (pat[j][3] >= pat[j][4] ? 3 : 4);   
        }
        else if(x==3) { // ���� ������ ���� 3�� ���õǾ��ٸ�, �̹� �������� ���� 1, 2 �� ū ���� ����
            curpat[j] = pat[j][1] >= pat[j][2] ? 1 : 2;
        }
        else if(x==4) { // ���� ������ ���� 4�� ���õǾ��ٸ�, �̹� �������� ���� 2�� ����
            curpat[j] = 2;
        }
    }

    for(int n=1;n<=4;n++) { // pat �迭 ���
        for(int m=1;m<=4;m++) {
            cout << pat[n][m] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int l=1;l<=4;l++) {
        cout << l << "��° ������ ���õ� ���� : " << curpat[l] << endl;;
    }

    cout << "�ִ밪 : " << pat[cols][curpat[4]] << endl; // �ִ밪 ���
}