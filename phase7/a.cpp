#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include "../model/Person.h"

using namespace std;

namespace p7a1{
    class Add{
    public:
        //��¼�����õĴ���
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
 * ���������൱�ں����ĸ���֮�����ڣ���Ϊ�࣬�������ж����״̬
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
 * �������󻹿�����Ϊ�������ݣ���Ҳ����ͨ���������ܴ�����
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
 * ����bool���͵ķº�����Ϊν��
 * �����㷨find_if�ĵ�������������һ��һԪν��
 */
using namespace p7a2;
TEST(functionObj,unitaryPredicate) /* NOLINT һԪν��*/
{
    vector<int> v;
    v.reserve(10);
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    GT5 gt5;
    /* ��find_if�㷨��Դ�벻�ѿ��������û�ҵ��᷵end��
     * ����ҵ����᷵�ص�һ���ҵ��ĵ�����
     */
    auto res = find_if(v.begin(),v.end(),gt5);
    if (res != v.end()){
        cout << "���ҵ�����5��" << endl;
        cout << *res << endl;
    }
}

TEST(functionObj,binaryPredicate) /* NOLINT ��Ԫν��*/
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

//�ڽ��º���֮�����º���
TEST(functionObj,builtIn_arithmetic) /* NOLINT */
{
    cout << nigger(1.2) << endl;

    negate n;
    cout << n(50.98) << endl;

    plus p;
    cout << p(1,3) << endl;
}

//��ϵ�º���
TEST(functionObj,builtIn_relationship) /* NOLINT */
{
    int a = 2800;
    int b = 4396;
    greater_equal ge;
    cout << ge(a,b) << endl;
    less l;
    cout << l(a,b) << endl;
}

//�߼��º���
TEST(functionObj,builtIn_logic) /* NOLINT */
{
    bool a = true;
    bool b = false;
    logical_and la;
    cout << la(a,b) << endl;
}

