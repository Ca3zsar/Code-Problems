#include <bits/stdc++.h>

using namespace std;

ifstream fin("lant1.in");
ofstream fout("lant1.out");

int p,q,r,n,x,y,dist1[101],dist2[101],sol[101],cont;
vector<int>v[101];
queue<int>c;

int main()
{
    fin>>n>>p>>q>>r;
    while(fin>>x>>y)
    {
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dist1[r]=1;
    c.push(r);
    while(c.size())
    {
        int x=c.front();
        c.pop();
        for(auto vec:v[x])
        {
            if(!dist1[vec])
            {
                dist1[vec]=dist1[x]+1;
                c.push(vec);
            }
        }

    }
    int x=q;
    sol[++cont]=x;
    while(x!=r)
    {
        for(auto vec:v[x])
        {
            if(dist1[vec]==dist1[x]-1)
            {
                sol[++cont]=vec;
                x=vec;
            }
        }
    }
    dist2[p]=1;
    c.push(p);
    while(c.size())
    {
        int x=c.front();
        c.pop();
        for(auto vec:v[x])
        {
            if(!dist2[vec])
            {
                dist2[vec]=dist2[x]+1;
                c.push(vec);
            }
        }

    }
    x=r;
    while(x!=p)
    {
        for(auto vec:v[x])
        {
            if(dist2[vec]==dist2[x]-1)
            {
                sol[++cont]=vec;
                x=vec;
            }
        }
    }
    fout<<cont<<'\n';
    for(int i=cont;i>=1;i--)fout<<sol[i]<<' ';
    return 0;
}
