#include <bits/stdc++.h>

using namespace std;

ifstream fin("cerc3.in");
ofstream fout("cerc3.out");

vector<pair<int,int>>v;
int n,x,r;
int g[400],maxx,maxsir;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>r;
        v.push_back(make_pair(x,r));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i].first-v[j].first>v[j].second+v[i].second)
            {
                if(g[j]+1>maxx)maxx=g[j]+1;
            }
        }
        if(maxx)g[i]=maxx;
        maxx=0;
        if(g[i]>maxsir)maxsir=g[i];
    }
    fout<<maxsir+1;
    return 0;
}
