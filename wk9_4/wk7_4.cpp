#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

char int_char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// 判斷字串s是不是整數
bool is_num(string s){
    bool flag = true;
    for (unsigned int i = 0; i<s.length(); i++){
        if (!isdigit(s[i])){
            flag = false;
            break;
        }
    }
    return flag;
}

// 整數轉成字串
string int_to_str(int n){
    // convert int to string from the end
    //cout << n << endl;
    string temp;
    do {
        temp += int_char[n%10];
        n = n/10;
    } while(n != 0);

    //cout << temp << endl;
    // reverse string
    string temp2;
    for (int i = temp.length()-1; i >=0; i--){
        temp2.append(1,temp[i]);
    }
    return temp2;
}

class StrManip{
private:
    int num;
    string str[20];
public:
    StrManip() {}
    StrManip(int n):num(n) {}

    void set_num(int n) {
        num = n;
    }

    void set_string(int i, const string & s){
        str[i] = s;
    }

    // 取出第N個字符串第X個字符開始的長度為L的字符串
    string copy(int n, int x, int l){
        string temp;
        temp = str[n-1].substr(x, l);
        //cout << "StrManip Copy: " << temp << endl;
        return temp;
    }

    // 判斷S1, S2是否為0-99999之間的整數，若是則將其轉化為整數值加法
    // 若不是，則作字符串加法，返回的值為一字符串
    string add(string s1, string s2){
        if (is_num(s1) && is_num(s2)){
            int n1 = atoi(s1.c_str());
            int n2 = atoi(s2.c_str());
            if ( (n1 >= 0) && (n1 <= 99999) && (n2 >= 0) && (n2 <= 99999)){
                int temp = n1 + n2;
                string s_temp = int_to_str(temp);
                return s_temp;
            }

        }

        // not int between 0-99999
        string temp = s1;
        temp.append(s2);
        return temp;

    }

    // 在第n個字符串中從左開始找尋S字符串，返回其第一次出現的位置；若沒有找到，返回字符串的長度
    int find(string s, int n){
        unsigned int pos;
        pos = str[n-1].find(s);
        //cout << "findpos " <<  pos << endl;
        if (pos != string::npos) return pos;
        else return str[n+1].length();
    }

    // 在第n個字符串中從右開始找尋S字符串，返回其第一次出現的位置；若沒有找到，返回字符串的長度
    int rfind(string s, int n){
        unsigned int pos;
        pos = str[n-1].rfind(s);
        if (pos != string::npos) return pos;
        else return str[n+1].length();

    }

    // 在第n 個字符串的第x個字符位置插入s字符串
    void insert(string s, int n, int x){
        str[n-1].insert(x, s);
    }

    // 把第n個字符串變為s
    void reset(string s, int n){
        str[n-1] = s;
    }

    // 把第n個字符串變為s, char* type
    void reset(char* s, int n){
        str[n-1] = s;
    }

    // 打印輸出第n個字符串
    void print(int i){
        cout << str[i-1] << endl;
    }

    // 打印輸出所有字符串
    void printall(){
        for (int i = 0; i<num; i++){
            cout << str[i] << endl;
        }
    }

};

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


void compute(string cmd, string &s, StrManip & my_str){
    //cout << "compute" << endl;
    string temp;
    if (cmd.compare("copy") == 0){
        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int N = atoi(temp.c_str());

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int X = atoi(temp.c_str());

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int L = atoi(temp.c_str());

        //cout << "copy " << N << ' ' << X << ' ' << L << endl;
        s.insert(0, " ");
        s.insert(0, my_str.copy(N, X, L));


    } else if (cmd.compare("add") == 0){
        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        string s1 = temp;

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        string s2 = temp;

        //cout << "add " << s1 << ' ' << s2 << endl;
        s.insert(0, " ");
        s.insert(0, my_str.add(s1, s2));
    } else if (cmd.compare("find") == 0){
        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        string s1 = temp;

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int N = atoi(temp.c_str());

        //cout << "find " << s1 << ' ' << N << endl;
        s.insert(0, " ");
        s.insert(0, int_to_str(my_str.find(s1, N)));

    } else if (cmd.compare("rfind") == 0){
        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        string s1 = temp;

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int N = atoi(temp.c_str());

        //cout << "rfind " << s1 << ' ' << N << endl;
        s.insert(0, " ");
        s.insert(0, int_to_str(my_str.rfind(s1, N)));
    } else if (cmd.compare("insert") == 0){
        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        string s1 = temp;

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int N = atoi(temp.c_str());

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int X = atoi(temp.c_str());
        //cout << "insert " << s1 << ' ' << N << ' ' << X << endl;
        my_str.insert(s1, N, X);
    } else if (cmd.compare("reset") == 0){
        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        string s1 = temp;

        temp = get_str(s);
        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int N = atoi(temp.c_str());

        //cout << "reset " << s1 << ' ' << N << endl;
        my_str.reset(s1, N);
    } else if (cmd.compare("print") == 0){
        temp = get_str(s);

        while (is_command(temp)) {
            compute(temp, s, my_str);
            temp = get_str(s);
        }
        int N = atoi(temp.c_str());

        //cout << "print: " << N << endl;
        my_str.print(N);
    } else if (cmd.compare("printall") == 0){
        my_str.printall();
    }
}





int main()  {
    int n;
    string temp;
    StrManip my_str;

    // read string
    cin >> n;
    my_str.set_num(n);

    for (int i = 0; i<n; i++){
        cin >> temp;
        my_str.set_string(i, temp);
    }


    getline(cin, temp);
    //cout << temp;

    while(getline(cin, temp)){
        string cmd = get_str(temp);
        //cout << "here" << endl;
        if (cmd.compare("over") == 0){
            break;
        }
        compute(cmd, temp, my_str);
    }



    return 0;
}
