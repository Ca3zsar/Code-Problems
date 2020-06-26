#include <fstream>

using namespace std;

const int N=60;
char s[N],*p=s;

typedef long long int lli;

lli factor(),termen();

lli eval()
{
    lli r=termen();
    while(*p=='+' || *p=='-')
    {
        if(*p=='+')
        {
            p++;
            r+=termen();
        }
        else
        {
            p++;
            r-=termen();
        }
    }
    return r;
}

lli termen()
{
    lli r=factor();
    while(*p=='*')
    {
        p++;
        r*=factor();

    }
    return r;

}

lli factor()
{
    lli r=0;
    if(*p=='(')
    {
        p++;
        r=eval();
        p++;
    }
    else
    {
        int semn = 1;
        if(*p=='-'){
            semn=-1;
            p++;
        }

        while(*p>='0' && *p<='9')
        {
            r=r*10+*p-'0';
            p++;
        }
        r*=semn;
    }
    return r;

}



int main()
{
    scanf("%s",s);
    printf("%lld\n",eval());

    return 0;

}
