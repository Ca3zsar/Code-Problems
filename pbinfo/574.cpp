#include <iostream>

using namespace std;

int n,power;
int p3[1000];

int main()
{
    cin>>n;
    power=n*(n-1)/2;
    p3[++p3[0]]=1;
    for(int i=1;i<=power;i++)
    {
        int T=0;
       for(int j=1;j<=p3[0];j++)
       {
           T+=(p3[j]*3);
           p3[j]=T%10;
           T/=10;
       }
       while(T)
       {
           p3[++p3[0]]=T%10;
           T/=10;
       }
    }
    for(int i=p3[0];i>=1;i--)cout<<p3[i];
    return 0;
}
