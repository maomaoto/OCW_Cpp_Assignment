/*
    wk 2-1 ²�檺�ǥͰT���B�z�{�ǹ�{
    �y�z�G
        �b�@�ӾǥͰT���B�z�{�Ǥ��A�n�D��{�@�ӥN��ǥͪ����A�åB�Ҧ��������ܶq�����ӬO�p�����C
    ��J�G
        �m�W�B�~�֡B�Ǹ��B�Ĥ@�Ǧ~�������Z�B�ĤG�Ǧ~�������Z�B�ĤT�Ǧ~�������Z�B�ĥ|�Ǧ~�������Z�C
        �䤤�m�W�B�Ǹ����r�Ŧ�A���t�Ů�M�r���F�~�֬�����ơF���Z���D�t��ơC
        �U�������e�������γ�ӭ^��r��","�j�}�A�L�h�l�Ů�C
    ��X�G
        �@��A�����ǿ�X�G�m�W�B�~�֡B�Ǹ��B�|�~�������Z(�V�U����)�C
        �U�������e���γ�ӭ^��r��","�j�}�A�L�h�l�Ů�C

*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

class Student {
private:
    char name[80] = {'\0'};
    int age = 0;
    char serial[80] = {'\0'};
    int gradeFirst = 0;
    int gradeSecond = 0;
    int gradeThird = 0;
    int gradeForth = 0;
public:
    void setName(char * inputName){
        strcpy(name, inputName);
    }

    void printName(){
        cout << name;
    }

    void setAge(int inputAge){
        age = inputAge;
    }

    void printAge(){
        cout << age;
    }

    void setSerial(char * inputSerial){
        strcpy(serial, inputSerial);
    }

    void printSerial(){
        cout << serial;
    }

    void setGrade(int inputGrade, int year){
        if (year == 1) gradeFirst = inputGrade;
        else if (year == 2) gradeSecond = inputGrade;
        else if (year == 3) gradeThird = inputGrade;
        else if (year == 4) gradeForth = inputGrade;
    }

    int getGrade(int year){
        if (year == 1) return gradeFirst;
        else if (year == 2) return gradeSecond;
        else if (year == 3) return gradeThird;
        else if (year == 4) return gradeForth;
    }

};

int main(){

    char input[80] = {'\0'};

    // read
    cin >> input;
    Student A;

    char *temp = strtok(input, ",");
    A.setName(temp);

    temp = strtok(NULL, ",");
    A.setAge(atoi(temp));

    temp = strtok(NULL, ",");
    A.setSerial(temp);

    temp = strtok(NULL, ",");
    A.setGrade(atoi(temp), 1);

    temp = strtok(NULL, ",");
    A.setGrade(atoi(temp), 2);

    temp = strtok(NULL, ",");
    A.setGrade(atoi(temp), 3);

    temp = strtok(NULL, ",");
    A.setGrade(atoi(temp), 4);


    // print
    A.printName();
    cout << ',';
    A.printAge();
    cout << ',';
    A.printSerial();
    cout << ',';
    cout << (A.getGrade(1) + A.getGrade(2) + A.getGrade(3) + A.getGrade(4)) / 4 << endl;



    return 0;
}
