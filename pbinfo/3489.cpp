#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <functional>
#include <tuple>
using namespace std;

int C,P;
struct point{
    point(double x,double y):x(x),y(y){};
    double x,y;
};


vector<point>vp;
double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    scanf("%d",&P);
    double x,y;
    for(int i=0;i<P;i++)
    {
        scanf("%lf%lf",&x,&y);
        vp.push_back(point(x,y));
    }
    scanf("%d",&C);
    double r;
    for(int i=0;i<C;i++)
    {
        scanf("%lf%lf%lf",&x,&y,&r);
        int nr=0;
        for(auto pt:vp)
        {
            if(distance(x,y,pt.x,pt.y)<=r)nr++;
        }
        printf("%d\n",nr);
    }
    return 0;
}
