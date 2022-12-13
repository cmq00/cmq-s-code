#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10);
    int i;
    for( i = 0;i < 10;++i)
        //v.push_back(i);
        cin >> v[i];
   
    vector<int>::iterator j;
    for(j = v.begin();j < v.end();++j)
        cout << *j << " ";
    cout << endl;
    
    for(j = v.begin();j < v.end();++j)
        cout << *j << " ";
    cout << endl;
    
    j = v.begin();
    while(j < v.end()){
        cout << *j << " ";
        j += 2;
    }
    cout << endl;

    return 0;
}
