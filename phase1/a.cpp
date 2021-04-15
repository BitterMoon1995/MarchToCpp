#include <gtest/gtest.h>

#define b 4396
using namespace std;

TEST(valueDeclare, variable)/* NOLINT */
{
    int a = 10;
    cout << "a = " << a << endl;
}

TEST(valueDeclare, constant) {/* NOLINT */
    cout << b << endl;
    const int c = 6324;
    cout << c << endl;

//    b = 6;
//    c = 9;
}

TEST(dataType, integer)/* NOLINT */
{
    cout << sizeof(short) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
}

TEST(dataType, realNumber) /* NOLINT */
{
//    cout << sizeof(float ) << endl;
//    cout << sizeof(double ) << endl;

//    float f = 4396.8964f;
//    cout << f << endl;
//    double d = 4396.8964;
//    cout << d << endl;

    double d = 3e2;
    cout << d << endl;
    double d2 = 3e-2;
    cout << d2 << endl;
}

TEST(dataType, charType) /* NOLINT */
{
    char a = 'a';
    cout << a + 1 << endl;
    cout << sizeof(a) << endl;
}

TEST(dataType, stringType) /* NOLINT */
{
    //c风格
    char s1[] = "black nigger";
    cout << s1 << endl;
    //c++风格
    string s2 = "black slave";
    cout << s2 << endl;
}

TEST(dataType, boolType) /* NOLINT */
{
    bool flag = true;
    cout << flag << endl;
    bool imNigger = false;
    cout << imNigger - 1 << endl;
}

TEST(io, keyboardInput) /* NOLINT */
{
    int a = 0;
    cout << "请赋值：" << endl;
    cin >> a;
    cout << a << endl;
}

