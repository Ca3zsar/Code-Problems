#include <fstream>

using namespace std;

ifstream fin("detdrum3.in");
ofstream fout("detdrum3.out");

int n,val[101],dad[101],par[101],sc,pos[101],cont,sol[101],sum,maxx;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>dad[i];
        par[dad[i]]++;
    }
    for(int i=1;i<=n;i++)fin>>val[i];
    for(int i=1;i<=n;i++)
    {
        if(!par[i])
        {
            sc=0;
            sum=0;
            int temp=i;
            while(temp)
            {
                sum+=val[temp];
                pos[++sc]=temp;
                temp=dad[temp];
            }
            if(sum>maxx)
            {
                maxx=sum;
                cont=sc;
                for(int j=1;j<=cont;j++)sol[j]=pos[j];
            }
        }
    }
    fout<<maxx<<'\n';
    for(int i=cont;i>=1;i--)fout<<sol[i]<<' ';
    return 0;
}
