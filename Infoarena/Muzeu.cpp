#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("muzeu.in");
ofstream fout("muzeu.out");

struct coord
{
    int x,y;
};

vector<coord>v;

int dist[251][251];
char mat[251][251];
int n;
queue<coord>q;

void visit()
{
    coord aux;
    while(q.size())
    {
        aux=q.front();
        q.pop();
        if(dist[aux.x-1][aux.y] == 0 && mat[aux.x-1][aux.y]=='.' && aux.x-1>0)
        {
            q.push({aux.x-1,aux.y});
            dist[aux.x-1][aux.y]=dist[aux.x][aux.y]+1;
        }

        if(dist[aux.x+1][aux.y] ==0 && mat[aux.x+1][aux.y]=='.' && aux.x<n)
        {
            q.push({aux.x+1,aux.y});
            dist[aux.x+1][aux.y]=dist[aux.x][aux.y]+1;
        }

        if(dist[aux.x][aux.y+1] ==0 && mat[aux.x][aux.y+1]=='.' && aux.y<n)
        {
            q.push({aux.x,aux.y+1});
            dist[aux.x][aux.y+1]=dist[aux.x][aux.y]+1;
        }

        if(dist[aux.x][aux.y-1] ==0 && mat[aux.x][aux.y-1]=='.' && aux.y>1)
        {
            q.push({aux.x,aux.y-1});
            dist[aux.x][aux.y-1]=dist[aux.x][aux.y]+1;
        }

    }
}

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            fin>>mat[i][j];
            if(mat[i][j]=='P')
            {
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    visit();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j]==0 && mat[i][j]=='.')dist[i][j]=-1;
            else if(dist[i][j]==0 && mat[i][j]=='#')dist[i][j]=-2;
            fout<<dist[i][j]<<' ';
        }
        fout<<'\n';
    }
    return 0;
}
