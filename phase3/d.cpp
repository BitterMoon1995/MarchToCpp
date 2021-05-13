#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class Palace;
/*
 * 类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
 * 尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
 * 友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

 * 1.全局函数作友元 2.成员函数作友元 3.类中定义友元函数
 *
 * 盘点十大不用成员函数作友元的理由：
 * 以类A的func a(B b)作类B的友元成员函数为例，需满足
 * 1.类B需在A之前前置声明，否则函数参数非法
 * 2.类A需在B实现之前实现，否则友元声明非法
 * 3.函数a需在B实现之后实现，否则该函数中对类B的私有成员访问非法
 * 所以顺序必须是：B声明——A实现且a声明——B实现——a实现，这下麻了
 */
class Ladybro{
public:
    void visit(const Palace& palace);
};

class Palace{
    string bedroom;
    double cost;

    //友元函数在类中声明
    //使某一类或函数可以访问目标类的私有成员：将函数或类的声明写在目标类中用friend修饰即可
    //如何让全局函数myNigga进入公主の闺房？
    friend void myNigga(Palace &house);
    //声明友元类
    friend class Nigger;
    //声明友元成员函数
    friend void Ladybro::visit(const Palace& palace);

public:
    string livingRoom;

    Palace();

    Palace(string bedroom, string livingRoom) : bedroom(std::move(bedroom)), livingRoom(std::move(livingRoom)) {}

    Palace(string bedroom, string livingRoom, double cost) : bedroom(std::move(bedroom)), cost(cost),
                                                                                   livingRoom(std::move(livingRoom)) {}
    //友元函数在类中定义，不能用作用域解析运算符。不是成员函数不是成员函数不是成员函数，也不能被继承
    friend void princeVisit(Palace& palace){
        cout << "【王子】买城堡花费：" << endl;
        cout << palace.cost << endl;
    }
};

void Ladybro::visit(const Palace& palace) {
    cout << "【骚闺蜜】访问小骚公主的：" << endl;
    cout << palace.bedroom << endl;
}

void myNigga(Palace& house){
    cout << house.livingRoom << endl;
    cout << house.bedroom << endl;
}

TEST(the_friend,globalFunctionAsFriend) /* NOLINT */
{
    Palace princessPalace("公主卧室", "公主客厅");
    myNigga(princessPalace);
}

class Nigger{
public:
    void visit(Palace palace);
};


//如何评价爷在类外实现成员函数？
void Nigger::visit(Palace palace) {
    cout << "【黑鬼】访问：" << endl;
    cout << palace.bedroom << endl;
}

TEST(the_friend,classAsFriend) /* NOLINT */
{
    Palace princessPalace("公主卧室", "公主客厅");
    Nigger nigger;
    nigger.visit(princessPalace);
}

TEST(the_friend,memberFunctionAsFriend) /* NOLINT */
{
    Palace princessPalace("公主卧室", "公主客厅");
    Ladybro ladybro;
    ladybro.visit(princessPalace);
}

TEST(the_friend,declareInClass) /* NOLINT 友元函数在类中定义*/
{
    Palace ladyWeier("公主卧室", "公主客厅",580000000);
    princeVisit(ladyWeier);
}
