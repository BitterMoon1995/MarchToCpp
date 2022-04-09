#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include "../model/Person.h"

using namespace std;

void pr(int v){
    cout << v << endl;
}

TEST(C_I_A,a) /* NOLINT */
{
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(6);

    //不难看出要通过【迭代器】才可以访问【容器】中的数据


    //1.简自狗
//    auto begin = vec.begin();
//    auto end = vec.end();
//    while (begin != end){
//        cout << *begin << endl;
//        begin++;
//    }

    //2.bang
//    for (auto begin = vec.begin(); begin != vec.end(); begin++) {
//        cout << *begin << endl;
//    }

    //3.gala
//    for (int & begin : vec) {
//        cout << begin << endl;
//    }

    //4.通过STL的for_each算法
    for_each(vec.begin(),vec.end(),pr);
}
