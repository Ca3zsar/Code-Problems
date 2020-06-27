#include <bits/stdc++.h>

using namespace std;

int n,m,plecare;
bool b[101];
int v[101][101];
int sol[101];

void DFS(int nod,int cont)
{
    sol[cont]=nod;
    if(nod==plecare &&cont==4)
    {
        for(int i=1; i<cont; i++)
            cout<<sol[i]<<' ';
        cout<<'\n';
    }
    else
    {
        if(cont<4)
        {
            for(auto vec:v[nod])
            {
                if(!b[vec])
                {
                    b[vec]=true;
                    DFS(vec,cont+1);
                    b[vec]=false;
                }
            }
        }
    }
    //cout<<nod<<'\n';
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1; i<=n; i++)
    {
        plecare=i;
        DFS(i,1);
    }
    return 0;
}
