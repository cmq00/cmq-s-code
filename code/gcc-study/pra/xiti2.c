#include <stdio.h>

int main()
{
    char c;
    int eng_char = 0,space_char = 0,digit_char = 0,other_char = 0;
    while((c = getchar()) != '\n'){
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
        eng_char++;
    }
    else if(c == ' '){
        space_char++;
    }
    else if(c >= '0' && c <= '9'){
        digit_char++;
    }
    else
    {
        other_char++;
    }
}
    printf("%d\n%d\n%d\n%d\n",eng_char,digit_char,space_char,other_char);
    return 0;
}
