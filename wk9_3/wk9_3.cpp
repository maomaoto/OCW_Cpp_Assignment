#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

//map<int, multiset<int> > mmid;
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
    int n, x;
    string temp;
    string cmd;
    MSET my_set;
    int x_count;
    set<int> my_set_record;



    cin >> n;
    //getline(cin, temp);  // remove "return line"

    for (int i = 0; i<n; i++){
        //getline(cin, temp);
        //cmd = get_str(temp);
        cin >> cmd;
        if (cmd.compare("add") == 0){
            // read x
            cin >> x;

            // add x into my_set and my_set_record
            my_set.insert(x);
            my_set_record.insert(x);

            // output the number of x in my_set
            x_count = my_set.count(x);
            cout << x_count << endl;

        } else if (cmd.compare("del") == 0){
            // read x
            cin >> x;

            // output the number of x in my_set
            x_count = my_set.count(x);
            cout << x_count << endl;

            // remove all x in my_set
            my_set.erase(x);

        } else if (cmd.compare("ask") == 0){
            // read x
            cin >> x;
            // output if x is ever existed (0:No, 1:Yes)
            if (my_set_record.find(x) != my_set_record.end()) cout << "1 ";
            else cout << "0 ";

            // output the number of x in my_set
            x_count = my_set.count(x);
            cout << x_count << endl;


        }
    }

    return 0;
}
