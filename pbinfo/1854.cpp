#include <fstream>

using namespace std;

ifstream fin("complet.in");
ofstream fout("complet.out");

int v[100001],n,q,op,k,s[100001];

int sum(int nod)
{
    if(2*nod<=n)s[nod]+=sum(2*nod);
    if(2*nod+1<=n)s[nod]+=sum(2*nod+1);
    if(!s[nod])return v[nod];
    return s[nod];
}

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)fin>>v[i];
    fin>>q;
    s[1]=sum(1);
    for(int i=1;i<=q;i++)
    {
        fin>>op>>k;
        if(op==1)fout<<v[k/2]<<'\n';
        else{
            fout<<s[k]<<'\n';
        }
    }
    return 0;
}
