#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>
#include <fstream>

using namespace std;

TEST(fileOperate, write) /* NOLINT */
{
    //1.创建流对象
    ofstream ofs;
    //2.指定路径、打开方式

    /*
     * 如果频繁用到路径检索的时候，“\\”需要手动添加十分麻烦，这里介绍一种C++的新特性——源码转译。
     * 就是指按照字面源码进行编译，不再区分是否为C\C++保留的符号，使用方法如下：
     */
    ofs.open(R"(E:\Cpp Projects\Diluc\phase4\test.txt)", ios::out);
//    ofs.open("E:\\Cpp Projects\\Diluc\\phase4\\test.txt",ios::out);

    //3.写入内容
    ofs << "president zhou said that" << endl;
    ofs << "we must kill all black nigger" << endl;
    //4.关闭输出流
    ofs.close();
}

TEST(fileOperate, read) /* NOLINT */
{
    ifstream ifs;
    ifs.open(R"(E:\Cpp Projects\Diluc\phase4\test.txt)", ios::in);
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    //读数据
    //1.利用缓冲数组
//    char buf[1024] = {0};
//    while (ifs >> buf)
//        cout << buf << endl;

    //2.
    char buf[1024] = {0};
    while (ifs.getline(buf, 100))
        cout << buf << endl;
    ifs.close();

    //3.
//    string buf;
//    while (getline(ifs,buf))
//        cout << buf << endl;

    //4.
//    char c;
//    while ((c=ifs.get()) != EOF)
//        cout << c << endl;
}

namespace file {
    class Person2 {
    public:
        string personName;
        int age;

        Person2() {}

        Person2(string personName, int age) : personName(std::move(personName)), age(age) {}

        friend ostream &operator<<(ostream &os, const Person2 &Person2) {
            os << "personName: " << Person2.personName << " age: " << Person2.age;
            return os;
        }
    };
}
using namespace file;
TEST(fileOperate, binaryWrite) /* NOLINT */
{
    ofstream ofs;
    ofs.open(R"(E:\Cpp Projects\Diluc\phase4\binary.txt)", ios::out | ios::binary);
    auto *person2 = new Person2("nigger", 23);
    ofs.write((const char *) person2, sizeof(*person2));
    delete person2;
    ofs.close();
}

TEST(fileOperate, binaryRead) /* NOLINT */
{
    ifstream ifs;
    ifs.open(R"(E:\Cpp Projects\Diluc\phase4\binary.txt)", ios::in | ios::binary);
    if (!ifs.is_open()) {
        return;
    }
    auto *p = new Person2;
    ifs.read((char *) p, sizeof(Person2));
    cout << *p << endl;
    ifs.close();
}