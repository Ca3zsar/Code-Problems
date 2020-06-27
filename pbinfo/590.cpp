#include <bits/stdc++.h>
#define triplu tuple<int,int,int>
using namespace std;

ifstream fin("prim.in");
ofstream fout("prim.out");

int n,m,a,b,cost,d[101],d2[101],ra,rb,total,x[101][101];
vector<triplu>v;

int get_root(int nod)
{
    if(nod==d[nod])return nod;
    d[nod]=get_root(d[nod]);
    return d[nod];
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)d[i]=i;
    for(;m;m--)
    {
        fin>>a>>b>>cost;
        x[a][b]=x[b][a]=1;
        v.push_back(make_tuple(cost,a,b));
    }
    sort(v.begin(),v.end());
    for(auto vec:v)
    {
        tie(cost,a,b)=vec;
        ra=get_root(a);
        rb=get_root(b);
        if(ra==rb)
        {
            x[b][a]=0;
            x[a][b]=0;
            continue;
        }
        d[rb]=ra;
        d2[b]=a;
        total+=cost;
    }
    queue<int>q;
    q.push(1);
    while(q.size())
    {
        int ps=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(x[ps][i])
            {
                x[ps][i]=0;
                x[i][ps]=0;
                d2[i]=ps;
                q.push(i);
            }
        }
    }
    fout<<total<<'\n';
    for(int i=1;i<=n;i++)fout<<d2[i]<<' ';
    return 0;
}
