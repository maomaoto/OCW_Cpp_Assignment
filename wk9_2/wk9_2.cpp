
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
