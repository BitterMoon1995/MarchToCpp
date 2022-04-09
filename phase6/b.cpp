#include <string>
#include <gtest/gtest.h>
#include <algorithm>
#include "../model/Person.h"

using namespace std;

TEST(the_string,constructor) /* NOLINT */
{
    string s1 = string();
    string s2 = string("nigger");
    string s3 = string(s2);
    string s4 = string(10,'n');
    cout << s4 << endl;
}

//可用 = 或 assign()
TEST(the_string,assign) /* NOLINT 赋值操作*/
{
    string s1;
    s1 = "hello black nigger";
    string s2;
    s2 = s1;
    string s3;
    s3 = 'n';
    string s4;
    s4.assign(s1);
    string s5;
    s5.assign(s1,5);
    cout << s5 << endl;
    string s6;
    s6.assign(8,'n');
}

TEST(the_string,append) /* NOLINT 拼接/追加操作*/
{
//    string s1 = "take my nigger to farm,";
//    s1 += "to pick cotton、";
//    cout << s1 << endl;
//    s1.append("kill nigger");
//    cout << s1 << endl;

    string s2 = "nnnnniggaaaaaaaa";
    string s3 = "black";
    s3.append(s2,4);
    cout << s3 << endl;
    string s4 = "black";
    s4.append(s2,4,5);
    cout << s4 << endl;
}

TEST(the_string,findAndReplace) /* NOLINT 查找/替换*/
{
    string s1 = "nigga don`t hate me cause I`m beautiful nigga,"
                      "maybe you got your yeeyee ass hair cut you got"
                      "some bitches on your dick";
    cout << s1.find("dick",0) << endl;
    cout << s1.rfind("me",117) << endl;
    cout << s1.replace(0,5,"nigger") << endl;
}

TEST(the_string,compare) /* NOLINT 比较*/
{
    string s1 = "aaa";
    string s2 = "aba";
    string s3 = "aaa";
    cout << s1.compare(s2) << endl;
    cout << s1.compare(s3) << endl;
}

TEST(the_string,access) /* NOLINT 存取元素*/
{
    string s1 = "If you're gonna be bad, be bad with purpose. Otherwise you're just not worth forgiving.";
    cout << s1[4] << endl;
    cout << s1.at(0) << endl;
}

TEST(the_string,insert) /* NOLINT 插入*/
{
    string s1 = "black";
    cout << s1.insert(5," nigger") << endl;
    cout << s1.erase(0,2) << endl;
}

TEST(the_string,substring) /* NOLINT 插入*/
{
    string s = "stupid white pig";
    cout << s.substr(6,10) << endl;
}