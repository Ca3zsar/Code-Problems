#include <iostream>

using namespace std;

long long unsigned np,p=1,c,n,k;

int main()
{
    cin>>n;
    np=n;
    k=2;
    if(n%2==0)
    {
        c=1;
        while(n%2==0){
            c*=2;
            n/=2;
        }
        c/=2;
        p*=c;
    }
    k=3;
    while(k<=n)
    {
        if(k*k>n)
        {
            p*=(n-1);
            n=1;
        }else{
            if(n%k==0)
            {
                p*=(k-1);
                c=1;
                while(n%k==0)
                {
                    c*=k;
                    n/=k;
                }
                c/=k;
                p*=c;
            }
        }
        k+=2;
    }
    cout<<p;
    return 0;
}
