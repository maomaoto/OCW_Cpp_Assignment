#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

map<int, multiset<int> > mmid;

bool is_command(string cmd){
    if (cmd.compare("copy") == 0){
        return true;
    } else if (cmd.compare("add") == 0){
        return true;
    } else if (cmd.compare("find") == 0){
        return true;
    } else if (cmd.compare("rfind") == 0){
        return true;
    } else if (cmd.compare("insert") == 0){
        return true;
    } else if (cmd.compare("reset") == 0){
        return true;
    } else if (cmd.compare("print") == 0){
        return true;
    } else if (cmd.compare("printall") == 0){
        return true;
    } else {
        return false;
    }
}


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
    getline(cin, temp);  // remove "return line"

    for (int i = 0; i<n; i++){
        getline(cin, temp);
        cmd = get_str(temp);
        if (cmd.compare("new") == 0){
            // add a multiset
            int id = atoi(get_str(temp).c_str());
            mmid.insert(make_pair(id, multiset<int>));

        } else if (cmd.compare("add") == 0){
            int id = atoi(get_str(temp).c_str());
            int num = atoi(get_str(temp).c_str());


        } else if (cmd.compare("merge") == 0){
        } else if (cmd.compare("unique") == 0){
        } else if (cmd.compare("out") == 0){
        }
    }

    return 0;
}
