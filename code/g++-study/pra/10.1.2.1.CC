#include <iostream> 
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0;i < 5;i++)
        v.push_back(i);

    vector<int>::iterator i;
    for(i = v.begin();i != v.end();i++){
        cout << *i << " ";
        *i *= 2;
    }

    cout << endl;

    for(vector<int>::reverse_iterator j = v.rbegin();j != v.rend();j++)
        cout << *j << " ";

    cout << endl;

    return 0;
}


