#include <map>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n,m,i;
    while(~scanf("%d %d",&n,&m))
    {
        map<string,int> list;
        map<string,int>::iterator it;
        char listname[20];

        while(n--)
        {
            scanf("%s",listname);
            list.insert(pair<string,int>(listname,1));
        }

        char name[m][20];
        
        for(i = 0;i < m;++i)
            scanf("%s",name[i]);
        
        for(i = 0;i < m;++i)
        {
            it = list.find(name[i]);
            if(it != list.end())
                printf("yes\n");
            else
                printf("no\n");
        }

    }
    return 0;
}
