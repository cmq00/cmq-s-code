#include <bits/stdc++.h>

using namespace std;
int nx[] = {-1,0,1,0};
int ny[] = {0,1,0,-1};
int main()
{
    int fx,fy,cx,cy;
    int dx = nx[0],dy = ny[0];
    int dxx= nx[0],dyy = ny[0];
    int step = 0;
    char mp[20][20];
    for(int i = 1;i <= 10;++i)
        for(int j = 1;j <= 10;++j){
            cin >> mp[i][j];
            if(mp[i][j] == 'F')
                fx = i,fy = j;
            if(mp[i][j] == 'C')
                cx = i,cy = j;
        }
    //cout << "haha" << endl;
     /*for(int i = 1;i <= 10;++i){
        for(int j = 1;j <= 10;++j)
            cout << mp[i][j];
        cout << endl;
     }*/
    int i = 0,j = 0;
    int n = 1e5;
    while(n--){
        if(fx == cx && fy == cy)
            break;
        step++;
        //printf("step:%d\n",step); 
        int fxx = fx + dx,fyy = fy + dy;
        if(fxx <= 10 && fxx >= 1 && fyy <= 10 && fyy >= 1 && mp[fxx][fyy] != '*')
            fx = fxx,fy = fyy;
        else
            dx = nx[(i + 1) % 4],dy = ny[(i + 1) % 4],i++;
        
        int cxx = cx + dxx,cyy = cy + dyy;
        if(cxx <= 10 && cxx >= 1 &&  cyy <= 10 && cyy >= 1 && mp[cxx][cyy] != '*')  
            cx += dxx,cy += dyy;      
        else
            dxx = nx[(j + 1) % 4],dyy = ny[(j + 1) % 4],j++;
        //printf("F:(%d,%d) C:(%d,%d)\n",fx,fy,cx,cy);
    }
    //cout << n << endl;
    if(n == -1)
        printf("0\n");
    else
        printf("%d\n",step);
    return 0;
}