#include <fstream>

using namespace std;

ifstream fin("biarbore.in");
ofstream fout("biarbore.out");

void arbore(int ind,int p)
{
    int x;
    fin>>x;
    if(ind==1){
        if(p==1)fout<<x<<' ';
        if(p==2)
        {
            fout<<x;
            exit(0);
        }
    }
    if(x!=0)
    {
        arbore(ind+1,p);
        arbore(ind+1,p);
    }
}

int main()
{
    int x;
    fin>>x;
    arbore(1,1);
    arbore(1,2);
    return 0;
}
