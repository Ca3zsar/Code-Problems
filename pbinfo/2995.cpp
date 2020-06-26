#include <iostream>
#include <cmath>
using namespace std;

void inserare(int &n)
{
    int aux[10];
    int cif=0;
    while(n)
    {
        aux[++cif]=n%10;
        n/=10;
    }
    n=0;
    for(int i=cif;i>=2;i--)
    {
        cout<<n<<'\n';
        n=n*10+aux[i];
        n=n*10+abs(aux[i]-aux[i-1]);
    }
    n=n*10+aux[1];
}

int main()
{
    int n;
    cin>>n;
    inserare(n);
    cout<<n;
    return 0;
}
