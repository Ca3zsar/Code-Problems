#include <bits/stdc++.h>

using namespace std;

ifstream fin("odaoni.in");
ofstream fout("odaoni.out");

int n,np,nr;
int v[10];

int bun(int x)
{
    while(x)
    {
        if(!v[x%10])return 0;
        x/=10;
    }
    return 1;
}

int main()
{
    fin>>n;
    np=n;
    while(np)
    {
        v[np%10]++;
        np/=10;
    }
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i!=n)
            {
                nr+=bun(i);
                nr+=bun(n/i);
            }else nr+=bun(i);
        }
    }
    fout<<nr;
    return 0;
}
