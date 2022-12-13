#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>//hgfj

using namespace  std;

struct  MAN{
    int score;

    int money;
    int character;
};

bool compare(const MAN &src, const MAN  &dest) {

    if (src.score == dest.score) {
	    if (src.money == dest.money) {
	        return src.character > dest.character;
	    } else {
	        return src.money > dest.money;
	    }
    }

    return src.score > dest.score;
}

int main(void)
{

    int n;
    MAN man;
    vector <MAN> mans;

    cin >> n;
    while (n-- > 0) {

        cin >> man.score >> man.money >> man.character;
        mans.push_back(man);
    }

    sort(mans.begin(), mans.end(), compare);
   
    for (vector <MAN>::iterator iter = mans.begin(); iter != mans.end(); ++iter) {
        cout << iter->score << " " << iter->money << " " << iter->character << "\n";
    }

    return 0;
}