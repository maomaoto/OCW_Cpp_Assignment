/*
    wk 5-2 魔獸世界之二：裝備
*/

#include <iostream>
#include <iomanip>
using namespace std;

enum KnightType{dragon, ninja, iceman, lion, wolf};
char KnightName[][7] = {"dragon", "ninja", "iceman", "lion", "wolf"};

enum HQType{red, blue};
char HQName[][5] = {"red", "blue"};

enum WeaponType{sword, bomb, arrow};
char WeaponName[][6] = {"sword", "bomb", "arrow"};

class CKnight {
public:
    //KnightType type;
    int serial;
    int life;
    //int attack;

    CKnight(int s, int l): serial(s), life(l) {
        //cout << KnightName[type] << endl;
    }

    virtual void PrintInfo() = 0;
};


class CDragon: public CKnight {
private:
    WeaponType wp1;
    float morale;
public:
    CDragon(int s, int l, float m): CKnight(s, l){
        int temp = (m+0.005)*100;
        morale = (float)temp/100;
        wp1 = static_cast<WeaponType>(s%3);
    }

    void PrintInfo(){
        cout << "It has a " << WeaponName[wp1] << ",and it's morale is " << setprecision(3) << morale << endl;
    }

};

class CNinja: public CKnight {
private:
    WeaponType wp1, wp2;
public:
    CNinja(int s, int l): CKnight(s, l) {
        wp1 = static_cast<WeaponType>(s%3);
        wp2 = static_cast<WeaponType>((s+1)%3);
    }

    void PrintInfo() {
        cout << "It has a " << WeaponName[wp1] << " and a " << WeaponName[wp2] << endl;
    }
};

class CIceman: public CKnight {
private:
    WeaponType wp1;
public:
    CIceman(int s, int l): CKnight(s, l) {
        wp1 = static_cast<WeaponType>(s%3);
    }

    void PrintInfo(){
        cout << "It has a " << WeaponName[wp1] << endl;
    }
};

class CLion: public CKnight {
private:
    int loyalty;
public:
    CLion(int s, int l, int loyalty): CKnight(s, l), loyalty(loyalty){}
    void PrintInfo(){
        cout << "It's loyalty is " << loyalty << endl;
    }
};

class CWolf: public CKnight {
public:
    CWolf(int s, int l): CKnight(s, l) {}
    void PrintInfo(){}
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
    CKnight* KnightList[50];


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

        for (int i = 0; i<50; i++){
            KnightList[i] = NULL;
        }

    }

    bool ProduceKnight() {
        // return false if stop making warrior
        int tempTick = ProduceTick;
        while(true) {
            if (life >= KnightLife[ProduceSeq[ProduceTick]]) {
                TotalKnight++;
                KnightCount[ProduceSeq[ProduceTick]]++;
                life -= KnightLife[ProduceSeq[ProduceTick]];
                switch(ProduceSeq[ProduceTick]){
                case dragon:
                    KnightList[TotalKnight-1] = new CDragon(TotalKnight, KnightLife[ProduceSeq[ProduceTick]],
                                                            (float)life/KnightLife[ProduceSeq[ProduceTick]]);
                    break;
                case ninja:
                    KnightList[TotalKnight-1] = new CNinja(TotalKnight, KnightLife[ProduceSeq[ProduceTick]]);
                    break;
                case iceman:
                    KnightList[TotalKnight-1] = new CIceman(TotalKnight, KnightLife[ProduceSeq[ProduceTick]]);
                    break;
                case lion:
                    KnightList[TotalKnight-1] = new CLion(TotalKnight, KnightLife[ProduceSeq[ProduceTick]], life);
                    break;
                case wolf:
                    KnightList[TotalKnight-1] = new CWolf(TotalKnight, KnightLife[ProduceSeq[ProduceTick]]);
                }


                cout << setfill('0') << setw(3) << timer << ' ';
                cout << HQName[type] << ' ' << KnightName[ProduceSeq[ProduceTick]] << ' ';
                cout << TotalKnight << " born with strength " << KnightLife[ProduceSeq[ProduceTick]] << ',';
                cout << KnightCount[ProduceSeq[ProduceTick]] << ' ' << KnightName[ProduceSeq[ProduceTick]];
                cout << " in " << HQName[type] << " headquarter" << endl;
                KnightList[TotalKnight-1]->PrintInfo();
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
