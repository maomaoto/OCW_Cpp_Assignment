#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


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
        temp = str[n+1].substr(x, l);
        return temp;
    }

    // 判斷S1, S2是否為0-99999之間的整數，若是則將其轉化為整數值加法
    // 若不是，則作字符串加法，返回的值為一字符串
    string add(string s1, string s2){}

    // 在第n個字符串中從左開始找尋S字符串，返回其第一次出現的位置；若沒有找到，返回字符串的長度
    int find(string s, int n){
        int pos;
        pos = str[n+1].find(s);
        if (pos != string::npos) return pos;
        else return str[n+1].length();
    }

    // 在第n個字符串中從右開始找尋S字符串，返回其第一次出現的位置；若沒有找到，返回字符串的長度
    int rfind(string s, int n){

    }

    // 在第n 個字符串的第x個字符位置插入s字符串
    void insert(string s, int n, int x){}

    // 把第n個字符串變為s
    void reset(string s, int n){}

    // 打印輸出第n個字符串
    void print(int i){
        cout << str[i] << endl;
    }

    // 打印輸出所有字符串
    void printall(){
        for (int i = 0; i<num; i++){
            this->print(i);
        }
    }

};


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

    for (int i = 0; i<n; i++){
        my_str.print(i);
    }

    return 0;
}
