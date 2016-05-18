#include <iostream>
#include <iomanip>
using namespace std;

int main()  {
    double d;
    cin >> d;
    cout << fixed << setprecision(5) << d << endl;
    cout << scientific << setprecision(7) << d << endl;
    return 0;
}
