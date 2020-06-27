#include <fstream>

using namespace std;

ifstream fin("ghiozdan.in");
ofstream fout("ghiozdan.out");

int d,k,t,difmax,pred,x;

int main()
{
    fin>>d>>k>>t;
    for(int i=1;i<=k;i++)
    {
        fin>>x;
        if(x-pred>difmax)difmax=x-pred;
        pred=x;
    }
    if(d-pred>difmax)difmax=d-pred;
    if(t>=difmax)fout<<0;
    else{
        if(!t)fout<<difmax;
        else{
            fout<<difmax-t;
        }
    }
    return 0;
}
