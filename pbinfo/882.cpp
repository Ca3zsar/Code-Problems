#include <bits/stdc++.h>
using namespace std;

ifstream fin("lac.in");
ofstream fout("lac.out");

int a[1002][1002],n,m,pen,ins,ok,x,y;
queue<pair<int,int>>q;

int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)fin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]){
                q.push(make_pair(i,j));
                ok=0;
                while(q.size())
                {
                    x=q.front().first;
                    y=q.front().second;
                    q.pop();
                    a[x][y]=0;
                    if(x==1 || x==n || y==1 || y==m)ok=1;
                    if(a[x-1][y])q.push(make_pair(x-1,y));
                    if(a[x][y+1])q.push(make_pair(x,y+1));
                    if(a[x+1][y])q.push(make_pair(x+1,y));
                    if(a[x][y-1])q.push(make_pair(x,y-1));
                }
                if(ok)pen++;
                else ins++;
            }
        }
    }
    fout<<ins<<' '<<pen;
    return 0;
}
