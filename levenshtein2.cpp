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

    D[0][0] = 0; // i�� target index, j�� source index!!
    for (int i = 1; i <= n; i++) { // 0�� : ���Ժ��
        D[i][0] = D[i - 1][0] + 0.7;
    }

    for (int j = 1; j <= m; j++) { // 0�� : �������
        D[0][j] = D[0][j - 1] + 0.5;
    }

    for (int j = 1; j <= m; j++) { // D �迭 �ϼ�
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
    int arr[50] = { 0 }; // ����, ����, ��ȯ ���¸� ������ �迭
    int index = 0;
    while (1) // D �迭�� ������ �Ʒ� ������������ �����Ѵ�. (D[n][m]��������)
    {
        cout << k << " " << l << endl;
        if (k == 0 || l == 0) break; // �迭�� ������ ���ٸ� �׸��ϱ�
        else if (min(D[k - 1][l], D[k][l - 1], D[k - 1][l - 1]) == D[k - 1][l]) { // �ٷ� ���� �ּ��� ���
            if ((D[k][l] - D[k - 1][l]) < 0.6 ) { // ���� ������ �Ͽ��ٸ�, ���� ���̰� 0.7�� ���� ���� ������ �� ��
                k -= 1; l -= 1; // �׷��� ������ 0�� ����� ��ȯ ������ �� �� (��, �� ��ȣ�� ���� 1�� ����)
                arr[index] = 4;
                index++;
                
            }
            else { // ���� ���̰� 0.7�� ���ٸ�, ���� ������ �� ��
                arr[index] = 1; // ���� ������ �Ͽ��ٴ� ���� ����
                index++; // arr �迭�� �ε��� �ø���
                k -= 1; // �� ĭ ���� �ö� ����(�� ��ȣ�� 1 ����)
            }

        }
        else if (min(D[k - 1][l], D[k][l - 1], D[k - 1][l - 1]) == D[k][l - 1]) { // �ٷ� ������ �ּ��� ���
            if ((D[k][l] - D[k][l - 1]) < 0.4){ //  ���� ������ �Ͽ��ٸ�, ���� ���̰� 0.5�� ���� ���� ������ �� ��
                k -= 1; l -= 1; // �׷��� ������ 0�� ����� ��ȯ ������ �� �� (��, �� ��ȣ�� ���� 1�� ����)
                arr[index] = 4;
                index++;
                
            }
            else { // ���� ���̰� 0.5�� ���ٸ�, ���� ������ �� ��
                arr[index] = 2; // ���� ������ �Ͽ��ٴ� ���� ����
                index++; // arr �迭�� �ε��� �ø���
                l -= 1; // �� ĭ �������� �ű� ����(�� ��ȣ�� 1 ����)
            }
        }
        else if (min(D[k - 1][l], D[k][l - 1], D[k - 1][l - 1]) == D[k - 1][l - 1]) { // ���� �밢�� ���� �ּ��� ���
            if (D[k][l] > D[k - 1][l - 1]) { // ����� 0.3�� ��ȯ ������ �� ���
                arr[index] = 3; // �� ������ ������ ����
                index++; // arr �迭�� �ε��� �ø���
                k -= 1; l -= 1; // ��, �� ��ȣ�� ���� 1�� ����
                
            }
            else { // ����� 0�� ��ȯ ������ �� ��
                k -= 1; l -= 1; // ��, �� ��ȣ�� ���� 1�� ����
                arr[index] = 4;
                index++;
            }
        }


    }

    for (int i = n + m; i >= 0; i--) {
        switch (arr[i])
        {
        case 1: cout << "���Կ��� 0.7 "; break;
        case 2: cout << "�������� 0.5 "; break;
        case 3: cout << "��ȯ���� 0.3 "; break;
        default:; // �ƹ� ������ ���� �迭�� ���Ҵ� ��� x, ����� 0�� ��ȯ���굵 ��� x
        }
    }

    return D[n][m];
}



int main() {

    char s[19] = "����Ÿ���̴�"; // �ҽ�
    char t[25] = "�����ͺ��̽�����"; // Ÿ��

    int m = strlen(s);
    int n = strlen(t);

    double res = editdistance(s, t, m, n);

    cout << "��Ʈ�� ���� �Ÿ� = " << res << endl;
}