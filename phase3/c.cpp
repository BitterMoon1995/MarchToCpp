#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class iPad2021{
public:
    static int total_sale_volume;

    friend ostream &operator<<(ostream &os, const iPad2021 &pad2021) {
        return os;
    }
};
//类的静态成员变量需要在类外分配内存空间
int iPad2021::total_sale_volume = 998;

/*
-静态成员变量属于整个类所有
-静态成员变量的生命期不依赖于任何对象，为程序的生命周期
-可以通过类名直接访问公有静态成员变量
-所有对象共享类的静态成员变量
-可以通过对象名访问公有静态成员变量
-静态成员变量需要在类外单独分配空间
-静态成员变量在程序内部位于全局数据区 (Type className::VarName = value)
 */
TEST(staticMember,staticParam) /* NOLINT */
{
    //Definition or redeclaration of 'total_sale_volume' not allowed inside a function
//    int iPad2021::total_sale_volume = 98;
    iPad2021 myipad1;
    iPad2021 myipad2;
    cout << iPad2021::total_sale_volume++ << endl;//通过类名直接调用公有静态成员变量
    cout << myipad1.total_sale_volume-- << endl;//Static member accessed through instance
    cout << myipad2.total_sale_volume << endl;
}