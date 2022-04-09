#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include "../model/Person.h"

using namespace std;

TEST(the_map, pair) /* NOLINT */
{
    pair<int, string> p1(1, "black nigger");
    cout << p1.first << endl;
    cout << p1.second << endl;
    pair<string, int> p2 = make_pair("nigga", 8964);
}

TEST(the_map, a) /* NOLINT */
{
    map<int, string> m1;
    m1.insert(pair<int, string>(1, "black nigger"));
    m1.insert(pair<int, string>(5, "black nigger"));
    m1.insert(pair<int, string>(2, "black nigger"));
    m1.insert(pair<int, string>(7, "black nigger"));
    for (const auto &item : m1) {
        cout << item.first << item.second << endl;
    }
    map<int, string> m2(m1);
    map<int, string> m3;
    m3 = m1;
}

TEST(the_map, size_swap) /* NOLINT */
{
    map<int, string> m1;
    cout << m1.empty() << endl;
    m1.insert(pair<int, string>(1, "black nigger"));
    m1.insert(pair<int, string>(5, "black nigger"));
    m1.insert(pair<int, string>(2, "black nigger"));
    cout << m1.size() << endl;

    map<string, int> m2;
    map<int, string> m3;
//    m1.swap(m2);
    m1.swap(m3);
}

TEST(the_map, insert_erase) /* NOLINT */
{
    map<int, string> m1;
    //插入方法1
    m1.insert(pair<int, string>(1, "nigger"));
    //插入方法2
    m1.insert(make_pair(2, "black slave"));
    //麻烦
    m1.insert(map<int, string>::value_type(3, "nigger slave"));
    //别用
    m1[4] = "black nigger";

    m1.erase(m1.begin());
    m1.erase(2);
    for (const auto &item : m1) {
        cout << item.first << item.second << endl;
    }
    m1.clear();
    cout << __cplusplus << endl;
}

TEST(the_map, find_count) /* NOLINT */
{
    map<int, string> m1;
    m1.insert(make_pair(6324, "black slave"));
    m1.insert(make_pair(4396, "black slave"));
    m1.insert(make_pair(2800, "简自狗"));
    m1.insert(make_pair(2800, "简自狗"));
    m1.insert(make_pair(2, "black slave"));

    auto it = m1.find(4396);
    if (it != m1.end()){
        cout << "已找到该元素" << endl;
        cout << (*it).first << (*it).second << endl;
    }

    cout << m1.count(2800) << endl;
}

namespace p6e{
    class comp{
    public:
        bool operator()(int a,int b) const{
            return a > b;
        }
    };
}
using namespace p6e;
TEST(the_map, sort) /* NOLINT */
{
    map<int, string, comp> m1;
    m1.insert(make_pair(6324, "black slave"));
    m1.insert(make_pair(4396, "black slave"));
    m1.insert(make_pair(443, "简自狗"));
    m1.insert(make_pair(2800, "简自狗"));
    m1.insert(make_pair(996, "black slave"));
    for (const auto &item : m1){
        cout << item.first << " " << item.second << endl;
    }

}


