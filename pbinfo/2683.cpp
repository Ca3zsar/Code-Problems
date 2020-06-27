#include <bits/stdc++.h>

using namespace std;

int v[1010],viz[1010],n,nr,maxx;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        if(!viz[i]){
            nr++;
            viz[i]=1;
            maxx=v[i];
            for(int j=i+1;j<=n;j++)
            {
                if(!viz[j] && v[j]>maxx)
                {
                    maxx=v[j];
                    viz[j]=1;
                }
            }
        }
    }
    cout<<nr;
    return 0;
}
