#include <iostream>
#include <climits>
using namespace std;

long long unsigned maxx=ULLONG_MAX,rez,put,x,y,c,n,m;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        rez+=x;
        put+=y;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        if(x>=rez && y>=put && c<maxx)maxx=c;
    }
    if(maxx!=ULLONG_MAX)cout<<maxx;
    else cout<<-1;
    return 0;
}
