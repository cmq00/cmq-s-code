#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    char ch;
    char code[N];
    int cont = 0;
    while(~scanf("%s",code)){
        int len = strlen(code);
        for(int i = 0;i < len;++i){
            if(code[i] == ':' && code[i + 1] == 'w')
                cont++;
        }
    }
    cout << cont << endl;
    return 0;
}