#include <bits/stdc++.h>

using namespace std;

ifstream fin("subsircomunmaximal.in");
ofstream fout("subsircomunmaximal.out");

string a,b;
int v[1001][1001],n,m,cnt;

int main()
{
    fin>>a>>b;
    n=a.size();
    m=b.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])v[i+1][j+1]=v[i][j]+1;
            else v[i+1][j+1]=max(v[i][j+1],v[i+1][j]);
        }
    }
    int x=n,y=m;
    string s;
    s.resize(v[n][m]+1);
    while(x && y)
    {
        if(a[x-1]==b[y-1])
        {
            s[++cnt]=a[x-1];
            x--;
            y--;
        }else{
            if(v[x-1][y]>v[x][y-1])x--;
            else y--;
        }
    }
    for(int i=cnt;i>=1;i--)fout<<s[i];
    return 0;
}
