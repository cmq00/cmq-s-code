#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>

using namespace std;
#define me(x,y) memset(x,y,sizeof x)
#define MIN(x,y) x < y ? x : y
#define MAX(x,y) x > y ? x : y

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5+10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-09;
const double PI = acos(-1.0);

int main(){
    int t,ca=1;cin>>t;
    while(t--){
        double r,h,x0,y0,z0,vx,vy,vz;
        scanf("%lf%lf",&r,&h);
        scanf("%lf%lf%lf",&x0,&y0,&z0);
        scanf("%lf%lf%lf",&vx,&vy,&vz);
        double a=vx*vx*h*h+vy*vy*h*h-vz*vz*r*r;
        double b=2*x0*vx*h*h+2*y0*vy*h*h+2*h*vz*r*r-2*z0*vz*r*r;
        double c=x0*x0*h*h+y0*y0*h*h-r*r*h*h+2*h*z0*r*r-z0*z0*r*r;
        double x1=(-b+sqrt(b*b-4*a*c))/(2*a);
        double x2=(-b-sqrt(b*b-4*a*c))/(2*a);
//        printf("%lf %lf %lf\n",a,b,c);
//        printf("%lf %lf\n",x1,x2);
        if(x1>x2) swap(x1,x2);
        printf("Case %d: ",ca++);
        if(x1 < 0) printf("%.10lf\n",x2);
        else{
            double z1=z0+vz*x1;
            if(z1<0 || z1>h) printf("%.10lf\n",x2);
            else printf("%.10lf\n",x1);
        }
    }
    return 0;
}

/*
 
*/