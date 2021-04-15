#include <gtest/gtest.h>

using namespace std;

#define nigger "nigger"

int clearlove = 4396;
const int uzi = 2800;

TEST(FourRegion, globalArea) /* NOLINT */
{
    int a = 1;
    cout << "局部变量：" << &a << endl;
    const int xiaohu = 2800;
    cout << "局部常量：" << &xiaohu << endl;

    //全局区
    //全局区中主要存放的数据有：全局变量、静态变量、常量(如字符串常量)

    cout << "全局变量：" << &clearlove << endl;
    cout << "宏：" << &nigger << endl;

    static int sa = 89;
    cout << "静态变量：" << &sa << endl;

    cout << "字符串常量：" << &("nigger si ma") << endl;

    cout << "全局常量：" << &uzi << endl;
}

int* t1(int i){
    i = 100;
    int a = 998;
    return &a;
}

//栈区
//由编译器自动分配释放，存放函数的形参、局部变量等。当函数执行完毕时自动释放。
//不要在函数中返回局部变量的指针，因为局部变量会在函数执行后销毁，该指针指向的地址是无效的。
TEST(FourRegion,stack) /* NOLINT */
{
    int* p = t1(8);
    cout << *p << endl;//*p会被编译器保留1次
    cout << *p << endl;
}

int* t2(){
    //利用new操作符在堆区开辟内存，返回的是该数据类型的指针
    return new int(10);
}

//堆区
//由程序员分配释放，或者在程序终止后，由操作系统回收。
TEST(FourRegion,heap) /* NOLINT */
{
    int* p = t2();
    cout << *p << endl;
    cout << *p << endl;
    //用delete释放堆区的数据
    delete p;
    cout << *p << endl;
    cout << &p << endl;
}

TEST(FourRegion,newArrayInHeap) /* NOLINT */
{
    int* arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << endl;
    }
    //delete释放数组空间的时候必须加[]
    delete[] arr;
}
