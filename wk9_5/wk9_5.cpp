#include <iostream>
//#include <cstring>
//#include <cstdlib>
//#include <set>
#include <map>
using namespace std;

int main()  {



    int n, id, f;
    map<int, int> member_map; // use first as force, second as id
    map<int, int>::iterator it, it_big, it_small;
    pair<map<int, int>::iterator, bool> ret;
    int fgap_small, fgap_big;

    member_map[1000000000] = 1;

    // read number of new members
    cin >> n;

    for (int i = 0; i<n; i++){
        // read id and force
        cin >> id >> f;
        // insert new member into set
        ret = member_map.insert(pair<int, int>(f, id));
        it = ret.first;

        // find iterator bigger than self
        it_big = it;
        if (it != (member_map.end()--)) it_big++;

        // find iterator smaller than self
        it_small = it;
        if (it != member_map.begin()) it_small--;

        // find the force diff with neighbors
        fgap_big = it_big->first - it->first;
        fgap_small = it->first - it_small->first;

        // decide gamer
        if ((fgap_small == 0) || (fgap_big < fgap_small)){
            cout << it->second << ' ' << it_big->second << endl;
        } else {
            cout << it->second << ' ' << it_small->second << endl;
        }
        /*
        if (fgap_big == 0){
            // only have smaller member
            cout << it->second << ' ' << it_small->second << endl;
        } else if (fgap_small == 0){
            // only have bigger member
            cout << it->second << ' ' << it_big->second << endl;
        } else if (fgap_big < fgap_small){
            cout << it->second << ' ' << it_big->second << endl;
        } else {
            cout << it->second << ' ' << it_small->second << endl;
        }
        */


    }

    return 0;
}
/*
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
    pair<set<CMember>::iterator, bool> ret;
    int fgap_small, fgap_big;

    member_set.insert(CMember(1, 1000000000));

    // read number of new members
    cin >> n;

    for (int i = 0; i<n; i++){
        // read id and force
        cin >> id >> f;
        // insert new member into set
        ret = member_set.insert(CMember(id, f));
        it = ret.first;

        // find iterator bigger than self
        it_big = it;
        if (it != (member_set.end()--)) it_big++;

        // find iterator smaller than self
        it_small = it;
        if (it != member_set.begin()) it_small--;

        // find the force diff with neighbors
        fgap_big = (*it_big).force - (*it).force;
        fgap_small = (*it).force - (*it_small).force;

        // decide gamer
        if (fgap_big == 0){
            // only have smaller member
            cout << (*it).id << ' ' << (*it_small).id << endl;
        } else if (fgap_small == 0){
            // only have bigger member
            cout << (*it).id << ' ' << (*it_big).id << endl;
        } else if (fgap_big < fgap_small){
            cout << (*it).id << ' ' << (*it_big).id << endl;
        } else {
            cout << (*it).id << ' ' << (*it_small).id << endl;
        }


    }

    return 0;
}

*/
