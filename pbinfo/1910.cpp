#include <iostream>

using namespace std;

int q,n,b,r;
int v[100010];

int rest()
{
    int R=0;
    v[n]=1;
    for(int i=n;i;i--)
    {
        R=(10*R+v[i])%b;
    }
    v[n]=0;
    return R;
}

int main()
{
    cin>>q;
    for(; q; q--)
    {
        cin>>n>>b>>r;
        int x=rest();
        if(n>1)
        {
            cout<<1;
            for(int i=1;i<n-1;i++)cout<<0;
            int rp=b-x;
            cout<<(rp+r)%b<<'\n';
        }else cout<<r<<'\n';
    }
    return 0;
}
