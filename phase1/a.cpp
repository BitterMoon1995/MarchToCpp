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

TEST(dataType, array) /* NOLINT */
{
    string strArray[10];
    int intArr[10] = {6324,4396,2800};
    cout << intArr[3] << endl;
    // 不行！
//    cout << intArr[-1] << endl;
}

TEST(io, keyboardInput) /* NOLINT */
{
    int a = 0;
    cout << "请赋值：" << endl;
    cin >> a;
    cout << a << endl;
}

TEST(dataType, getType) /* NOLINT 获取变量的类型*/
{
    const int a = 10;
    auto e = &a;
    cout << typeid(a).name() << endl;
    cout << typeid(e).name() << endl;
}

/* decltype，在C++中，作为操作符，用于查询表达式的数据类型。
 * decltype在C++11标准制定时引入，主要是为泛型编程而设计，以解决泛型编程中，
 * 由于有些类型由模板参数决定，而难以（甚至不可能）表示之的问题。
 *
 * decltype并不会实际计算表达式的值，编译器分析表达式并得到它的类型。
 * 函数调用也算一种表达式，因此不必担心在使用decltype时真正的执行了函数。
 *
 * 当使用decltype(var)的形式时，decltype会直接返回变量的类型（包括顶层const和引用），不会返回变量作为表达式的类型。
 */
TEST(dataType, decltype_) /* NOLINT declared type操作符*/
{
    const int ci = 0, &cj = ci;

    // x的类型是const int
    decltype(ci) x = 0;
    cout << typeid(x).name() << endl;

    // y的类型是const int &
    decltype(cj) y = x;
    cout << typeid(y).name() << endl;
}

/* 您可以使用 typedef 为一个已有的类型取一个新的名字。*/
TEST(dataType, the_typedef) /* NOLINT 获取变量的类型*/
{
    typedef string nigger;
    nigger n1 = "Jack";
    nigger n2 = "Mike";
    cout << n1 << endl;
}