#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include "../model/Person.h"

using namespace std;

namespace p7a1{
    class Add{
    public:
        //记录被调用的次数
        int invokeTime;

        Add() {
            invokeTime = 0;
        }

        int operator() (int a,int b){
            invokeTime++;
            return a + b;
        }
    };
}
/*
 * 函数对象相当于函数的高明之处在于，作为类，它可以有额外的状态
 */
using namespace p7a1;
TEST(functionObj,functionWithStatus) /* NOLINT */
{
    Add add;
    add(1,1);
    add(1,1);
    add(1,1);
    add(1,1);
    cout << add.invokeTime << endl;
}

void addMingKai(Add& add,int i){
    cout << add(i,4396) << endl;
}

/*
 * 函数对象还可以作为参数传递，这也是普通函数所不能触摸的
 */
TEST(functionObj,passbyAsArgs) /* NOLINT */
{
    Add add;
    addMingKai(add,1);
}

namespace p7a2{
    class GT5{
    public:
        bool operator()(int i){
            return i > 5;
        }
    };
    class Sort{
    public:
        bool operator()(int a,int b){
            return a > b;
        }
    };
}
/*
 * 返回bool类型的仿函数称为谓词
 * 内置算法find_if的第三个参数就是一个一元谓词
 */
using namespace p7a2;
TEST(functionObj,unitaryPredicate) /* NOLINT 一元谓词*/
{
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    GT5 gt5;
    /* 从find_if算法的源码不难看出，如果没找到会返end。
     * 如果找到，会返回第一个找到的迭代器
     */
    auto res = find_if(v.begin(),v.end(),gt5);
    if (res != v.end()){
        cout << "已找到大于5的" << endl;
        cout << *res << endl;
    }
}

TEST(functionObj,binaryPredicate) /* NOLINT 二元谓词*/
{
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    Sort sort;
    std::sort(v.begin(),v.end(),sort);
    for (const auto &item : v){
        cout << item << endl;
    }
}

template<typename T>
T nigger(T t){
    return -t;
}

//内建仿函数之算术仿函数
TEST(functionObj,builtIn_arithmetic) /* NOLINT */
{
    cout << nigger(1.2) << endl;

    negate n;
    cout << n(50.98) << endl;

    plus p;
    cout << p(1,3) << endl;
}

//关系仿函数
TEST(functionObj,builtIn_relationship) /* NOLINT */
{
    int a = 2800;
    int b = 4396;
    greater_equal ge;
    cout << ge(a,b) << endl;
    less l;
    cout << l(a,b) << endl;
}

//逻辑仿函数
TEST(functionObj,builtIn_logic) /* NOLINT */
{
    bool a = true;
    bool b = false;
    logical_and la;
    cout << la(a,b) << endl;
}

