#include <iostream>
#include <map>

using namespace std;

struct Student
{
    struct Info
    {
        int id;
        char name[20];
    };
    int score;
    Info info;
};

typedef multimap<int,Student::Info> map_std;

using namespace std;

int main()
{
    map_std mp;
    Student st;
    char cmd[20];

    while(~scanf("%s",cmd))
    {
        if(cmd[0] == 'A')
        {
            scanf("%s %d %d",st.info.name,&st.info.id,&st.score);
            mp.insert(map_std::value_type(st.score,st.info));
        }

        else
        {
            int score;
            scanf("%d",&score);
            map_std::iterator it;

            it = mp.lower_bound(score);

            if(it != mp.begin())
            {
                --it;
                score =  it->first;
                map_std::iterator maxit = it;
                int maxid = it -> second.id;
                for(;it != mp.begin() && it -> first == score;--it)
                {
                    if(it -> second.id > maxid)
                    {
                        maxid = it -> second.id;
                        maxit = it;
                    }
                }

                if(it -> first == score)
                {
                    if(it -> second.id > maxid)
                    {   
                        maxit = it;
                        maxid = it -> second.id;
                    }
                }
            
               printf("%s %d %d\n",maxit -> second.name,maxit -> second.id,maxit -> first);

            }
            else
                printf("nobody\n");
            
        }
    }
    return 0;
}
