#include <bits/stdc++.h>

using namespace std;

ifstream fin("bucketsort.in");
ofstream fout("bucketsort.out");

vector<int>v;
int n,d,x;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        v.push_back(x);
    }
    fin>>d;
    if(!d)sort(v.begin(),v.end());
    else sort(v.rbegin(),v.rend());
    for(auto vec:v)fout<<vec<<' ';
    return 0;
}
