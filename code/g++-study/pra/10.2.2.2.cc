#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> monkey;
    int n,m;
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        monkey.clear();

        for(int i = 1;i <= n;++i)
            monkey.push_back(i);

        list<int>::iterator p = monkey.begin();

        while(monkey.size() > 1){
            for(int i = 1;i < m;++i){
                ++p;
                if(p == monkey.end())
                    p  = monkey.begin();
            }
            p = monkey.erase(p);
            if(p == monkey.end())
                p = monkey.begin();
        }
    cout << monkey.front() << endl;
    }
    return 0;
}

        
