#include <iostream>

using namespace std;

#include <bits/stdc++.h>
long long NextNumber(long long n)
{
    long long newNumber;
    int cif=0;
    int aux[64];
    while(n)
    {
        aux[++cif]=n%2;
        n/=2;
    }
    int nr1=0,nr=0;
    for(int i=1;i<=cif;i++)
    {
        while()
    }

}



int main()
{
    long long n;
    cin>>n;
    cout<<NextNumber(n);
    return 0;
}
