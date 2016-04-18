/*
    wk 3-4 魔獸世界之一：備戰
*/

#include <iostream>
#include <iomanip>
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
    int ProduceTick;
    static int KnightLife[5];
    int timer;


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

        ProduceTick = 0;
        timer = 0;

    }

    bool ProduceKnight() {
        // return false if stop making warrior
        int tempTick = ProduceTick;
        while(true) {
            if (life >= KnightLife[ProduceSeq[ProduceTick]]) {
                TotalKnight++;
                KnightCount[ProduceSeq[ProduceTick]]++;
                life -= KnightLife[ProduceSeq[ProduceTick]];
                cout << setfill('0') << setw(3) << timer << ' ';
                cout << HQName[type] << ' ' << KnightName[ProduceSeq[ProduceTick]] << ' ';
                cout << TotalKnight << " born with strength " << KnightLife[ProduceSeq[ProduceTick]] << ',';
                cout << KnightCount[ProduceSeq[ProduceTick]] << ' ' << KnightName[ProduceSeq[ProduceTick]];
                cout << " in " << HQName[type] << " headquarter" << endl;
                timer++;
                ProduceTick = (ProduceTick + 1) % 5;
                return true;
            } else {
                ProduceTick = (ProduceTick + 1) % 5;
                if (tempTick == ProduceTick) {
                    cout << setfill('0') << setw(3) << timer << ' ';
                    cout << HQName[type] << " headquarter stops making warriors" << endl;
                    return false;
                }
            }
        }


    }

};

int HeadQuarter::KnightLife[5] = {0, 0, 0, 0, 0};

int main()  {

    int NumDataSet = 0;
    int HQLife = 0;
    //int KnightLife[5] = {0};


    cin >> NumDataSet;

    for (int i = 0; i< NumDataSet; i++){
        cin >> HQLife;
        cin >> HeadQuarter::KnightLife[dragon];
        cin >> HeadQuarter::KnightLife[ninja];
        cin >> HeadQuarter::KnightLife[iceman];
        cin >> HeadQuarter::KnightLife[lion];
        cin >> HeadQuarter::KnightLife[wolf];

        HeadQuarter HQRed(red, HQLife);
        HeadQuarter HQBlue(blue, HQLife);

        bool RedFlag = true;
        bool BlueFlag = true;

        cout << "Case:" << i+1 << endl;
        while (RedFlag | BlueFlag) {
            if (RedFlag) RedFlag = HQRed.ProduceKnight();
            if (BlueFlag) BlueFlag = HQBlue.ProduceKnight();
        }


    }



    return 0;
}
