#include <set>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Gun
{
    char name[15];
    int kill,price;

    friend bool operator<(const Gun &x,const Gun &y)
    {
        if(x.kill == y.kill)
        {
            if(x.price == y.price)
            {
                return strcmp(x.name,y.name) < 0;
            }//hh

            return x.price < y.price;
        }
        return x.kill > y.kill;
    }
};


int main()
{
    set<Gun> s;
    Gun gun;
    int t,i;
    scanf("%d",&t);
    
    while(t--)
    //for(i = 0;i < t;++i) 
    {
        scanf("%s %d %d",gun.name,&gun.kill,&gun.price);
        s.insert(gun);
    }

    set<Gun>::iterator it;

    for(it = s.begin();it != s.end();it++)
    //for(i = 0;i < t;++i)
        printf("%s\n",(*it).name);

    return 0;
}