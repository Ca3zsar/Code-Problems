#include <bits/stdc++.h>

using namespace std;

ifstream fin("lantminim.in");
ofstream fout("lantminim.out");

int p,q,n,x,y,v[101][101],dist[101],sol[101];
queue<int>c;

int main()
{
    fin>>n>>p>>q;
    while(fin>>x>>y)
    {
        v[x][y]=v[y][x]=1;
    }
    c.push(p);
    dist[p]=1;
    while(c.size())
    {
        int x=c.front();
        c.pop();
        for(int i=1;i<=n;i++)
        {
            if(v[x][i] && !dist[i])
            {
                c.push(i);
                dist[i]=dist[x]+1;
            }
        }
    }
    int x=q;
    int cont=0;
    sol[++cont]=x;
    while(x!=p)
    {
        for(int i=1;i<=n;i++)
        {
            if(v[x][i] && dist[i]==dist[x]-1)
            {
                sol[++cont]=i;
                x=i;
            }
        }
    }
    fout<<cont<<'\n';
    for(int i=cont;i>=1;i--)fout<<sol[i]<<' ';
    return 0;
}
