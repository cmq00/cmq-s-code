#include <bits/stdc++.h>

using namespace std;

int main()
{
    int win[62510],w,l;
    char ch;
    w = l  = 0;
    for(int i = 0;cin >> ch && ch != 'E';++i){
        if(ch == 'W')   win[i] = 1;
        else if(ch == 'L')  win[i] = 2;
    }
    for(int i = 0;1;++i){
        if(win[i] == 1) w++;
        else if(win[i] == 2) l++;
        if(win[i] == 0){
              cout << w << ":" << l << endl;
              break;
        }
        else if((w >= 11 || l >= 11) && (w - l >= 2 || l - w >= 2)){
            cout << w << ":" << l << endl;
            w = l = 0;
        }
    }
    w = l = 0;
    cout << endl;
   for(int i = 0;1;++i){
        if(win[i] == 1) w++;
        else if(win[i] == 2) l++;
        if(win[i] == 0){
              cout << w << ":" << l << endl;
              break;
        }
        else if((w >= 21 || l >= 21) && (w - l >= 2 || l - w >= 2)){
            cout << w << ":" << l << endl;
            w = l = 0;
        }
    }
    return 0;
}