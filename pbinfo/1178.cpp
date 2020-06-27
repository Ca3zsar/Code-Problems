#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod * urm;
};

void sterge(nod * & p)
{
    nod *r= new nod;
    nod *rez= new nod;
    while(p->info%2==0)
    {
        rez=p;
        p=p->urm;
        delete rez;
    }
    r=p;
    while(r->urm!=NULL)
    {
        if(r->urm->info%2==0)
        {
            rez=r->urm;
            r->urm=rez->urm;
            delete rez;
        }
        else r=r->urm;
    }

}

int main()
{
    int n,x;
    cin>>n;
    nod *p= new nod;
    nod *z= new nod;
    z=p;
    cin>>x;
    p->info=x;
    for(int i=2; i<=n; i++)
    {
        cin>>x;
        nod *r= new nod;
        r->info=x;
        p->urm=r;
        p=p->urm;
    }
    p->urm=NULL;
    sterge(z);
    while(z!=NULL)
    {
        cout<<z->info<<' ';
        z=z->urm;
    }
    return 0;
}
