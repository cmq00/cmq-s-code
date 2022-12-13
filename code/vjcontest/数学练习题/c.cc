#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int main()
{
   string a;
   cin >> a;
   int flag = 0;
   if(a.size() < 3){
       sort(a.begin(),a.end());
       if(stoi(a) % 8 == 0)
            flag = 1;
       while(next_permutation(a.begin(),a.end())){
           if(stoi(a) % 8 == 0)
                flag = 1;
       }
       if(flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
   }
   else{
       int cont[10] = {0};
       int len = a.size();
       for(int i = 0;i < len;++i)
            cont[a[i] - '0']++;
        for(int i = 1;i <= 9;++i){
            if(cont[i]){
                cont[i]--;
                for(int j = 1;j <= 9;++j){
                    if(cont[j]){
                        cont[j]--;
                        for(int k = 1;k <= 9;++k){
                            if(cont[k]){
                                if((i * 100 + j * 10 + k) % 8 == 0)
                                    flag = 1;
                            }
                        }cont[j]++;
                    }
                }cont[i]++;
            }
        }
       if(flag == 1)
            printf("Yes\n");
        else
            printf("No\n");
   }
   return 0;

}