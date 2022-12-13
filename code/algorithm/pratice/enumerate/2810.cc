#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p = 0,triple[20];
    scanf("%d",&n);
    for(int i = 2;i <= n;++i){
        p = 0;
        for(int j = 2;j < n;++j){
            for(int k = j;k < n;++k){
                for(int l = k;l < n;++l){
                    if(l * l * l + j * j * j + k * k *k == i * i * i){
                        p = 1;
                        //triple[0] = j,triple[1] = k,triple[2] = l;
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                        break;
                    }
                }
                //if(p == 1)
                    //break;
            }
        
            //if(p == 1)
                //break;;
        }
        //if(p == 1)
            //continue;
    }
    return 0;
}

