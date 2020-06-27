#include <bits/stdc++.h>

using namespace std;

ifstream fin("acces.in");
ofstream fout("acces.out");

queue<int>q;
string v[1002][1002];
int n,m,a[1002][1002];

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fin>>v[i][j];
            if(v[i][j]=='P')
            {
                x=i;
                y=j;
            }
        }
    }
    for(int i=0; i<=n+1; i++)
        v[i][0]=v[i][m+1]='#';
    for(int i=0; i<=m+1; i++)
        v[0][i]=v[n+1][i]='#';
    q.push(make_pair(x,y));
    //IMI E LENE
    while(q.size())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        if(v[x-1][y]=='-')
        {
            a[x-1][y]=a[x][y]+1;
            q.push(make_pair(x-1,y));
        }else if(v[x-1][y]=='#')a[x-1][y]=-1;
        if(v[x][y+1]=='-')
        {
            a[x][y+1]=a[x][y]+1;
            q.push(make_pair(x,y+1));
        }else if(v[x][y+1]=='#')a[x][y+1]=-1;
        if(v[x+1][y]=='-')
        {
            a[x+1][y]=a[x][y]+1;
            q.push(make_pair(x+1,y));
        }else if(v[x+1][y]=='#')a[x+1][y]=-1;
        if(v[x][y-1]=='-')
        {
            a[x][y-1]=a[x][y]+1;
            q.push(make_pair(x,y-1));
        }else if(v[x][y-1]=='#')a[x][y-1]=-1;
    }
    return 0;
}
