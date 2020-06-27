#include <fstream>

using namespace std;

ifstream fin("furnici.in");
ofstream fout("furnici.out");

int x,n,nr,cdiv,pdiv,l;

int getdiv()
{
    int cnt=1,c=0,k;
    while(x%2==0)
    {
        c++;
        x/=2;
    }
    if(c)cnt*=(c+1);
    k=3;
    while(k<=x)
    {
        if(k*k>x)
        {
            x=1;
            cnt*=2;
        }else{
            c=0;
            while(x%k==0)
            {
                c++;
                x/=k;
            }
            if(c)cnt*=(c+1);
            k+=2;
        }
    }
    return cnt;

}

int main()
{
    fin>>n;
    l=1;
    for(int i=1;i<=n;i++)
    {
        fin>>x;
        cdiv=getdiv();
        if(cdiv<pdiv)l++;
        else{
            if(l>=2){
                nr++;
                l=1;
            }
        }
        pdiv=cdiv;
    }
    if(l>=2)nr++;
    fout<<nr;
    return 0;
}
