#include <bits/stdc++.h>
using namespace std;

ifstream fin("sclmprime.in");
ofstream fout("sclmprime.out");

int v[1010],n,cnt,x,s[1010],sol[1010],maxx,ind=1,minn=1000010;
bool pr[1000010];

void Eratostene()
{
	pr[1]=1;
	pr[0]=1;
	for(int i=4;i<=1000000;i+=2)pr[i]=1;
	for(int i=3;i*i<=1000000;i+=2)
	{
		if(!pr[i])
		{
			for(int j=3*i;j<=1000000;j+=(2*i))pr[j]=1;
		}
	}
}

 int main()
 {
 	Eratostene();
 	fin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		fin>>x;
 		if(!pr[x])v[++cnt]=x;
 	}
 	s[cnt]=1;
 	for(int i=cnt-1;i>=1;i--)
 	{
 		maxx=1;
 		for(int j=i+1;j<=cnt;j++)
 		{
 			if(v[i]<=v[j]){
 				if(s[j]+1>maxx)maxx=s[j]+1;
 			}
 		}
 		s[i]=maxx;
 	}
 	maxx=0;
 	//for(int i=1;i<=cnt;i++)cout<<v[i]<<' ';
 	for(int i=1;i<=cnt;i++)if(s[i]>maxx)maxx=s[i];
 	fout<<maxx<<'\n';
 	while(maxx)
    {
        int k=maxx,kind;
        minn=1000010;
        for(int i=ind;i<=cnt;i++)
        {
            if(v[i]<minn && s[i]==k && v[ind-1]<=v[i])
            {
                kind=i;
                minn=v[i];
            }
        }
        fout<<v[kind]<<' ';
        ind=kind+1;
        maxx--;
    }
 	return 0;
 }
