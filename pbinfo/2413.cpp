#include <bits/stdc++.h>

using namespace std;

ifstream fin("reteta1.in");
ofstream fout("reteta1.out");

int n,m,c[21],sr[21],sp[21];
vector

void bifare(int k,int x,double &sum)
{
    for(){
        sum+=x*()
    }
}

void BK(int k,double &sum)
{
    for(int i=1;i<=m;i++)
    {
        if(!sr[i])
        {
            sr[i]=1;
            bifare(k,1);
        }
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>tp>>q;
        v[i].push_back(tp);
        for(;q;q--)
        {
            fin>>x;
            v[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++)fin>>c[i];
    double sum=0;
    BK(1,sum);
    fout<<sum;
    return 0;
}
