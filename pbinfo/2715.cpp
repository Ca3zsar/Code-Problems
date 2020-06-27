#include <iostream>
#include <cstring>
using namespace std;

char c;
int ok;
int main()
{
    while(cin.get(c))
    {
        if(c>='a' && c<='z')
        {
            c=char('a'+(c-'a'+13)%26);
        }
        if(c>='A' && c<='Z')
        {
            c=char('A'+(c-'A'+13)%26);
        }
        cout<<c;

    }
    return 0;
}
