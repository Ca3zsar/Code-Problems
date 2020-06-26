#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("euler.in");
ofstream fout("euler.out");

int v[201][201];
vector<int>sol;
stack<int>parcurg;

int main()
{
    int n,x,y;
    fin>>n;
    while(fin>>x>>y)
    {
        v[x][y]=v[y][x]=1;
    }
    int ok;
    parcurg.push(1);
    while(parcurg.size())
    {
        ok=0;
        int t = parcurg.top();
        for(int i=1;i<=n;i++)
        {
            if(v[i][t]==1){
                v[i][t]=v[t][i]=0;
                parcurg.push(i);
                ok=1;
                break;
            }
        }
        if(ok)continue;
        parcurg.pop();
        sol.push_back(t);
    }
    fout<<sol.size()<<'\n';
    for(auto vec:sol)
    {
        fout<<vec<<' ';
    }
    return 0;
}
