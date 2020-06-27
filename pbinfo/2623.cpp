#include <bits/stdc++.h>

using namespace std;

int n,x,minn=1000001,maxx,v[100001],s[100001];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]>=maxx)
        {
            maxx=v[i];
            s[i]=1;
        }
    }
    for(int i=n;i>=2;i--)
    {
        if(v[i]<=minn )
        {
            minn=v[i];
            if(s[i] && i!=n)x++;
        }
    }
    cout<<x;
    return 0;
}
//GRESIT
