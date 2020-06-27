#include <iostream>

using namespace std;

long long unsigned sum(long long unsigned x)
{
    long long unsigned s=0;
    while(x)
    {
        s+=(x%10);
        x/=10;
    }
    return s;
}

int main()
{
    long long unsigned n,k;
    long long unsigned s;
    cin>>n>>k;
    s=(long long unsigned)(sum(n)*k)%9;
    if(n>=100)n%=1000;
    if(n<=100 && n>=10 && k>=2)n=n%10*100+n;
    if(n<10 && k>=3)n=n*100+n*10+n;
    if(n<10 && k>=2)n=n*10+n;
    n%=8;

    cout<<(9*n-8*s+72)%72;
    return 0;
}
