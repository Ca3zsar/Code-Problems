#include <fstream>

using namespace std;

ifstream fin("subsecv.in");
ofstream fout("subsecv.out");
short fr[10001],n,minn=10001,ind;
short fr2[10001];
int x,s;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        s=(s+x%n)%n;
        if(s==0)
        {
            fout<<1<<' '<<i;
            return 0;
        }
        if(fr[s] && !fr2[s])fr2[s]=i;
        else if(!fr[s])fr[s]=i;
    }
    for(int i=1;i<n;i++)
    {
        if(fr[i] && fr2[i] && fr[i]<minn)
        {
            minn=fr[i];
            ind = i;
        }
    }
    fout<<fr[ind]+1<<' '<<fr2[ind];
    return 0;
}
