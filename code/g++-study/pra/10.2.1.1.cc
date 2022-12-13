#include <iostream>
#include <vector>

using namespace std;

template <class T>
void prvc(const vector<T> & v)
{
    typename vector<T>::const_iterator i;
    for(i = v.begin();i != v.end();++i)
        cout << *i << " ";
    cout << endl;
}

int main()
{
    int a[5] = {1,2,3,4,5};
    vector<int> v(a,a + 5);

    prvc(v);
    v.insert(v.begin() + 2,13);
    prvc(v);
    v.erase(v.begin() + 2);
    prvc(v);
    return 0;
}
