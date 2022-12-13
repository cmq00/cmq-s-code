#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<string,char> mp;
    int n,m;
    scanf("%d %d",&n,&m);

    while(n--)
    {
        char name[20];
        char c;
        scanf("%s %c",name,&c);
        mp[name] = c;
    }

    while(m--)
    {
        char name1[20],name2[20];
        scanf("%s %s",name1,name2);
        
        if(mp[name1] == mp[name2])
            printf("End in a draw!\n");
        else{
        
            if(mp[name1] == 'T')
            {
                if(mp[name2] == 'Z')
                    printf("XiaoM Wins!\n");
                else 
                    printf("TianT Wins!\n");
            }
            if(mp[name1] == 'Z')
            {
                if(mp[name2] == 'P')
                    printf("XiaoM Wins!\n");
                else
                    printf("TianT Wins!\n");
            }
            if(mp[name1] == 'P')
            {
                if(mp[name2] == 'T')
                    printf("XiaoM Wins!\n");
                else
                    printf("TianT Wins!\n");
            }
        }
    }
    return 0;
}
                