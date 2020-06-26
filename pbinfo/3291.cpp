#include <iostream>

using namespace std;

const int N = 30000000;
int v[N/32+1];

int main()
{
    int x;
    while(cin>>x && x!=0)
    {
        if(v[x/32] & (1<<(x%32)))
        {
            printf("%d",x);
            return 0;
        }
        else v[x/32] |= (1<<(x%32));
    }
    return 0;
}
