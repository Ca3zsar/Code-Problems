#include <fstream>

using namespace std;

ifstream fin("preordine1.in");
ofstream fout("preordine1.out");

void arbore(int ind,int p)
{
    int x;
    fin>>x;
    if(x!=0)
    {
        fout<<x<<' ';
        arbore(ind+1,p);
        arbore(ind+1,p);
    }
}

int main()
{
    int x;
    fin>>x;
    arbore(1,1);
    return 0;
}
