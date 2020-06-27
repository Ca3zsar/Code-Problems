#include <fstream>

using namespace std;

ifstream fin("succesor.in");
ofstream fout("succesor.out");

void Succesor(int a[],int n,int k)
{
    for(int i=k,x=1;i>=1;i--,x++)
    {
        a[i]++;
        if(a[i]>n-x+1)a[i]=0;
        else{
            for(int j=i+1;j<=k;j++)a[j]=a[j-1]+1;
            return ;
        }
    }
}

int main()
{
    int n,a[30001],k;
    fin>>n>>k;
    for(int i=1;i<=n;i++)fin>>a[i];
    Succesor(a,n,k);
    for(int i=1;i<=k;i++)fout<<a[i]<<' ';
    return 0;
}
