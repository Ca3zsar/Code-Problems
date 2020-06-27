#include <fstream>

using namespace std;

ifstream fin("zona3.in");
ofstream fout("zona3.out");

int v[102][102],w[102][102],n,m,t;

void setare(int x,int y,int p)
{
    v[x][y]=p;
    if(v[x-1][y]==1)
        setare(x-1,y,p);
    if(v[x][y+1]==1)
        setare(x,y+1,p);
    if(v[x+1][y]==1)
        setare(x+1,y,p);
    if(v[x][y-1]==1)
        setare(x,y-1,p);
}

void Fill(int x,int y)
{
    w[x][y]=0;
    t++;
    if(w[x-1][y])
        Fill(x-1,y);
    if(w[x][y+1])
        Fill(x,y+1);
    if(w[x+1][y])
        Fill(x+1,y);
    if(w[x][y-1])
        Fill(x,y-1);
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fin>>w[i][j];
            v[i][j]=w[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(w[i][j]==1)
            {
                Fill(i,j);
                setare(i,j,t);
            }
            t=0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            fout<<v[i][j]<<' ';
        fout<<'\n';
    }
    return 0;
}
