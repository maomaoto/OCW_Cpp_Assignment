#include <iostream>
using namespace std;
class A {
public:
    int val;
// 在此处补充你的代码
    A();
    int & GetObj();
};

A::A(){
    val = 0;
}

int & A::GetObj(){
    //int & r = val;
    return val;
}

main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}
