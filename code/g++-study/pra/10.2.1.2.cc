#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector<int> >v(3);

    int len = v.size();
    printf("%d\n",len);

    for(int i = 0;i < v.size();++i)
        for(int j = 0;j < 5;++j)
            v[i].push_back(j);

    for(int i = 0;i < v.size();++i){
        for(int j = 0;j < v[i].size();++j)
            cout << v[i][j] << " ";
    cout << endl;}

    return 0;
}
