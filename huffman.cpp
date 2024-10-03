#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct nodetype {
    string symbol;
    int frequency;
    nodetype* left;
    nodetype* right;

    nodetype(string sym, int freq, nodetype* lft, nodetype* rgt) : symbol(sym), frequency(freq), left(lft), right(rgt) {};
};

struct cmp {
  bool operator()(nodetype a, nodetype b) {
    return a.frequency > b.frequency;
  }
};

int main()
{
    priority_queue<nodetype, vector<nodetype>, cmp> pq;

    pq.push(nodetype("A", 15, NULL, NULL));
    pq.push(nodetype("B", 12, NULL, NULL));
    pq.push(nodetype("C", 9, NULL, NULL));
    pq.push(nodetype("D", 5, NULL, NULL));
    pq.push(nodetype("E", 10, NULL, NULL));
    pq.push(nodetype("F", 11, NULL, NULL));
    pq.push(nodetype("RS", 27, NULL, NULL));

    for(int i=1; i<=6; i++)
    {
        nodetype p=pq.top();
        pq.pop();
        nodetype q=pq.top();
        pq.pop();

        struct nodetype r(string s, int rf , nodetype* p, nodetype* q);
        string s = " ";
        int rf = p.frequency + q.frequency;
        nodetype* pl = p.left;
        nodetype* pr = p.right;
        pq.push(r(s, rf, pl, pr));

    } 
    pq.pop();
     
    /*for(int i=1;i<=13;i++)
    {
        nodetype temp = pq.top();
        cout << temp.frequency << " " << temp.symbol << endl;
        pq.pop();
    }*/

    nodetype temp = pq.top();
    cout << temp.frequency << " " << temp.symbol << endl;
    pq.pop();
    nodetype temp2 = pq.top();
    cout << temp2.frequency << " " << temp2.symbol << endl;
    pq.pop();
    
    return 0;

}