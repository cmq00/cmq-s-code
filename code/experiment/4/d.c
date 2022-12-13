#include <stdio.h>

int age = 10;

int fun(int n)
{
    age += 2;
    n--;
    if(n)
        fun(n);
    return age;
}

int main()
{
    int age = fun(4);
    printf("%d\n",age);
    return 0;
}

