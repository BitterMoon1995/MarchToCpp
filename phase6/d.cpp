#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include "../model/Person.h"

using namespace std;

template<class T>
void prset(set<T>& set){
    for (const auto &item : set){
        cout << item << endl;
    }
}

TEST(the_set,a) /* NOLINT */
{
    set<int> set1;
    set1.insert(4);
    set1.insert(1);
    set1.insert(2);
    set1.insert(2);
    set1.insert(2);

    set1.insert(3);
    prset<int>(set1);

    set<int> set2(set1);
    set<int> set3;
    set3 = set1;
}

namespace p5c{
    class comp{
    public:
        bool operator()(const int& a,const int& b){
            return a > b;
        }
    };
}
using namespace p5c;

class cmp {
public:
    //重载 () 运算符
    bool operator ()(const string &a,const string &b) const{
        //按照字符串的长度，做升序排序(即存储的字符串从短到长)
        return  (a.length() < b.length());
    }
    bool operator()(const int &a,const int &b) const{
        return a > b;
    }
    bool operator()(const Person &a,const Person &b) const{
        return a.age > b.age;
    }
};

TEST(the_set,editSortRule) /* NOLINT 修改默认排序规则，变为从大到小排序*/
{
    set<int,cmp> set1;
    set1.insert(4);
    set1.insert(5);
    set1.insert(2);
    set1.insert(7);
    for (const auto &item : set1){
        cout << item << endl;
    }
}

// 自定义类型必须指定排序方式
TEST(the_set,diyTypesSort) /* NOLINT 自定义类型的排序*/
{
    set<Person,cmp> set1;
    Person p1("腕豪",20);
    Person p2("狗头",1000);
    Person p3("石头人",500);
    Person p4("乌鸦",40);
    set1.insert(p1);
    set1.insert(p2);
    set1.insert(p3);
    set1.insert(p4);
    for (const auto &item : set1){
        cout << item.name << " " << item.age << endl;
    }
}