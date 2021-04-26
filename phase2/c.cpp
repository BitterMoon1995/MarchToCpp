#include <gtest/gtest.h>
using namespace std;

int t1(int a,int b = 20,int c = 30){
    return a + b +c;
}

int alpha(int a = 10,int b = 10);

int alpha(int a,int b){
    return a + b;
};
/*
 * 函数形参可以有默认值，该形参可以不传值。
 * 如果一个参数具有默认值，其右的所有参数都必须要有默认值。
 * 函数声明和函数实现不能同时具有默认参数。
 */
TEST(advancedFunction,defaultArgs) /* NOLINT */
{
    cout << t1(1) << endl;
    cout << t1(1,2) << endl;
    cout << alpha() << endl;
}

void t2(int a,int ){
    cout << a << endl;
}

TEST(advancedFunction,placeholder) /* NOLINT */
{
    t2(10,20);
}

void nigger(string name){
    cout << name << endl;
}

void nigger(string name,int age){
    cout << name << endl;
    cout << age << endl;
}

void nigger(int age,string name){
    cout << name << endl;
    cout << age << endl;
}

/*
 * 函数名可以相同，提高复用性。
 * 条件：1.同一个作用域下 2.名字相同  3.参数不同  *4.跟返回值无关
 */
TEST(advancedFunction,reload) /* NOLINT */
{
    nigger("jack");
    nigger("jackson",16);
    nigger(12,"harry");
}

int t3(int& a){
    return a * 2;
}

int t3(const int& a){
    return a * 3;
}

void t4(int a){
    cout << a << endl;
}

//void f4(int a = 10){
//    cout << "f4调用" << endl;
//}

void t4(int a,int b = 10){
    cout << a + b << endl;
}
/*
 * 引用与与其数据类型相同的常量引用可以作为函数重载的条件，
 * 调用时，看入参。
 *
 * 默认参数的存在可能导致函数重载非法。
 */
TEST(advancedFunction,reload_detail) /* NOLINT */
{
    int a = 2;
    cout << t3(2) << endl;
    cout << t3(a) << endl;

//    t4(1);
}
