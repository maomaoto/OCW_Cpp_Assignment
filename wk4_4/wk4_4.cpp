#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

char Int2Char[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


class BigInt{
private:
    char intStr[150];
public:
    BigInt(){}
    BigInt(const char *s){
        strcpy(intStr, s);
    }
    ~BigInt(){}

    int Char2Int(char a){
        switch (a){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
        }
    }

    BigInt & operator+(const BigInt & bi2){
        // add from the end
        char oper1[150];
        char oper2[150];
        char result[150] = {'\0'};
        strcpy(oper1, intStr);
        strcpy(oper2, bi2.intStr);
        int len1 = strlen(oper1);
        int len2 = strlen(oper2);
        int lenResult;
        if (len1 >= len2) lenResult = len1;
        else lenResult = len2;

        reverse(oper1, oper1+len1);
        reverse(oper2, oper2+len2);

        int add1, add2, tempInt;
        int carry = 0;
        char tempChar;
        for (int i = 0; i < lenResult; i++){
            if (i < len1) {
                add1 = Char2Int(oper1[i]);
            }
            else add1 = 0;

            if (i < len2) {
                add2 = Char2Int(oper2[i]);
            }
            else add2 = 0;

            tempInt = add1 + add2 + carry;
            carry = tempInt / 10;
            tempInt = tempInt % 10;

            tempChar = Int2Char[tempInt];
            result[i] = tempChar;

        }
        // if carry at the highest position
        if (carry != 0){
            tempChar = Int2Char[carry];
            result[lenResult] = tempChar;
        }

        reverse(result, result+strlen(result));
        strcpy(intStr, result);

        return *this;
    }

    BigInt & operator-(const BigInt & bi2){
        // subtract from the end
        char oper1[150];
        char oper2[150];
        char result[150] = {'\0'};
        strcpy(oper1, intStr);
        strcpy(oper2, bi2.intStr);
        int len1 = strlen(oper1);
        int len2 = strlen(oper2);
        int lenResult;

        // judge the sign
        bool sign = true;
        if (len1 < len2) sign = false;
        else if (len1 > len2) sign = true;
        else {
            for (int i = 0; i<len1; i++){
                if (oper1[i] > oper2[i] ){
                    sign = true;
                    break;
                } else if (oper1[i] < oper2[i]){
                    sign = false;
                    break;
                }
            }
        }

        // make oper1 is always bigger
        // add sign when finished
        if (!sign){
            swap(oper1, oper2);
            len1 = strlen(oper1);
            len2 = strlen(oper2);
        }

        // because len1 is always bigger or equal
        lenResult = len1;

        reverse(oper1, oper1+len1);
        reverse(oper2, oper2+len2);

        int sub1, sub2, tempInt;
        int carry = 0;
        char tempChar;

        for (int i = 0; i < lenResult; i++){
            if (i < len1) {
                sub1 = Char2Int(oper1[i]);
            }
            else sub1 = 0;

            if (i < len2) {
                sub2 = Char2Int(oper2[i]);
            }
            else sub2 = 0;

            if (sub1 + carry >= sub2){
                tempInt = sub1 + carry - sub2;
                carry = 0;
            } else {
                tempInt = sub1 + carry - sub2 + 10;
                carry = -1;
            }

            tempChar = Int2Char[tempInt];
            result[i] = tempChar;

        }
        // if carry at the highest position
        if (carry != 0){
            tempChar = Int2Char[carry];
            result[lenResult] = tempChar;
        }

        reverse(result, result+strlen(result));
        strcpy(intStr, result);

        return *this;
    }


    BigInt & operator*(const BigInt &);
    BigInt & operator/(const BigInt &);

    void SetValue(const char *s){
        strcpy(intStr, s);
    }

    friend istream & operator >> (istream &is, BigInt & bi);
    friend ostream & operator << (ostream &os, BigInt & bi);
};

istream & operator >> (istream &is, BigInt & bi){
    char temp[150];
    is >> temp;
    bi.SetValue(temp);
    return is;
}

ostream & operator << (ostream &os, BigInt & bi){
    os << bi.intStr;
    return os;
}

int main() {

    BigInt a, b, c;
    char oper;
    cin >> a >> oper >> b;
    switch (oper) {
    case '+':
        c = a + b;
    }
    cout << c;
    return 0;
}
