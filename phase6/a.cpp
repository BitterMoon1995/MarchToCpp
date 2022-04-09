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

    //���ѿ���Ҫͨ�������������ſ��Է��ʡ��������е�����


    //1.���Թ�
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

    //4.ͨ��STL��for_each�㷨
    for_each(vec.begin(),vec.end(),pr);
}
