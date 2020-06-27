#include <bits/stdc++.h>

using namespace std;

int n,x,minn=2000000001;
map<int,int>m;

const int b=32000;
struct parser{
   char *B,*E,*p;
   parser()
   {
       B=new char[b+10];
       E=B+b;
       Load();
   }
   parser &operator>>(int &x)
   {
       while(*p<'0' || *p>'9')Next();
       x=0;
       while(*p>='0' && *p<='9')
       {
           x=x*10+*p-'0';
           Next();
       }
       return *this;
   }
   void Load()
   {
       p=B;
       memset(B,0,b);
       fread(B,1,b,stdin);
   }
   void Next()
   {
       p++;
       if(p==E)Load();
   }
};

int main()
{
    parser fin;
    fin>>n;
    for(;n;n--)
    {
        fin>>x;
        m[x]++;
        if(m[x]==1 && x<minn)minn=x;
    }
    if(m[minn]==1)cout<<minn;
    else{
    for(auto const& x:m)
    {
        if(x.second==1)
        {
            cout<<x.first;
            return 0;
        }
    }
    }
    return 0;
}
