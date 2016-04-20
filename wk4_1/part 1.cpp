#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    char * operator=(const char * s){
        if (s) {
            //r = 0;
            //i = 0;
            char * pchPlus = strchr(s, '+');
            char * pchEnd = strchr(s, 'i');
            // only consider good input...
            if ( (pchPlus != NULL) & (pchEnd != NULL)){
                char strReal[pchPlus-s+1];
                strncpy(strReal, s, pchPlus-s);
                strReal[pchPlus - s] = '\0';
                r = atof(strReal);
                char strImg[pchEnd - pchPlus -1];
                strncpy(strImg, pchPlus+1, pchEnd - pchPlus-1);
                strImg[pchEnd - pchPlus -1] = '\0';
                i = atof(strImg);
            }
        }
        return (char*)s;
    }
};
int main() {
    Complex a;
    a = "3.5+4.6i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
