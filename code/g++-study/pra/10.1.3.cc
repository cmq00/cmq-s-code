#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a[10] = {2,5,32,34,12,123,90};
    vector<int> v;

    for(int i = 1;i <= 4;i++)
        v.push_back(i);

    vector<int>::iterator p;

    p = find(v.begin(),v.end(),3);
    if(p != v.end())
        cout << *p << endl;
    
    p = find(v.begin(),v.end(),9);
    if(p == v.end())
        cout << "not finf" << endl;
    
    p = find(v.begin() + 1,v.end() - 1,4);
    cout << *p <<endl;
    
    int *pp;
    /*if(pp == a + 4)
        cout << "not find" << endl;
    else
        cout << *pp << endl;*/

    sort(a,a + 7);
    for(pp = a;pp <= a + 6;pp++)
        cout << *pp << " ";
    return 0;
}
