#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int N=100001;

vector<int>dus[N];
vector<int>intors[N];
vector<vector<int>>comp;
vector<int>stiva;
int n,m,x,y;
int viz[N];

const int b=32000;

struct parser{
    char *B,*E,*p;
    parser(){
        B= new char[b+10];
        E=B+b;
        Load();
    }
    parser &operator>>(int &x)
    {
        while((*p<'0' || *p>'9')&& *p!='-')Next();
        int semn=1;
        if(*p=='-')
        {
            semn=-1;
            Next();
        }
        x=0;
        while(*p>='0' && *p<='9')
        {
            x=x*10+*p-'0';
            Next();
        }
        x*=semn;
        return *this;
    }
    void Load()
    {
        p=B;
        memset(B,0,b);
        fread(B,1,b,stdin);
    }
    void Next()
    {
        p++;
        if(E==p)Load();
    }

};

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

bool first_el(const vector<int>&v1,const vector<int>&v2)
{
    return v1[0]<v2[0];
}

int main()
{
    freopen("retele.in","r",stdin);
    freopen("retele.out","w",stdout);
    parser fin;
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y;
        dus[x].push_back(y);
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
    for(unsigned i=0;i<comp.size();i++)
    {
        sort(comp[i].begin(),comp[i].end());
    }
    sort(comp.begin(),comp.end(),first_el);
    printf("%d\n",comp.size());
    for(auto vec:comp){
        printf("%d ",vec.size());
        for(auto el:vec)printf("%d ",el);
        printf("\n");
    }
    return 0;
}
