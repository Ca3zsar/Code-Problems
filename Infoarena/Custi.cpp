#include <fstream>
using namespace std;

ifstream fin("custi.in");
ofstream fout("custi.out");

struct point
{
    int x,y;
};

int v[1001];
int nivel[1001][1001];
int mat[1001][1001];
int n;

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            fin>>mat[i][j];
            if(mat[i][j]){
                int d1,d2,d3;
                d1=nivel[i-1][j];
                d2=nivel[i][j-1];
                d3=min(d1,d2);
                if(mat[i-d3][j-d3]==1)
                {
                    nivel[i][j]=d3+1;
                    v[nivel[i][j]]++;
                }
                else
                {
                    nivel[i][j]=d3;
                    v[nivel[i][j]]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int sol=0;
        for(int j=i;j<=n;j++)
        {
            sol+=v[j];
        }
        fout<<sol<<'\n';
    }
    return 0;
}
