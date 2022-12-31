#include <bits/stdc++.h>

using namespace std;

int aaa;

int a[1004][1004];

bool IsNum(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
 
    return false;
}

double SumNumInString(char *string) {
    double sum = 0;
    int i = 0, j = 0;
 
    while (string[j] != '\0') {
        while (!IsNum(string[i])) {
            if (string[i] == '\0') {
                return sum;
            }
            i++;
        }
        j = i;
 
        while (IsNum(string[j])) {
            j++;
        }
 
        for (int k = i; k < j; ++k) {
            sum += (string[k] - '0') * (double) pow(10, j - k - 1);
        }
        i = j;
    }
 
    return sum;
}

int main()
{
    char ch;
    char s[104];
    while(~scanf("%c",&ch)){
        getchar();
        gets(s);
        int cntl = 0,dig = 0;
        for(int i = 0;i < strlen(s);++i){
            if(('a' <= s[i] && s[i] <= 'z') || 'A' <= s[i] && s[i] <= 'Z')
                cntl++;
            if('0' <= s[i] && s[i] <= '9')
                dig++;
        }
        if(ch == 'B'){
            cout << cntl << endl;
        }
        if(ch == 'C')
            cout << dig << endl;
        else{
            double data = SumNumInString(s);
            printf("%.2f\n",&data);
        }
    }
  
    return 0;
}
