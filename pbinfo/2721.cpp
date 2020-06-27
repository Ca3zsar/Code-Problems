#include <iostream>

using namespace std;


void Insert(int a[],int &n)
{
    int v[]=new int[80001];
    int cont=0;
    for(int i=0;i<n;i++,cont++)
    {
        v[cont]=a[i];
        if(a[i]%2==1)
        {
            cont++;
            v[cont]=2*a[i];
        }
    }
    n=cont;
    for(int i=0;i<cont;i++)a[i]=v[i];
}

int main()
{
    int a[200]={22,5,7,8,11};
    int n=5;
    Insert(a,n);
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    return 0;
}


