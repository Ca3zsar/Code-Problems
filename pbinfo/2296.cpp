#include <fstream>
#define maxx 1000000
using namespace std;

ifstream fin("gcd.in");
ofstream fout("gcd.out");

int cnt1[maxx+1],cnt2[maxx+1],nrm;
int n,x,d;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        if(x>nrm)nrm=x;
        cnt1[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        if(x>nrm)nrm=x;
        cnt2[x]++;
    }
    for(d=nrm;d>=1;d--)
    {
        int ok1=0,ok2=0;
        for(int i=nrm/d;i>=1;i--)
        {
            if(cnt1[d*i])
            {
                ok1=1;
                break;
            }
        }
        for(int i=nrm/d;i>=1;i--)
        {
            if(cnt2[d*i])
            {
                ok2=1;
                break;
            }
        }
        if(ok1 && ok2)
        {
            fout<<d;
            return 0;
        }
    }
    return 0;
}
