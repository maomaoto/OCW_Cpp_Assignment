#include <iostream>
//#include <iomanip>
#include <cstring>
//#include <cctype>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

map<int, multiset<int> > mmid;
typedef multiset<int> MSET;

string get_str(string &s){
    string temp;
    bool found = false;
    int pos = 0;
    // 把找到的字串存到temp裡
    for (int i = 0; i<s.length(); i++){
        if (s[i] == ' '){
            if (found) {
                pos = i;
                break;
            }
        } else {
            temp.append(1, s[i]);
            found = true;
            pos = i;
        }
    }

    // 清掉 s 裡完取出來的第一個字串
    s.erase(0, pos);
    //cout << "get_str: " << temp << endl;
    return temp;
}


int main()  {
    int n;
    string temp;
    string cmd;



    cin >> n;
    //getline(cin, temp);  // remove "return line"

    for (int i = 0; i<n; i++){
        //getline(cin, temp);
        //cmd = get_str(temp);
        cin >> cmd;
        if (cmd.compare("new") == 0){
            // add a multiset
            //int id = atoi(get_str(temp).c_str());
            int id;
            cin >> id;
            MSET sequence;
            mmid.insert(make_pair(id, sequence));

        } else if (cmd.compare("add") == 0){
            //int id = atoi(get_str(temp).c_str());
            //int num = atoi(get_str(temp).c_str());
            int id, num;
            cin >> id >> num;
            mmid[id].insert(num);

        } else if (cmd.compare("merge") == 0){
            //int id1 = atoi(get_str(temp).c_str());
            //int id2 = atoi(get_str(temp).c_str());
            int id1, id2;
            cin >> id1 >> id2;
            if (id1 != id2) {
                for (MSET::iterator it = mmid[id2].begin(); it != mmid[id2].end(); it++){
                    mmid[id1].insert(*it);
                }
                mmid[id2].clear();
            }

        } else if (cmd.compare("unique") == 0){
            //int id = atoi(get_str(temp).c_str());
            int id;
            cin >> id;

            set<int> temp_set;
            // copy all elements from multiset to set, repeated items are auto neglected.
            temp_set.insert(mmid[id].begin(), mmid[id].end());
            /*
            for (MSET::iterator it = mmid[id].begin(); it != mmid[id].end(); it++){
                temp_set.insert(*it);
            }
            */
            // clear multiset, and copy cleared elements back to multiset
            mmid[id].clear();
            mmid[id].insert(temp_set.begin(), temp_set.end());
            /*
            for (set<int>::iterator it = temp_set.begin(); it != temp_set.end(); it++){
                mmid[id].insert(*it);
            }
            */
            temp_set.clear();


        } else if (cmd.compare("out") == 0){
            //int id = atoi(get_str(temp).c_str());
            int id;
            cin >> id;
            for (MSET::iterator it = mmid[id].begin(); it != mmid[id].end(); it++){
                cout << *it << ' ';
            }
            cout << endl;

        }
    }

    return 0;
}
