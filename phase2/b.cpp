#include <gtest/gtest.h>
using namespace std;

/*
 * 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。
 * 一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

 * 从使用角度上讲，引用变量就是它引用的变量【本身】。
 *
 * 本质上，引用的本质是它引用的变量的指针常量（type* const p）。不过编译器在发现这个指针是引用的时候，
 * 会自动为其解引用，所以引用无需写 * 。
 * c++推荐引用技术，以简化指针的操作。
 */

TEST(reference,alpha) /* NOLINT */
{
    int a = 10;
    int& b = a;

    cout << b << endl;
    b = 4396;
    cout << a << endl;

    int& c = a;
    //a就是b，b就是c
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
}

TEST(reference,notice) /* NOLINT */
{
    //引用必须初始化
//    int& a;

    //引用初始化后，引用对象不可以改变
    int a = 10;
    int& b = a; //编译器：int* const b = a
    b++;//编译器：(*b)++，省略了*
    int c = 20;
    b = c;//仅仅是个赋值操作
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
//形参的a是实参a的引用，只不过这个引用的别名和原名是一样的
void swap(int& a,int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

TEST(reference,asArguments) /* NOLINT */
{
    int a = 10;
    int b = 4396;
    swap(a,b);
    cout << a << b << endl;
}

int& t1(){
    int a = 10;
    return a;
}

int& t2(){
    static int a = 10;
    return a;
}
/*
 * 当函数返回一个引用时，则返回一个指向返回值的隐式指针。
 */
TEST(reference,asReturnValue) /* NOLINT */
{
    //不要引用返回的局部变量
    //ref所引用的a在t1()执行完后就释放了
//    int& ref = t1();
    int& ref = t2();
    cout << ref << endl;
    cout << ref << endl;

    //当引用作函数的返回值且并非引用局部变量时，该函数的调用可以作左值，
    //因为对该函数调用的操作就是对该引用所引用的变量本身进行操作
    t2() = 4397;
    cout << ref << endl;
    cout << ref << endl;
}

void showVal(const int& x){
//    x++;
    cout << x << endl;
}

TEST(reference,constReference) /* NOLINT */
{
    //引用【并不能】引用全局区-常量区の量
//    int& x =4396;

    //编译器：int temp = 10;const int* const x = temp
    const int& x = 43960;

    //不可以通过修改常量引用来修改被引用量的值
//    x += 7;
    cout << x << endl;

    //常量引用的主要用途：修饰形参防止误操作
    int y = 8848;
    showVal(y);
}
