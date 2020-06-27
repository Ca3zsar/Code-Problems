#include <bits/stdc++.h>

using namespace std;

ifstream fin("partial.in");
ofstream fout("partial.out");

int n,m,x,y,sol[201],a[201][201],cnt,viz[201];
vector<int>v[201];

void DFS(int nod)
{
    sol[++cnt]=nod;
    viz[nod]=1;
    for(auto vec:v[nod])
    {
        if(!viz[vec])DFS(vec);
    }
}

int main()
{
    fin>>n;
    while(fin>>x>>y)
    {
        v[x].push_back(y);
        v[y].push_back(x);
        m++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!viz[i])
        {
            DFS(i);
            int sum=0;
            for(int j=1;j<=cnt;j++)
            {
                sum+=v[sol[j]].size();
            }
            if(sum==m)
            {
                for(int j=1;j<=cnt;j++)
                {
                    for(auto vec:v[j])a[j][vec]=1;
                }
                for(int j=1;j<=n;j++)
                {
                    for(int k=1;k<=n;k++)fout<<a[j][k]<<' ';
                    fout<<'\n';
                }
                return 0;
            }else cnt=0;
        }
    }
    return 0;
}
