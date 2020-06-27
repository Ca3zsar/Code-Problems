#include <fstream>
#include <iostream>
#define nMax 250001
using namespace std;

ifstream fin("heap.in");
ofstream fout("heap.out");

int v[250001];
int m,x,q,n;

void heap_down(int k,int nr)
{
    int St,Dr,c;
    if(2*k<=nr)
    {
        St=v[2*k];
        if(2*k+1<=nr)Dr=v[2*k+1];
        else Dr=St-1;
        if(St>Dr)c=2*k;
        else c=2*k+1;
        if(v[k]<v[c]){
            swap(v[k],v[c]);
            heap_down(c,nr);
        }
    }
}

void heap_up(int k)
{
    int t;
    if(k<=1)return;
    t=k/2;
    if(v[k]>v[t])
    {
        swap(v[k],v[t]);
        heap_up(t);
    }
}

int main()
{
    fin>>m;
    for(; m; m--)
    {
        fin>>q;
        if(q==2)
        {
            fout<<v[1]<<'\n';
            v[1]=v[n];
            n--;
            heap_down(1,n);
            //cout<<n<<'\n';
        }
        else
        {
            fin>>x;
            v[++n]=x;
            heap_up(n);
        }

    }
    return 0;
}
