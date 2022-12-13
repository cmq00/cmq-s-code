#include <stdio.h>
#include <string.h>

int main()
{
    char buf[10] = "ABCDEF";
    char * begin = buf, * end = buf + strlen(buf) - 1;
    char t;

    while(begin < end){
        t = *begin;
        *begin ++ = *end;
        *end -- = t;
    }
    printf("%s\n",buf);

    return 0;
}
