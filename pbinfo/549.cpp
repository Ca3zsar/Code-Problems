#include <bits/stdc++.h>

using namespace std;

ifstream fin("epidemie.in");
ofstream fout("epidemie.out");

vector<int>v[1001];
queue<int>q;
int n,m,k,x,y,dist[1001],maxx;

int main()
{
    fin>>n>>m;
    for(;m;m--)
    {
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    fin>>k;
    for(;k;k--)
    {
        fin>>x;
        q.push(x);
        dist[x]=1;
    }
    while(q.size())
    {
        x=q.front();
        q.pop();
        if(dist[x]>maxx)maxx=dist[x];
        for(auto vec:v[x])
        {
            if(!dist[vec])
            {
                dist[vec]=dist[x]+1;
                q.push(vec);
            }
        }
    }
    fout<<maxx;
    return 0;
}
