#include <bits/stdc++.h>
#define triplu tuple<int,int,int>
#define pereche pair<int,int>
using namespace std;

ifstream fin("kruskal.in");
ofstream fout("kruskal.out");

queue<pereche>q;
vector<triplu>v;
int n,m,x,y,cost,d[101],total;

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
        fin>>x>>y>>cost;
        v.push_back(make_tuple(cost,x,y));
    }
    sort(v.begin(),v.end());
    for(auto vec:v)
    {
        tie(cost,x,y)=vec;
        int rx=get_root(x);
        int ry=get_root(y);
        if(rx==ry)continue;
        d[rx]=ry;
        total+=cost;
        q.push(make_pair(x,y));
    }
    fout<<total<<'\n';
    while(q.size())
    {
        pereche varf=q.front();
        q.pop();
        fout<<varf.first<<' '<<varf.second<<'\n';
    }
    return 0;
}
