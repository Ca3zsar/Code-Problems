#include <bits/stdc++.h>
#define pereche pair<int,int>
using namespace std;

ifstream fin("catun.in");
ofstream fout("catun.out");
const int nMax=36010;
const int INF=1<<30;

vector<pereche>drumuri[nMax];
priority_queue<tuple<int,int,int>>Coada;

int to,from,cost;
int nrAsezari,nrDrumuri,nrFort;
int dist[nMax],indFort[nMax],Closest[nMax];

bitset<nMax>vizitat;

void Citire()
{
    fin>>nrAsezari>>nrDrumuri>>nrFort;
    for(int i=1; i<=nrAsezari; i++)
        dist[i]=Closest[i]=INF;
    for(int i=1; i<=nrFort; i++)
    {
        int x;
        fin>>x;
        dist[x]=0;
        Coada.push(make_tuple(0,-x,x));
    }
    for(int i=1; i<=nrDrumuri; i++)
    {
        fin>>from>>to>>cost;
        drumuri[to].push_back({from,cost});
        drumuri[from].push_back({to,cost});
    }
}


void Determinare()
{

    while(Coada.size())
    {
        int CurrentNod,FromNod,CurrentCost;
        tie(CurrentCost,FromNod,CurrentNod)=Coada.top();
        Coada.pop();
        FromNod *= -1;
        CurrentCost *= -1;
        if(vizitat[CurrentNod])
            continue;
        vizitat[CurrentNod]=true;
        Closest[CurrentNod]=FromNod;
        for(auto NextPlace : drumuri[CurrentNod])
        {
            if(make_pair(CurrentCost+NextPlace.second,FromNod)<
               make_pair(dist[NextPlace.first],Closest[NextPlace.first]))
             {
                dist[NextPlace.first]=CurrentCost+NextPlace.second;
                Closest[NextPlace.first]=FromNod;
                Coada.push(make_tuple(-dist[NextPlace.first],-FromNod,NextPlace.first));

            }
        }
    }
}


void Afisare()
{
    for(int i=1; i<=nrAsezari; i++)
    {
        if(Closest[i]==INF||Closest[i]==i)Closest[i]=0;
        fout<<Closest[i]<<' ';
    }
}

int main()
{
    Citire();
    Determinare();
    Afisare();
    return 0;
}
