#include <bits/stdc++.h>

using namespace std;

char c[256];

int main()
{
    while(cin>>c){
        cout<<c<<' ';
        for(int i=strlen(c)-1;i>=0;i--)cout<<c[i];
        cout<<' ';
    }
    return 0;
}
