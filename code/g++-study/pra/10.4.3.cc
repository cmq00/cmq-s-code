#include <set>
#include <iostream>

using namespace std;

int main()
{
    typedef set<int>::iterator it;
    int a[5] = {3,5,4,1,6};
    set <int> st(a,a + 5);
    pair<it,bool> result;
    result = st.insert(2);
    if(result.second)
        cout << *result.first << "inserted" << endl;
    return 0;
}

