#include <iostream>

using namespace std;

int a[101][101],viz[101];
int n,x,y,sol[101],ok,plec;

void DFS(int nod,int cont)
{
    sol[cont]=nod;
    if(cont==n)
    {
        ok=1;
        for(int i=1; i<=n; i++)
            cout<<sol[i]<<' ';
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(a[nod][i] && !viz[i])
            {
                viz[i]=1;
                DFS(i,cont+1);
                viz[i]=0;
            }

        }
    }

}

int main()
{
    cin>>n;
    for(int i=1; i<=n*(n-1)/2; i++)
    {
        cin>>x>>y;
        a[x][y]=1;
    }
    for(int i=1; i<=n && !ok; i++)
    {
        viz[i]=1;
        DFS(i,1);
        viz[i]=0;
    }
    return 0;
}
