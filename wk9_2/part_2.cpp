#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
#include <iterator>
template <class T>
class CMyistream_iterator:public iterator <input_iterator_tag, T>{
private:
    istream & is;
    T value;
public:
    // read one value when constructed
    CMyistream_iterator(istream & i ):is(i){is >> value;}

    CMyistream_iterator(const CMyistream_iterator& mit):is(mit.is), value(mit.value){}

    // return value when operator*
    T & operator*(){
        return value;
    }

    // read next value from istream
    CMyistream_iterator operator++(){
        is >> value;
        return *this;
    }

    CMyistream_iterator operator++(int){
        CMyistream_iterator temp(*this);
        operator++();
        return temp;
    }
};

int main()
{
    CMyistream_iterator<int> inputInt(cin);
    int n1,n2,n3;
    n1 = * inputInt; //读入 n1
    int tmp = * inputInt;
    cout << tmp << endl;
    inputInt ++;
    n2 = * inputInt; //读入 n2
    inputInt ++;
    n3 = * inputInt; //读入 n3
    cout << n1 << "," << n2<< "," << n3 << endl;
    CMyistream_iterator<string> inputStr(cin);
    string s1,s2;
    s1 = * inputStr;
    inputStr ++;
    s2 = * inputStr;
    cout << s1 << "," << s2 << endl;
    return 0;
}
