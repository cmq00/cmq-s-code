#include <iostream>

using namespace std;

class cs{
    public:
        cs(){
            cout << "Cons 1 called" << endl;
        }
        cs(int n){
            cout << "Cons 2 called" << endl;
        }
};

int main()
{
    cs array1[2];
    cout << "step" << endl;
    cs array2[2] = {4,5};
    cout << "step2" << endl;
    cs array3[3] = {3};
    cout << "step3" << endl;
    cs* array4 = new cs[2];
    delete [] array4;
    return 0;
}
