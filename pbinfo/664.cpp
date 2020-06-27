#include <iostream>
#include <algorithm>
using namespace std;

int n,x;

int DetPair(int a)
{
    int pr=1;
    int k=2,ind=0;
    while(a%k==0)
    {
        a/=k;
        ind++;
    }
    pr*=(2*ind+1);
    k=3;
    while(a!=1)
    {
        if(k*k>a)
        {
            a=1;
            pr*=3;
        }else{
            ind=0;
            while(a%k==0)
            {
                a/=k;
                ind++;
            }
            pr*=(2*ind+1);
            k+=2;
        }
    }
    return pr;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        int pr=DetPair(x);
        cout<<pr<<' ';
    }
    return 0;
}
