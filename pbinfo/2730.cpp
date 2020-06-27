#include <iostream>

using namespace std;

#include <cstring>
int SC(char s[])
{
    int c=strlen(s);
    if(c==1)
    {
        if(s[0]>='0' && s[0]<='9')return s[0]-'0';
        else return 0;
    }else{
        if(s[0]>='0' && s[0]<='9')return s[0]-'0'+SC(s+1);
        else return SC(s+1);
    }
}

int main()
{
    cout<<SC("Ana are 15 mere si 185 de pere.");
    return 0;
}
