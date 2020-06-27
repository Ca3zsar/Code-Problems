#include <bits/stdc++.h>

using namespace std;

map<string,int>m;
int n,maxx;
string nume;

int main()
{
    cin>>n;
    for(;n;n--)
    {
        cin>>nume;
        m[nume]++;
    }
    for(auto v:m)
    {
        if(v.second>maxx)
        {
            nume=v.first;
            maxx=v.second;
        }
    }
    cout<<nume<<' '<<maxx;
    return 0;
}
