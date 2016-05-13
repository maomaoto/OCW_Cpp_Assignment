
// 在此处补充你的代码

class MyString: public string{
public:
    MyString(): string() {}
    MyString(const char *s): string(s) {}
    MyString(const MyString& mstr): string(mstr) {}
    MyString(const string& str): string(str){}

    MyString& operator= (const MyString& mstr){
        ((string *) this)->operator=(mstr);
        return *this;
    }

    MyString operator+ (const MyString& mstr) {
        MyString temp(*this);
        temp.append(mstr);
        return temp;
    }

    MyString operator+ (const char* s) {
        MyString temp(*this);
        temp.append(s);
        return temp;
    }

    MyString operator() (int pos, int len){
        MyString mstr = ((string *) this)->substr(pos, len);
        return mstr;
    }

    friend MyString operator+(char* s, const MyString& mstr);



};

MyString operator+(char* s, const MyString& mstr){
    MyString temp(s);
    temp = temp + mstr;
    return temp;
}

