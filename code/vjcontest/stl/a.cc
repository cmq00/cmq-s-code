#include <deque>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
    queue<char>q;
    char a[5];
    while(~scanf("%s",a))
    {
        if(a[0] == 'I')
        {
            char c;
            scanf(" %c",&c);
            q.push(c);
        }
        else
        {
            char p = q.front();
            q.pop();
            printf("%c\n",p);
        }
    }
    return 0;
}