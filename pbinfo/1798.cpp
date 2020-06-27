#include <iostream>

using namespace std;

int total,n;

int urc(int r)
{
    if(!r)return 1;
    if(r==1)return urc(0);
    if(r>=2)return urc(r-1)+urc(r-2);
}

int main()
{
    cin>>n;
    cout<<urc(n);
    return 0;
}
