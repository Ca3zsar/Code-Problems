#include <fstream>
#include <set>
#include <vector>
#include <utility>
using namespace std;

ifstream fin("covoare1.in");
ofstream fout("covoare1.out");

struct coord
{
    int x,y;
    int dim1,dim2;
};


set<coord,compare>q;
vector<pair<int,int>>sol;

int main()
{
    int n,m,p,x,y;
    fin>>n>>m>>p;
    q.insert(make_pair(1,1));
    while(p)
    {
        coord aux;
        int ok=1;
        fin>>x>>y;
        while(ok)
        {
            ok=0;
            aux=*q.begin();
            q.erase(q.begin());
            for(auto vec:sol)
            {
                if(!(aux.x>=vec.x && aux.x<=vec.x+vec.dim1 && aux.y>=vec.y && aux.y<=vec.y+vec.dim2))
                {
                    ok=1;
                }
            }
        }
        aux.dim1=x;
        aux.dim2=y;
        sol.push_back(aux);
        if(aux.x+x<=n)q.insert({aux.x+x,aux.y,0,0});
        if(aux.y+y<=m)q.insert({aux.x,aux.y+y,0,0});
        fout<<aux.x<<' '<<aux.y<<'\n';
        q.erase(q.begin());
        p--;
    }
    return 0;
}
