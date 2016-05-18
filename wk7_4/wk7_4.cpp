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



    // 材N才﹃材X才秨﹍L才﹃
    string copy(int n, int x, int l){
        string temp;
        temp = str[n+1].substr(x, l);
        return temp;
    }

    // 耞S1, S2琌0-99999ぇ丁俱计璝琌玥盢ㄤ锣て俱计猭
    // 璝ぃ琌玥才﹃猭才﹃
    string add(string s1, string s2){}

    // 材n才﹃い眖オ秨﹍т碝S才﹃ㄤ材Ω瞷竚璝⊿Τт才﹃
    int find(string s, int n){
        int pos;
        pos = str[n+1].find(s);
        if (pos != string::npos) return pos;
        else return str[n+1].length();
    }

    // 材n才﹃い眖秨﹍т碝S才﹃ㄤ材Ω瞷竚璝⊿Τт才﹃
    int rfind(string s, int n){

    }

    // 材n 才﹃材x才竚础s才﹃
    void insert(string s, int n, int x){}

    // р材n才﹃跑s
    void reset(string s, int n){}

    // ゴ块材n才﹃
    void print(int i){
        cout << str[i] << endl;
    }

    // ゴ块┮Τ才﹃
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
