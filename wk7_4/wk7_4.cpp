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



    // ���X��N�Ӧr�Ŧ��X�Ӧr�Ŷ}�l�����׬�L���r�Ŧ�
    string copy(int n, int x, int l){
        string temp;
        temp = str[n+1].substr(x, l);
        return temp;
    }

    // �P�_S1, S2�O�_��0-99999��������ơA�Y�O�h�N����Ƭ���ƭȥ[�k
    // �Y���O�A�h�@�r�Ŧ�[�k�A��^���Ȭ��@�r�Ŧ�
    string add(string s1, string s2){}

    // �b��n�Ӧr�Ŧꤤ�q���}�l��MS�r�Ŧ�A��^��Ĥ@���X�{����m�F�Y�S�����A��^�r�Ŧꪺ����
    int find(string s, int n){
        int pos;
        pos = str[n+1].find(s);
        if (pos != string::npos) return pos;
        else return str[n+1].length();
    }

    // �b��n�Ӧr�Ŧꤤ�q�k�}�l��MS�r�Ŧ�A��^��Ĥ@���X�{����m�F�Y�S�����A��^�r�Ŧꪺ����
    int rfind(string s, int n){

    }

    // �b��n �Ӧr�Ŧꪺ��x�Ӧr�Ŧ�m���Js�r�Ŧ�
    void insert(string s, int n, int x){}

    // ���n�Ӧr�Ŧ��ܬ�s
    void reset(string s, int n){}

    // ���L��X��n�Ӧr�Ŧ�
    void print(int i){
        cout << str[i] << endl;
    }

    // ���L��X�Ҧ��r�Ŧ�
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
