#include <iostream>
using namespace std;
#include <string>

int nxt[1000001];
int posn[1000001]={0};

void InitNext(string p) {
    int i, j, M = p.length();
    nxt[0] = -1;
    for(i=0, j=-1; i<M; i++, j++) {
        nxt[i] = (p[i] == p[j]) ? nxt[j] : j;
        while((j>=0) && (p[i] != p[j])) j = nxt[j];
    }
}

int KMP(string p, string t) {
    int i, j, M = p.length(), N = t.length();
    InitNext(p);
    for(i=0, j=0; j<M && i<N; i++, j++) {
        while((j>=0) && (t[i] != p[j])) j = nxt[j];
    }
    if(j==M) return i-M;
    else return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    string txt;
    string pat;
    int pos, prev = 0, i=0;
    getline(cin, txt);
    getline(cin, pat);
    /*fgets(txt, 100, stdin);
    size_t tlen = strlen(txt);
    if (tlen > 0 && txt[tlen-1] == '\n')
        txt[tlen-1] = '\0';
    fgets(pat, 100, stdin);
    size_t plen = strlen(pat);
    if (plen > 0 && pat[plen-1] == '\n')
        pat[plen-1] = '\0';
    */
    int M = txt.length(), N = pat.length();
    
    int j=0;
    for(j=0;;)
    {
        pos = KMP(pat, txt);
        pos += prev;
        i = pos + M;
        if(i<=N) 
        {
            posn[j] = pos + 1;
            j++;
        }
        
        else break;
        prev = i;
    }
    
    cout << j << '\n';
    for(int k=0;;k++)
    {
        if(posn[k] == 0) break;
        cout << posn[k] << '\n';
        
    }

    return 0;
}
