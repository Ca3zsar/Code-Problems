#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("bits.in");
ofstream fout("bits.out");

long long unsigned Q,N,x;

int main()
{
    fin>>N>>Q;
    for(int i=1;i<=Q;i++)
    {
        fin>>x;
        if((N>>x)&1)fout<<1;
        else fout<<0;
    }

    return 0;
}
