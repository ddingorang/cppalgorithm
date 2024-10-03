#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

double min(double a, double b, double c)
{
    if(a<=b && a<=c) return a;
    else if(b<=c && b<=a) return b;
    else return c;
}

double editdistance(char* s, char* t, int m, int n) {
    double D[n+1][m+1] = {0};
    double cost, ins, del, sub;
    int temp;

    D[0][0] = 0; // i�� target index, j�� source index!!
    for(int i=1; i<=n; i++) { // 0�� : ���Ժ��
        D[i][0] = D[i-1][0] + 0.7;
    }
    
    for(int j=1; j<=m; j++) { // 0�� : �������
        D[0][j] = D[0][j-1] + 0.5;
    }

    for(int j=1; j<=m; j++) {
        double minimum = 10000;
        for(int i=1; i<=n; i++) {
            ins = D[i-1][j] + 0.7;
            del = D[i][j-1] + 0.5;
            cost = (s[i-1] == t[j-1]) ? 0 : 0.3;
            sub = D[i-1][j-1] + cost;
            D[i][j] = min(ins, del, sub);

            if(minimum > D[i][j]) {
                minimum = D[i][j];
                if(D[i][j]==ins) temp = 1;
                else if(D[i][j]==del) temp = 2;
                else if(D[i][j]==sub) {
                    temp = (cost==0) ? 4 : 3; 
                }
            }

            if(i==n && j==m) {
                if(D[n][m]==ins) temp = 1;
                else if(D[n][m]==del) temp = 2;
                else if(D[n][m]==sub) {
                    temp = (cost==0) ? 4 : 3; 
                }
            }

        }

        // cout << "minimum : " << minimum << endl;
        // cout << "temp : " << temp << endl;

        switch(temp)
        {
            case 1: cout << "���Կ��� 0.7 "; break;
            case 2: cout << "�������� 0.5 "; break;
            case 3: cout << "��ȯ���� 0.3 "; break;
            default : ;
        }
        
    }
    cout << endl;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++) {
            //cout << D[i][j] << " ";
            printf("%.1f ", D[i][j]);
        }
        cout << endl;
    }

    return D[n][m];
}
        
    

int main() {

    char s[6] = "TACTG";
    char t[9] = "CATGACTG";

    int m = strlen(s);
    int n = strlen(t);

    double res = editdistance(s, t, m, n);
   
    cout << "��Ʈ�� ���� �Ÿ� = " << res << endl;
}