#include <iostream>

using namespace std;

long long int x,b,n;

int main()
{
    cin>>n;
    for(;n;n--)
    {
        cin>>x>>b;
        x>>=b;
        (x&(1<<0))?cout<<1:cout<<0;
    }
    return 0;
}
