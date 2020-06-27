#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *urm;
};

void sortareCrescator(nod *&prim)
{
    nod *r = prim;
    int n,aux;
    n=1;
    while(r->urm!=NULL)
    {
        n++;
        r=r->urm;
    }
    for(int i=1;i<=n;i++)
    {
        r=prim;
        while(r->urm!=NULL)
        {
            if(r->info>r->urm->info)
            {
                aux=r->info;
                r->info=r->urm->info;
                r->urm->info=aux;
            }
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
