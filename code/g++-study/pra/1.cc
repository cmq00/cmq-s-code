#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int i,n;
    for(i = 0;i < 5;++i){
        scanf("%d",&n);
        v.push_back(n);
    }

    v.unique();

    vector<int>::iterator p;

    for(p = v.begin();p != v.end();++p)
        cout << *p << " ";
    cout << endl;
    return 0;
}
