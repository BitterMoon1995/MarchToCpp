#include <gtest/gtest.h>
#include "nigga.h"

using namespace std;

//函数在使用之前要先声明，否则 Use of undeclared identifier 'myMax
int myMax(int a, int b);

TEST(complexStructure, arr) /* NOLINT */
{
//    int arr[5] = {1,2,3,4,5};
//    for (const auto &item : arr){
//        cout << item << endl;
//    }

    double niggers[5];
    niggers[0] = 4;
    niggers[1] = 3;
    niggers[2] = 9;
    niggers[3] = 6;
    niggers[4] = 7;
    //const防止误操作
    for (const double item : niggers) {
        cout << item << endl;
    }
}

TEST(complexStructure, pointer) /* NOLINT */
{
//    cout << sizeof(char *) << endl;
//    cout << sizeof(int *) << endl;
//    cout << sizeof(long *) << endl;
//    cout << sizeof(long long *) << endl;

    // 关于const修饰指针
    int a = 10;
    int b = 20;
    /*1.常量指针
     * 指针的指向（指针的值）可以修改，指针指向的对象的值不可以修改（不可以通过*p = x修改指针p指向的对象的值）*/
    const int* p = &a;
    p = &b;
//    *p = 4396;错误

    /*2.指针常量
     * 指针的指向不可以修改，指针指向的对象的值可以修改（可以通过*p修改所指向的对象的值）*/
    int* const p2 = &a;
//    p2 = &b;
    *p2 = 6324;

    /*3.反冲斗士*/
    const int* const p3 = &a;
//    p3 = &b;
//    *p3 = 2800;

    cout << *p << endl;
}

int myMax(int a, int b) {
    return a > b ? a : b;
}

TEST(complexStructure, function) /* NOLINT */
{
    int a = 1;
    int b = 2;
//    mySwap(&a, &b);
//    cout << a << "\n" << b << endl;

    cout << myMax(a, b) << endl;

}

