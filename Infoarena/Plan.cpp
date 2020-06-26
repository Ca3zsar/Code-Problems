#include <fstream>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
const int N=100001;

ifstream fin("plan.in");
ofstream fout("plan.out");

vector<int>dus[N];
vector<int>intors[N];
vector<vector<int>>comp;
vector<int>stiva;
vector<pair<int,int>>sol
int n,m,x,y;
int viz[N];
bool edges[300][300];

void dfs(int nod)
{
    viz[nod]=1;
    for(auto it: dus[nod])
    {
        if(viz[it])continue;
        dfs(it);
    }
    stiva.push_back(nod);
}

void dfsIntors(int nod)
{
    viz[nod]=1;
    for(auto it:intors[nod])
    {
        if(viz[it])continue;
        dfsIntors(it);
    }
    comp.back().push_back(nod);
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y;
        dus[x].push_back(y);
        edges[x][y]=1;
        intors[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!viz[i])dfs(i);
    }
    memset(viz,0,sizeof(viz));
    for(int i=stiva.size()-1;i>=0;i--)
    {
        if(!viz[stiva[i]]){
            comp.push_back(vector<int>());
            dfsIntors(stiva[i]);
        }
    }
    int nr=0;
    while(comp.size()>1)
    {

    }
    return 0;
}
