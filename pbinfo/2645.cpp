#include <bits/stdc++.h>

using namespace std;

ifstream fin("minlex.in");
ofstream fout("minlex.out");

int k;
string cuv;
stack<char>s;

int main()
{
    cin>>k>>cuv;
    for(int i=0; i<cuv.size(); i++)
    {
        if(s.empty())
            s.push(cuv[i]);
        else
        {
            if(k)
            {
                while(k)
                {
                    if(s.size())
                    {
                        if(cuv[i]-'a'<s.top()-'a')
                        {
                            k--;
                            s.pop();
                        }
                        else
                            break;
                    }
                    else
                        break;
                }
                s.push(cuv[i]);
            }
            else
            {
                s.push(cuv[i]);
            }
        }
    }
    string c;
    c.clear();
    while(!s.empty())
    {
        c=c+s.top();
        s.pop();
    }
    for(int i=c.size()-1; i>=0; i--)
        cout<<c[i];
    return 0;
}
