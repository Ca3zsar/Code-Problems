#include <bits/stdc++.h>

using namespace std;

ifstream fin("mere.in");
ofstream fout("mere.out");

vector<int>v[1001];
int z[1001],n,sum,x,y,f[1001];

void dps(int k)
{
    int ind,maxx=0;
    sum+=z[k];
    f[k]=1;
    for(auto vec:v[k])
    {
        if(!f[vec])
        {
            if(z[vec]==maxx)
            {
                if(vec<ind)
                    ind=vec;
            }
            if(z[vec]>maxx)
            {
                maxx=z[vec];
                ind=vec;
            }
        }
    }
    if(maxx)
        dps(ind);
}

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>z[i];
    for(int i=1; i<=n-1; i++)
    {
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dps(1);
    fout<<sum;
    return 0;
}
