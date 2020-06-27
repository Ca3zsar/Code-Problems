#include <bits/stdc++.h>

using namespace std;

ifstream fin("hanoi.in");
ofstream fout("hanoi.out");

queue<pair<char,char>>q;
int nr;
void Hanoi(char a, char b, char c, int n)
{
    if(n)
    {
        Hanoi(a,c,b,n-1);
        q.push(make_pair(a,b));
        nr++;
        Hanoi(c,b,a,n-1);
    }
}

int main()
{
    int n;
    fin>>n;
    Hanoi('A','C','B',n);
    fout<<nr<<'\n';
    while(q.size())
    {
        pair<char,char>t;
        t=q.front();
        fout<<t.first<<"->"<<t.second<<'\n';
        q.pop();
    }
    return 0;
}
