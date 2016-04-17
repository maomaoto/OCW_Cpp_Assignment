/*
    wk 3-4 魔獸世界之一：備戰
*/

#include <iostream>
using namespace std;

enum KnightType{dragon, ninja, iceman, lion, wolf};
char KnightName[][7] = {"dragon", "ninja", "iceman", "lion", "wolf"};

enum HQType{red, blue};
char HQName[][5] = {"red", "blue"};

class Knight {
public:
    KnightType type;
    int serial;
    int life;
    int attack;

    Knight(KnightType t, int s, int l, int a = 0): type(t), serial(s), life(l), attack(a) {
        cout << KnightName[type] << endl;
    }

};

class HeadQuarter {
public:
    HQType type;
    int life;
    int TotalKnight;
    int KnightCount[5];
    KnightType ProduceSeq[5];

    HeadQuarter(HQType t, int l): type(t), life(l) {
        TotalKnight = 0;
        for (int i = 0; i<5; i++){
            KnightCount[i] = 0;
        }
        if (t == red) {
            ProduceSeq[0] = iceman;
            ProduceSeq[1] = lion;
            ProduceSeq[2] = wolf;
            ProduceSeq[3] = ninja;
            ProduceSeq[4] = dragon;
        } else if (t == blue) {
            ProduceSeq[0] = lion;
            ProduceSeq[1] = dragon;
            ProduceSeq[2] = ninja;
            ProduceSeq[3] = iceman;
            ProduceSeq[4] = wolf;
        }

    }

};


int main()  {

    int NumDataSet = 0;
    int HQLife = 0;
    int KnightLife[5] = {0};


    cin >> NumDataSet;

    for (int i = 0; i< NumDataSet; i++){
        cin >> HQLife;
        cin >> KnightLife[dragon];
        cin >> KnightLife[ninja];
        cin >> KnightLife[iceman];
        cin >> KnightLife[lion];
        cin >> KnightLife[wolf];
    }



    return 0;
}
