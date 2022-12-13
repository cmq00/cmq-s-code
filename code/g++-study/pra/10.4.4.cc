#include <queue>
#include <iostream>

using namespace std;

struct student
{
    char name[20];
    int num,score;
    friend bool operator<(const student &x,const student &y)
    {
        if(x.score == y.score)
        {
            return x.num < y.num;
        }
        return x.score < y.score;
    }
};

priority_queue <student> q;
student s;

int main()
{
    char op[10];
    while(~scanf("%s",op))
    {

    if(op[0] == 'A')
    {
        scanf("%s %d %d",s.name,&s.num,&s.score);
        q.push(s);
    }

    else
    {   
        int k;
        scanf("%d",&k);
        //if(q.top() >= k)
            //printf("Nobody\n");
       //else

            printf("%s %d %d\n",q.top().name,q.top().num,q.top().score);
    }
}
    return 0;
}
