#include <gtest/gtest.h>
#include <string>

using namespace std;

struct Girl{
    string name;
    int age{};
    float faceScore{};
//1.
}girl1;

TEST(theStruct,creationWayAndStructArray) /* NOLINT */
{
    //2.
    struct Girl girl2;
    girl2.name = "甘雨";
    girl2.age = 3000;
    girl2.faceScore = 8.9;

    //3.
    //struct关键字可以省略
    Girl girl3 = {
            "可莉",
            12,
            6.8
    };

    Girl girls[3] = {
            girl1,
            girl2,
            girl3
    };
    for (const auto &item : girls){
        cout << item.age << endl;
    }
}

// 访问结构体指针的属性用 -> 符号
void printGirl(Girl* girl){
    cout << girl->name << endl;
    cout << girl->age << endl;
    cout << girl->faceScore << endl;
}

// 结构体在形参中的指针传递
// 还是老规矩尽量传指针不要传值，避免爆内存
TEST(theStruct,passThroughPointer) /* NOLINT */
{
    Girl girl = {
            "派蒙",
            20000,
            9
    };
    printGirl(&girl);
}

void editGirl(const Girl* girl){
//    girl->age = 19;
    cout << "edit JB" << endl;
}

// const修饰结构体防误触
TEST(theStruct,constQualified) /* NOLINT */
{
    Girl girl = {
            "胡桃",
            17,
            8.5
    };
    editGirl(&girl);
    printGirl(&girl);
}

