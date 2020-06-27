#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%6==0)
    {
        cout<<n/6<<' '<<n/3<<' '<<n/2;
        return 0;
    }
    cout<<"nu exista";
    return 0;
}
