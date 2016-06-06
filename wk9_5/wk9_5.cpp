#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

class CMember{
public:
    int id;
    int force;
    CMember(int i, int f):id(i), force(f){}
};

bool operator<(const CMember & a, const CMember &b){
    if (a.force < b.force) return true;
    else return false;
}

int main()  {
    int n, id, f;
    set<CMember> member_set;
    set<CMember>::iterator it, it_big, it_small;

    member_set.insert(CMember(1, 1000000000));

    // read number of new members
    cin >> n;

    for (int i = 0; i<n; i++){
        cin >> id >> f;
        it = member_set.insert(CMember(id, f));
        if (it != member_set.end()-1) it_big = it +1;
        else it_big = it;
        if (it != member_set.begin()) it_small = it -1;
        else it_small = it;
    }

    return 0;
}
