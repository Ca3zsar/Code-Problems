#include <bits/stdc++.h>

using namespace std;
long long unsigned n;

int main()
{
    int aux[2][2];
    int A[2][2]={0,1,1,1};
    int Aprim[2][2]={1,0,0,1};
    scanf("%lld",&n);
    n-=1;
    while(n)
    {
        if(n%2==1)
        {
            aux[0][0]=Aprim[0][0]*A[0][0]%9+A[1][0]*Aprim[0][1]%9;
            aux[0][1]=Aprim[0][0]*A[0][1]%9+Aprim[0][1]*A[1][1]%9;
            aux[1][0]=aux[0][1]%9;
            aux[1][1]=Aprim[1][0]*A[0][1]%9+Aprim[1][1]*A[1][1]%9;
            for(int n=0;n<=1;n++)
                for(int j=0;j<=1;j++)Aprim[n][j]=aux[n][j]%9;
            n--;
        }else{
            aux[0][0]=A[0][0]*A[0][0]%9+A[0][1]*A[1][0]%9;
            aux[0][1]=A[0][0]*A[0][1]%9+A[0][1]*A[1][1]%9;
            aux[1][0]=aux[0][1]%9;
            aux[1][1]=A[1][0]*A[0][1]%9+A[1][1]*A[1][1]%9;
            for(int n=0;n<=1;n++)
                for(int j=0;j<=1;j++)A[n][j]=aux[n][j]%9;
            n/=2;
        }
    }
    printf("%d",Aprim[1][1]%9);
    return 0;

}
