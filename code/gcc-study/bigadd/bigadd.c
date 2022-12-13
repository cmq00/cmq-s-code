#include <string.h>
#include <stdio.h>

int add(char num1, char num2, int flag, char * out);

int add(char num1, char num2, int flag, char * out)
{
    char t;

    t = num1 + num2 + flag;
    if(t < 106){
        *out= t - 48;
        flag = 0;
    }
    
    else{
        *out = t - 58;
        flag = 1;
    }
    
    return flag;
}




void change(char *buf)
{
    char * begin = buf, * end = buf + strlen(buf) - 1;
    char t;

    while(begin < end){
        t = *begin;
        *begin ++ = *end;
        *end -- = t;
    }
}

int main()
{
    char num2[10] = "8912355";
    char num1[10] = "9265";
    char out[10] = {0};

    int i,flag = 0,j;
    int len = strlen(num1),len2 =  strlen(num2);

    printf("num1:%s\n", num1);
    printf("num2:%s\n", num2); 

    if(len2 < len){
	    for(i=0,j = 0; i < len2;j++, i++){
	
	        flag = add(num1[len - i - 1], num2[len2 - i - 1],flag, &out[j]);
	    }
	    for(; i < len; j++, i++){
	        flag = add(num1[len - i - 1], '0',flag, &out[j]);
	    }
    }
    else{       
	    for(i = 0,j = 0; i < len;j++, i++){
	
	        flag = add(num1[len - i - 1], num2[len2 - i - 1],flag, &out[j]);
	    }
	    for(; i < len2; j++, i++){
	        flag = add(num2[len2 - i - 1], '0',flag, &out[j]);
	    }
    }
    if(1 == flag)
        out[j] = '1';

    change(out);
    printf("%s\n", out);
    return 0;
}
