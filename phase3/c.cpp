#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class iPad2021{
public:
    static int total_sale_volume;

    int price;

    //静态成员函数是类的一个特殊的成员函数
    //静态成员函数属于整个类所有，没有this指针
    //静态成员函数只能直接访问静态成员变量和静态成员函数
    //可以通过类名直接访问类的公有静态成员函数
    //可以通过对象名访问类的公有静态成员函数
    //定义静态成员函数，直接使用static关键字修饰即可
    static void saleReport(){
        cout << "热烈祝贺ipad2021总销量为：" << total_sale_volume << endl;
//        cout << price << endl;
    }

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
TEST(objectModel,staticParam) /* NOLINT */
{
    //Definition or redeclaration of 'total_sale_volume' not allowed inside a function
//    int iPad2021::total_sale_volume = 98;

    iPad2021 myipad1;

//    iPad2021 myipad2;
//    cout << iPad2021::total_sale_volume++ << endl;//通过类名直接调用公有静态成员变量
//    cout << myipad1.total_sale_volume-- << endl;//Static member accessed through instance
//    cout << myipad2.total_sale_volume << endl;

    iPad2021::saleReport();
    myipad1.saleReport();
}

class Nigga{
public:

    Nigga(float income){
        income = income;
    }

    Nigga(int age,float income) {
        this->age = age;
        this->income = income;
    }

    //非静态成员变量，属于实例
    int age;
    float income;
    static int value;//静态成员变量，属于类，不占实例的内存空间
    //★非静态成员函数，属于类。所有对象共用同一个函数，用this区分
    Nigga * suicide(){
        cout << age << "岁nigger正义自杀" << endl;
        return this;
    }
    //静态成员函数，属于类
    static void bees2(){
        cout << "nigger死妈了" << endl;
    }
};
int Nigga::value = 0;

TEST(objectModel,belonging) /* NOLINT 关于类各个成员的归属*/
{
    //空对象占用1字节内存空间
    Nigga nigga(11);

    cout << sizeof(nigga) << endl;
}
/*
 * this指针：指向被调用的成员函数所属的对象。
 * 用途：1.帮助区分同名的成员函数参数和成员变量
 *      2.在实例成员函数中返回实例本身
 */
TEST(objectModel,thisPointer) /* NOLINT */
{
    //在构造函数中，如果参数名和成员变量名相同，又不加this，编译器无法区分
//    Nigga nigga(-2880.9f);
//    cout << nigga.income << endl;

    //通过this->age，让编译器区分同名的成员函数参数与成员变量
    Nigga nigger(22,-200.5f);
    cout << nigger.age << endl;
    Nigga* jack = nigger.suicide();
    cout << jack->income << end;
}

