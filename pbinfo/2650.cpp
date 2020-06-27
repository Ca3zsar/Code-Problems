#include <bits/stdc++.h>

using namespace std;

queue<int>q;
int fr[200001],n,x,nr;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(fr[x])cout<<0<<' ';
        else{
            nr=0;
            while(q.front()!=x)
            {
                fr[q.front()]++;
                nr++;
                q.pop();
            }
            nr++;
            fr[x]++;
            q.pop();
            cout<<nr<<' ';
        }
    }
    return 0;
}
