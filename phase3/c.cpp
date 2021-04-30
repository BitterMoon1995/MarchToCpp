#include <gtest/gtest.h>
#include <string>
#include <utility>

using namespace std;

/** 对象作属性、静态成员、this、const修饰方法等等 */

class Phone{
    string name;
    int price;

public:
    Phone() {};

    Phone(string name, int price) : name(std::move(name)), price(price) {}
};

class JK{
    string name;
    int age;
    Phone phone;

public:
    JK(string name, int age, Phone phone) : name(std::move(name)), age(age), phone(std::move(phone)) {}
};

TEST(ClassAdvanced,objectAsMember) /* NOLINT 对象成员：类对象作类的成员*/
{

}