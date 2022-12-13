#include <iostream>
using namespace std;

int main()
{
    int cur,val;
    if(cin >> cur){
        int cont = 1;
        while(cin >> val){
            if(val == cur)
                cont++;
            else{
                cout << cur <<" "<< cont << endl;
                cur = val;
                cont = 1;
            }
        }
        cout << cur << cont << endl;
    }
    return 0;
}
