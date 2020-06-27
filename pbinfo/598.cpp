#include <bits/stdc++.h>

using namespace std;

ifstream fin("gears.in");
ofstream fout("gears.out");

int n,k,x,y,sol[101];
vector<int>v[101];

void DFS(int nod)
{
    for(auto vec:v[nod])
    {
        if(!sol[vec])
        {
            sol[vec]=sol[nod]*(-1);
            DFS(vec);
        }
    }
}

int main()
{
    fin>>n>>k;
    while(fin>>x>>y)
    {
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sol[k]=1;
    DFS(k);
    for(int i=1;i<=n;i++)(sol[i]==1)?fout<<'D':fout<<'S';
    return 0;
}
