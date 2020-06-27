#include <bits/stdc++.h>

using namespace std;

ifstream fin("nivelebin.in");
ofstream fout("nivelebin.out");

int X,st,dr,n,v[1001];
int m1[1001],m2[1001];
int niv[1001],c,maxx;

void explore(int nod,int level)
{
    if(level>maxx)maxx=level;
    niv[level]++;
    if(m1[nod]!=0)explore(m1[nod],level+1);
    if(m2[nod]!=0)explore(m2[nod],level+1);
}

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>X>>st>>dr;
        v[st]=1;
        v[dr]=1;
        m1[i]=st;
        m2[i]=dr;
    }
    int nod=0;
    for(int i=1;i<=n && !nod;i++)if(!v[i])nod=i;
    explore(nod,1);
    fout<<maxx<<'\n';
    for(int i=1;i<=maxx;i++)fout<<niv[i]<<' ';
    return 0;
}
