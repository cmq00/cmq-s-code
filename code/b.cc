#include <bits/stdc++.h>

using namespace std;

class Sphere
{
    private:
	    int x,y,z,r;
    public:
        void set(double x1,double y1,double z1,double r1){
            x = x1,y = y1,z = z1,r = r1;
        }
        string re(double x2,double y2,double z2,double r2){
            double dis = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2) + (z - z2) * (z - z2));
            if(dis == r + r2 || dis == r - r2 || dis == r2 - r){
                return "They are intersectant";
            }
            else if(dis > r + r2)
                return "They are disjoint";
            else
                return "They are intersectant";
        }
};


int main()
{
    int n;
    cin >> n;
    Sphere s1,s2;
    while(n--){
        double x,y,z,r;
        cin >> x >> y >> z >> r;
        s1.set(x,y,z,r);
        cin >> x >> y >> z >> r;
        s2.set(x,y,z,r);
        cout << s1.re(x,y,z,r) << endl;
    }
	return 0;
}


