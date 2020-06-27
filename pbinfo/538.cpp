#include <bits/stdc++.h>

using namespace std;

ifstream fin("lungimeminima.in");
ofstream fout("lungimeminima.out");

int n,p,L,x,y,dist[101],viz[101],cnt;
int v[101][101];
queue<int>q;

int main()
{
    fin>>n>>p>>L;
    while(fin>>x>>y)
    {
        v[x][y]=v[y][x]=1;
    }
    q.push(p);
    viz[p]=1;
    while(q.size())
    {
        int varf=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(v[varf][i] && !viz[i])
            {
                dist[i]=dist[varf]+1;
                viz[i]=1;
                q.push(i);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(dist[i]>=L)cnt++;
    }
    fout<<cnt<<'\n';
    for(int i=1; i<=n; i++)
    {
        if(dist[i]>=L)fout<<i<<' ';
    }
    return 0;
}
