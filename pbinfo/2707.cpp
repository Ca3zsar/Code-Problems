#include <iostream>

using namespace std;

int a[101][101],n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i][i])
        {
            cout<<0;
            return 0;
        }
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][j]!=a[j][i] || a[i][j]>1 || a[j][i]>1 || a[i][j]<0 || a[j][i]<0)
            {
                cout<<0;
                return 0;
            }
        }
    }
    cout<<1;
    return 0;
}
