#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class Person{
    string name;
    int age{};
public:
    //构造函数可以有参数
    Person(){
        cout << "构造函数调用" << endl;
    };

    Person(const string &name, int age) : name(name), age(age) {
        cout << "有参（全参）构造调用" << endl;
    }

    Person(int age) : age(age) {
        cout << "有参（age）构造调用" << endl;
    }

    Person(const Person& person){
        name = person.name;
        age = person.age;
        cout << "拷贝构造函数调用" << endl;
    }
    //析构函数不能有参数
    ~Person(){
        cout << "析构函数调用" << endl;
    }

    friend ostream &operator<<(ostream &os, const Person &person) {
        os << "name: " << person.name << " age: " << person.age;
        return os;
    }
};

TEST(ctAndDect,alpha) /* NOLINT   构造函数与析构函数*/
{
    //默认调用无参构造
    Person person;
    //不要用括号法调用无参构造，空括号会被解释为函数声明
//    Person person1();
}

TEST(ctAndDect,withArgs) /* NOLINT   有参构造*/
{
    //括号调用有参构造
    Person person1("nigger",6);
    //显式调用有参构造
    Person person2 = Person("nigga",16);
    //隐式转换调用有参构造
    Person person3 = 25;
}

TEST(ctAndDect,anonymous) /* NOLINT    匿名对象*/
{
    //匿名对象
    Person("郑爽畜生",888);
    cout << "匿名对象会在其所在行执行完毕后立即回收" << endl;
}

TEST(ctAndDect,copy) /* NOLINT   拷贝构造*/
{
    Person person = Person("nigga",16);
    //括号调用拷贝构造
    Person person1(person);
    //显式
    Person person2 = Person(person);
    //隐式
    Person person3 = person;
}

void outPerson(Person person){
    cout << person << endl;
}

Person returnPerson(){
    Person person;
    return person;
}

/*
 * 时机：
 * 1.使用一个已创建的对象来初始化一个新对象
 * 2.值传递的方式给函数传递参数
 * 3.以值返回局部对象
 */
TEST(ctAndDect,timingOfCopy) /* NOLINT  拷贝构造的调用时机*/
{
//    Person nigger("尼哥", 20);
//    Person person1(nigger);
//    cout << person1 << endl;
//    outPerson(nigger);
    Person p = returnPerson();
    cout << (int*)&p << endl;
}

class Girl{
    int age;
    string name;

public:
//    Girl(int age, string name) : age(age), name(std::move(name)) {}

    Girl(Girl const &girl) {
    age = girl.age;
    name = girl.name;
    }

    friend ostream &operator<<(ostream &os, const Girl &girl) {
        os << "age: " << girl.age << " name: " << girl.name;
        return os;
    }
};

/* 默认构造函数：
 * 默认情况下，编译器至少给一个类添加3个构造函数：
 * 默认构造（无参、空实现）、默认析构（无参、空实现）、默认拷贝（值拷贝所有属性）
 *
 * 构造函数提供规则：
 * 如果用户定义有参构造，C++不再提供默认无参构造，但是会提供默认拷贝构造；
 * 如果用户定义拷贝构造，C++不再提供其他所有构造函数
 */
TEST(ctAndDect,ruleOfCstFunc) /* NOLINT  构造函数的调用规则*/
{
//    Girl girl1(14,"十四剑姬");
//    Girl girl2(girl1);
//    cout << girl2 << endl;

//    Girl girl;
}

class Game{
public:
    int price;
    double* revenue;

    Game(int price2, double revenue2) {
        price = price2;
        revenue = new double (revenue2);
    }

    /* 如果类有在堆区开辟的数据，要在析构函数中释放
     * delete 运算符，用以释放new运算符动态分配的内存空间，
     * 如果释放一个已经释放了的指针，堆区会报错。
     *
     * 释放一个指针，并不会使该指针的值变为 NULL。
     * */
    virtual ~Game() {
        if (revenue != nullptr){
            delete revenue;
            revenue = nullptr;
        }
        cout << "析构调用" << endl;
    }

    friend ostream &operator<<(ostream &os, const Game &game) {
        os << "price: " << game.price << " revenue: " << *game.revenue;
        return os;
    }

    Game(const Game& game_){
        price = game_.price;
        //深拷贝
        revenue = new double (*game_.revenue);
    }
};
/*
 * 默认拷贝构造函数为【浅拷贝】，
 * 在进行对象拷贝时，浅拷贝只会将源对象的所有属性的值赋值给新对象。
 *
 * 如果类中存在引用或指针属性，浅拷贝也只会将其值，即堆中某一对象的地址值赋值给新对象，
 * 导致新对象与源对象错误地完全共享了指针属性所指向的对象。
 *
 * 解决方法就是将拷贝函数改写为深拷贝，重新在堆区为新对象的指针属性创建对应的对象。
 */
TEST(ctAndDect,deepAndShallow) /* NOLINT  深拷贝与浅拷贝*/
{
    Game genshin(648, 1000000);
    Game wzry(genshin);
    *wzry.revenue *= 20;
    cout << wzry << endl;
}

class WhiteWoman{
    string name;
    int age;
    float score;

public:
    WhiteWoman(string name,int age,float score):name(name),age(age),score(score){
        cout << "爷：初始化列表构造" << endl;
    }

    friend ostream &operator<<(ostream &os, const WhiteWoman &woman) {
        os << "name: " << woman.name << " age: " << woman.age << " score: " << woman.score;
        return os;
    }
};

TEST(ctAndDect,initializedList) /* NOLINT  构造函数的初始化列表*/
{
    WhiteWoman whiteWoman("lucy",25,6.5);
    cout << whiteWoman << endl;
}
