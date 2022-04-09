#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include "../model/Person.h"

using namespace std;

template<class T>
void pv(vector<T> v) {
    for (auto &item : v) {
        cout << item << " ";
    }
    cout << endl;
}

template<class T>
void psc(vector<T> v){
    cout << "大小：" <<v.size() << endl;
    cout << "容量：" << v.capacity() << endl;
}


TEST(the_vector, constructor) /* NOLINT */
{
    vector<int> v1;
    v1.reserve(10);
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    pv<int>(v1);

    vector<int> v2(v1.begin() + 1,v1.end());
    pv(v2);

    vector<int> v3(10,2800);
    pv<int>(v3);

    vector<int> v4(v1);
    pv<int>(v4);
}

TEST(the_vector, assign) /* NOLINT */
{
    vector<int> v1;
    v1.reserve(10);
    for (int i = 0; i < 10; i++) {
        v1.push_back(i * 2);
    }
    vector<int> v2;
    v2 = v1;
    vector<int> v3;
    v3.assign(v1.begin() + 1,v1.end() - 1);
    vector<int> v4;
    v4.assign(5,4396);

    pv<int>(v1);
    pv<int>(v2);
    pv<int>(v3);
    pv<int>(v4);
}

TEST(the_vector, capacityAndSize) /* NOLINT */
{
    vector<int> v1;
    cout << v1.empty() << endl;
    v1.reserve(10);
    cout << v1.empty() << endl;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    cout << v1.empty() << endl;

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

    v1.resize(5);
    pv<int>(v1);
    v1.resize(10,4396);
    pv<int>(v1);
}

TEST(the_vector, insert_erase) /* NOLINT */
{
    vector<int> v1;
    v1.reserve(10);
    cout << (v1.begin() == v1.end()) << endl;
    for (int i = 0; i < 19; i++) {
            v1.push_back(i + 4396);
    }
    v1.pop_back();
    v1.insert(v1.begin(),2800);
    v1.insert(v1.end(),4396);
    pv<int>(v1);
    cout << (v1.end() - v1.begin()) << endl;

    //将所有偶数变为520
    v1.clear();

    psc<int>(v1);
    cout << (v1.begin() == v1.end()) << endl;
}

TEST(the_vector, index) /* NOLINT */
{
    vector<int> v1;
    v1.reserve(10);
    for (int i = 0; i < 10; i++) {
        v1.push_back(i + 4396);
    }

    cout << v1.at(5) << endl;
    cout << v1[8] << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
}

TEST(the_vector, swap) /* NOLINT */
{
    vector<int> v1;
    v1.reserve(5);
    for (int i = 0; i < 5; i++) {
        v1.push_back(4396);
    }
    vector<int> v2;
    v2.reserve(10);
    for (int i = 0; i < 10; i++) {
        v2.push_back(2800);
    }
    pv<int>(v1);
    v1.swap(v2);
    pv<int>(v1);
}
TEST(the_vector, swap_use) /* NOLINT */
{
    vector<int> v1;
    v1.reserve(100000);
    for (int i = 0; i < 100000; i++) {
        v1.push_back(i);
    }
    psc<int>(v1);
    v1.resize(3);
    //巧用拷贝构造+匿名对象+swap收缩容器
    vector<int>(v1).swap(v1);
    v1.shrink_to_fit();
    psc<int>(v1);

}