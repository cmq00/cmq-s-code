#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,i;
    double b[6] = {0.8,0.9,1.0,1.1,1.2};
    scanf("%d",&t);
    char name[1000];
    double score[6];

    while(t--){
        double sum = 0;
        scanf("%s",name);
        for(i = 0;i < 5;++i){
            scanf("%lf",&score[i]);
            sum += score[i] * b[i];
        }
        double aver = sum / 5.0;
        printf("%.2lf\n",aver);
    }
    return 0;
}
        
