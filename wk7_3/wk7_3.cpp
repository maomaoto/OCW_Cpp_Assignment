#include <iostream>
#include <iomanip>
using namespace std;

int main()  {
    int d;
    cin >> d;
    cout << hex << d << endl;
    cout << dec << setw(10) << setfill('0') << d << endl;
    return 0;
}
