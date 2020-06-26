#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

ifstream fin("biti.in");
ofstream fout("biti.out");

map<string,int>m;
int N;
int aux[(1<<20)+1];
vector<int>solutie;

void BK(int k,int nr)
{
    if(nr==(1<<N))
    {
        fout<<solutie.size()<<'\n';
        for(auto v:solutie)
            fout<<v;
        exit(0);
    }
    for(int i=0; i<=1; i++)
    {
        if(aux[(i+2*k)%(1<<N)] == 0)
        {
            if(aux[(i+2*k)%(1<<N)]==0)
            {
                aux[(i+2*k)%(1<<N)] = 1;
                solutie.push_back(i);
                BK((i+2*k)%(1<<N),nr+1);
                solutie.pop_back();
                aux[(i+2*k)%(1<<N)] = 0;
            }
        }
    }
}

int main()
{
    aux[0] = 1;
    fin>>N;
    for(int i=1; i<=N; i++)solutie.push_back(0);
    BK(0,1);
}
