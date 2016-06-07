#include <iostream>
//#include <cstring>
//#include <cstdlib>
#include <set>
//#include <map>
using namespace std;


class CPrime{
public:
    int num;    // number
    int npf;    // number of prime factors
    CPrime(int _n, int _npf):num(_n), npf(_npf) {}
};

class MyPrior {
public:
    bool operator()(const CPrime & a, const CPrime &b){
        if ((a.npf > b.npf) || (a.npf == b.npf && a.num > b.num)) return true;
        else return false;
    }

};

int cal_prime(int num){
    // calculate the number of prime factors

    // use a set to store prime factors
    set<int> prime_set;

    int n = num;
    for (int i = 2; i<=n; i++){
        while(n != i){
            if (n % i == 0){
                prime_set.insert(i);
                n = n/i;
            } else {
                break;
            }
        }
    }
    // n == i, last prime
    prime_set.insert(n);

    // make sure itself is not counted
    prime_set.erase(num);

    //cout << "num: " << num << " , npf: " << prime_set.size() << endl;

    return prime_set.size();
}



int main()  {

    typedef set<CPrime, MyPrior> MSET;

    int n;  // number of input lines
    int num, nof;   // number, number of factors
    MSET number_set;
    MSET::iterator it_end;

    // read number of lines
    cin >> n;
    //nof = cal_prime(n);
    //cout << nof;

    for (int i = 0; i<n; i++){
        // 10 number for each line
        for (int j = 0; j<10; j++){
            cin >> num;
            nof = cal_prime(num);
            number_set.insert(CPrime(num, nof));
        }
        cout << number_set.begin()->num << ' ' << number_set.rbegin()->num << endl;
        number_set.erase(number_set.begin());
        it_end = number_set.end();
        it_end--;
        number_set.erase(it_end);

    }


    return 0;
}


