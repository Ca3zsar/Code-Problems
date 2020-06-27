#include <iostream>

using namespace std;

int IncDecRec(int n)
{
    if(n<10)
    {
        if(n%2==0)return n+1;
        else return n-1;
    }
    else{
        int c=n%10;
        if(c%2==0)return (IncDecRec(n/10))*10+c+1;
        else return (IncDecRec(n/10))*10+c-1;

    }
}

int main()
{
    cout<<IncDecRec(4321);
    return 0;
}
