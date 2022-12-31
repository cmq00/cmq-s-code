#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int start;
    int key;
}id[4];

int a[1004];

int BlockSearch(int key,int a[],int n)
{
    int i = 0,j;
    while(i <= 3 && key > id[i].key){
        i++;
    }
    if(i > 3)
        return 0;
    if(i != 3){
        for(j = id[i].start;j < id[i].start + n / 3;j++){
            if(a[j] == key)
                return j;
        }
    }
    for(j = id[i].start;j <= n;++j){
        if(a[j] == key)
            return j;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> a[i];
    }
    int key;
    int i = 1,j = 1,k;
    cin >> key;

    for(i = 1;i <= 2;++i){
        id[i].start = j;
        j += n / 3;
        id[i].key = a[j - 1];
    }
    id[3].start = j;
    id[3].key = a[n];
    int pos = BlockSearch(key,a,n);
    cout << pos;
    return 0;
}