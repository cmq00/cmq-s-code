#include <list>
#include <iostream>

using namespace std;


void print_lst(list <int>::iterator it, int seq, int flag)
{
    #ifdef PRINT
    if (flag == 0)
        cout << "visit list " << *it << " " << seq << endl;
    else
        cout << "after delete " << *it << " " << seq << endl;
    #endif
}


int main()
{
    list<int> lst;
    int t;
    scanf("%d",&t);

    while(t -- > 0)
    {
        int n, i;
        cin >> n;
        lst.clear();
        
        for(i = 1; i <= n; ++i)
            lst.push_back(i);

        list<int>::iterator it;
       
        int p = 1;
        while(lst.size() > 3)
        {   
            if (p % 2 == 1) {
                for (i = 1, it = lst.begin(); it != lst.end(); ++ i) {
                    print_lst(it, i, 0);
                    if (i % 2 == 0) { 
                        it = lst.erase(it);
                        print_lst(it, i, 1);
                    }
                    else
                        ++ it;
                }
            } else {
                for (i = 1, it = lst.begin(); it != lst.end(); ++ i) {
                    print_lst(it, i, 0);
                    if (i % 3 == 0) { 
                        it = lst.erase(it);
                        print_lst(it, i, 1);
                    }
                    else
                        ++ it;
                }
            }
            ++ p;
        }
        while (lst.size() != 1) {
            cout << lst.front() << " ";
            lst.pop_front();
        }
        cout << lst.front() << endl;
    }
    return 0;
}//kjk