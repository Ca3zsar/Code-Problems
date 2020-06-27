#include <iostream>
#include <cmath>
using namespace std;

long long unsigned v[10002],n,k,s;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=2;i<=k;i++)
    {
        n--;
        for(int j=1;j<=n;j++)v[j]=2*min(v[j],v[j+1]);
    }
    for(int i=1;i<=n;i++)s+=v[i];
    cout<<s;
    return 0;
}
