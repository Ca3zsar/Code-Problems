#include <fstream>

using namespace std;
int p;
char *s;

int main()
{
    ifstream fin("parsare.in",std::ifstream::binary);
    ofstream fout("parsare.out");
    if(fin)
    {
        fin.seekg (0, fin.end);
        int length = fin.tellg();
        fin.seekg (0, fin.beg);
        s = new char[length];
        fin.read(s,length);
        int a,maxx=-100100;
        while(p<length)
        {
            while((s[p]<'0'||s[p]>'9') && s[p]!='-' && p<length)p++;
            a=0;
            int semn=1;
            if(s[p]=='-')
            {
                semn=-1;
                p++;
            }
            int ok=0;
            while(s[p]>='0'&&s[p]<='9' && p<length)
            {
                ok=1;
                a=10*a+s[p]-'0';
                p++;
            }
            if(ok){
                a=a*semn;
                if(a>maxx)maxx=a;
            }
        }
        fout<<maxx;
    }

    return 0;
}
