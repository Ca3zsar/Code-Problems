#include <bits/stdc++.h>

using namespace std;

ifstream fin("memory006.in");
ofstream fout("memory006.out");

queue<char>q;

long long unsigned a;
int n,secv=0;
short k,sum=0,nr;

int bin(int st,int dr)
{
    if(st==dr)return st;
    int m=(st+dr)/2;
    if(a==(1ULL<<m))return m;
    if(a<(1ULL<<m))return bin(st,m-1);
    return bin(m+1,dr);
}

int main()
{
    fin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        fin>>a;
        if((a&(a-1))==0)
        {
            //fout<<a<<' ';
            nr=bin(0,64);
            //fout<<nr<<'\n';
            q.push(nr);
            sum+=nr;
            while(sum>k)
            {
                sum-=q.front();
                q.pop();
            }
            if(sum==k)
            {
                secv++;
                sum-=q.front();
                q.pop();
            }
        }
        else
        {
            while(q.size())
                q.pop();
            sum=0;
            //cout<<a<<'\n';
        }
        //cout<<sum<<'\n';
    }
    unsigned long long x;
    //cout<<x;
    fout<<secv;
    return 0;
}
