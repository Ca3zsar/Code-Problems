#include <bits/stdc++.h>

using namespace std;

ifstream fin("fortuna.in");
ofstream fout("fortuna.out");

int n,m,p,k,gr[1001],x,y,maxx;
vector<int>v[1001];
queue<int>q;

int main()
{
    fin>>n>>m;
    for(;m;m--)
    {
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    fin>>k>>p;
    q.push(k);
    gr[k]=1;
    while(q.size())
    {
        x=q.front();
        q.pop();
        for(auto vec:v[x])
        {
            if(!gr[vec])
            {
                gr[vec]=gr[x]+1;
                q.push(vec);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!gr[i])
        {
            fout<<-1;
            return 0;
        }
        if(gr[i]>maxx)maxx=gr[i];
    }
    fout<<maxx+p-1;
    return 0;
}
