#include <fstream>

using namespace std;

ifstream fin("maxsecv.in");
ofstream fout("maxsecv.out");

int nr1,nr2,n;
int cont,x;

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>x;
        if(x==1)
        {
            cont++;
        }
        else
        {
            if(cont>nr1)
            {
                nr2=nr1;
                nr1=cont;
            }
            else
            {
                if(cont>nr2)
                {
                    nr2=cont;
                }
            }
            cont=0;
        }
    }
    if(cont>nr1)
    {
        nr2=nr1;
        nr1=cont;
    }
    else
    {
        if(cont>nr2)
        {
            nr2=cont;
        }
    }
    fout<<nr1+nr2;
    return 0;
}
