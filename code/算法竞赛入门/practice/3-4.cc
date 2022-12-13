#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int pos[100];
    int t,j = 0;
    cin >> s;
    int len = s.size();
    for(int i = 1;i < len;++i){
        if(s[i] == s[0])
            pos[j++] = i;
    }
    
    for(int i = 0;i < j;++i)
        cout << pos[i] << " " ;
    cout << endl;
    cout << j << endl;
    j--;
    while(j >= 0){
        //cout << " !" << endl;
        int i = 0;
        int k = pos[j];
        while(s[i] == s[k] && k < len){
            printf("i:%d k:%d\n",i,k);
            k++;
            i++;
        }
        if(k == len)
            {cout << len - pos[j] << endl;;break;}
        j--;
    }
    return 0;
}