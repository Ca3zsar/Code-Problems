#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long unsigned n;
int p;
vector<int>v;

int main()
{
    scanf("%d%lld",&p,&n);

    for(int i=1;i<=p;i++)v.push_back(i);
    long long unsigned perm=1;
    for(long long unsigned i = 1;i<p;i++)
    {
        perm*=i;
    }
    n--;
    for(long long unsigned i=1;i<p;i++)
    {
        printf("%d ",v[n/perm]);
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==v[n/perm])
            {
                v.erase(v.begin()+j);
                break;
            }
        }
        n%=perm;
        perm/=(p-i);
    }
    printf("%d",v[0]);
    return 0;
}
