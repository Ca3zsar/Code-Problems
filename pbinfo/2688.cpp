#include <iostream>

using namespace std;

int a[100001],b[100001],c[100001];
int n,minn=100000001;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    int i=1,j=1,k=1;
    while(i<=n && j<=n && k<=n)
    {
        if(a[i]==b[j] && b[j]==c[k])
        {
            cout<<a[i];
            return 0;
        }
        if(a[i] <= b[j] && a[i]<= c[k])i++;
        else if(b[j] <= a[i] && b[j] <= c[k])j++;
        else if(c[k] <= a[i] && c[k] <= b[j])k++;
    }
    cout<<-1;
    return 0;
}
