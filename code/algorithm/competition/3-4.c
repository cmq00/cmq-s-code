#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[15],n,b[15];
    srand(time(0));

    while(scanf("%d",&n) != EOF){
        int i,j,A,B;
        for(i = 0;i < n;++i)
            a[i] = 1 + rand() % 9;
        //for(i = 0;i < n;++i)
            //printf("%d ",a[i]);
        //printf("\n");

        int count = 1;
        while(count++){
            A = B = 0;
            for(i = 0;i < n;++i){
                scanf("%d",&b[i]);
                if(a[i] == b[i])
                    A++;
                }
            

            for(int num = 1;num <= 9;++num){
                int c1 = 0,c2 = 0;
                for(i = 0;i < n;++i){
                    if(a[i] == num)
                        c1++;
                    if(b[i] == num)
                        c2++;
                }

                if(c1 < c2) B += c1;
                else    B += c2;
            }

            if(A == n){
                printf("你可真是个小天才\n");
                for(i = 0;i < n;++i)
                    printf("%d ",a[i]);
                printf("\n");
                break;
            }
            else{
                printf("%dA %dB\n",A,B - A);
                if(count == 4 || count == 7)
                    printf("你这个菜逼还没猜出来\n");
            }
        }
    }
    return 0;
}

                    

                

                        

        
