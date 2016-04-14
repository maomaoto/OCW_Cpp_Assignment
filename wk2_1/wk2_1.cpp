/*
    wk 2-1 簡單的學生訊息處理程序實現
    描述：
        在一個學生訊息處理程序中，要求實現一個代表學生的類，並且所有的成員變量都應該是私有的。
    輸入：
        姓名、年齡、學號、第一學年平均成績、第二學年平均成績、第三學年平均成績、第四學年平均成績。
        其中姓名、學號為字符串，不含空格和逗號；年齡為正整數；成績為非負整數。
        各部分內容之間均用單個英文逗號","隔開，無多餘空格。
    輸出：
        一行，按順序輸出：姓名、年齡、學號、四年平均成績(向下取整)。
        各部分內容均用單個英文逗號","隔開，無多餘空格。

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
