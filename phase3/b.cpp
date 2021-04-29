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


