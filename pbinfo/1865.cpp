#include <fstream>
#define nmax 1000001
using namespace std;

ifstream fin("summit.in");
ofstream fout("summit.out");

long long unsigned a[nmax],n;
int Caut_Bin(int st,int dr,int x)
{
    if(st>=dr)
    {
        if(a[st]!=x)return 0;
        if(a[st]==x)return st;
    }else{
        int m=(st+dr)/2;
        if(a[m]==x)return m;
        if(a[m]>x)return Caut_Bin(st,m-1,x);
        return Caut_Bin(m+1,dr,x);
    }
}
int main()
{
    int i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];
        int x=a[i];
        a[i]+=a[i-1];
        fout<<Caut_Bin(1,i,x)<<'\n';
    }
    return 0;
}
