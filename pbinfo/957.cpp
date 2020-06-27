#include <fstream>

using namespace std;

ifstream fin("zana.in");
ofstream fout("zana.out");

int v[182][182],n,m,k,x,y,maxx,apar;

void bord()
{
    for(int i=0;i<=n+1;i++)v[i][0]=v[i][m+1]=-1;
    for(int i=0;i<=m+1;i++)v[0][i]=v[n+1][i]=-1;
}

void Fill(int a,int b)
{
    if(v[a][b])
    {
        if(v[a][b]==maxx)apar++;
        if(v[a][b]>maxx)
        {
            maxx=v[a][b];
            apar=1;
        }
        v[a][b]=-1;
        return ;
    }
    v[a][b]=-1;
    if(v[a-1][b]!=-1)Fill(a-1,b);
    if(v[a][b+1]!=-1)Fill(a,b+1);
    if(v[a+1][b]!=-1)Fill(a+1,b);
    if(v[a][b-1]!=-1)Fill(a,b-1);
}

int main()
{
    fin>>n>>m>>k;
    bord();
    for(;k;k--)
    {
        fin>>x>>y;
        v[x][y]++;
    }
    Fill(1,1);
    fout<<maxx<<'\n'<<apar;
    return 0;
}
