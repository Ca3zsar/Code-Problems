#include <bits/stdc++.h>

using namespace std;

ifstream fin("flici.in");
ofstream fout("flici.out");

long long unsigned sum;
int n,x;
vector<int>v1,v2;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        v1.push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<n;i++)
    {
        sum+=abs(v1[i]-v2[i]);
    }
    fout<<sum;
    return 0;
}
