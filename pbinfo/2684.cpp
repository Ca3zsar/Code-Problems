#include <bits/stdc++.h>

using namespace std;

ifstream fin("ssc.in");

multiset<int>ms;
multiset<int>::iterator it;
int v[100001];
int n;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)fin>>v[i];
    for(int i=1;i<=n;i++)
    {
        if(!ms.size())ms.insert(v[i]);
        else{
            it=ms.begin();
            if(v[i]<*it)
            {
                ms.insert(v[i]);
            }else{
                it=ms.upper_bound(v[i]);
                --it;
                ms.erase(it);
                ms.insert(v[i]);
            }
        }
    }
    cout<<ms.size();
    return 0;
}
