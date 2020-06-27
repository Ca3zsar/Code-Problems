#include <fstream>

using namespace std;

ifstream fin("retea.in");
ofstream fout("retea.out");

int n,m,nr,v[101][101],viz[101],x,y;

void DFS(int nod,int k)
{
    viz[nod]=1;
    nr++;
    for(int i=1;i<=n;i++)
    {
        if(v[nod][i] && !viz[i] && i!=k)DFS(i,k);
    }
}

int main()
{
    fin>>n>>m;
    for(;m;m--)
    {
        fin>>x>>y;
        v[x][y]=v[y][x]=1;
    }
    DFS(2,1);
    if(nr==n-1)fout<<0<<' ';
    else fout<<1<<' ';
    nr=0;
    for(int i=1;i<=n;i++)viz[i]=0;
    for(int i=2;i<=n;i++)
    {
        DFS(1,i);
        if(nr==n-1)fout<<0<<' ';
        else fout<<1<<' ';
        nr=0;
        for(int j=1;j<=n;j++)viz[j]=0;
    }
    return 0;
}
