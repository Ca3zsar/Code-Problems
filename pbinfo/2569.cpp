#include <fstream>

using namespace std;

ifstream fin("alo.in");
ofstream fout("alo.out");

int sum,E,n,nr,mi;

int main()
{
    fin>>E>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>nr>>mi;
        if(nr%10==5)
        {
            if(nr/10000==1)sum-=(mi*2);
            else sum+=mi;
        }
    }
    fout<<E+sum;
    return 0;
}
