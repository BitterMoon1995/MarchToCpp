#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>
#include <fstream>

using namespace std;

TEST(fileOperate, write) /* NOLINT */
{
    //1.����������
    ofstream ofs;
    //2.ָ��·�����򿪷�ʽ

    /*
     * ���Ƶ���õ�·��������ʱ�򣬡�\\����Ҫ�ֶ����ʮ���鷳���������һ��C++�������ԡ���Դ��ת�롣
     * ����ָ��������Դ����б��룬���������Ƿ�ΪC\C++�����ķ��ţ�ʹ�÷������£�
     */
    ofs.open(R"(E:\Cpp Projects\Diluc\phase4\test.txt)", ios::out);
//    ofs.open("E:\\Cpp Projects\\Diluc\\phase4\\test.txt",ios::out);

    //3.д������
    ofs << "president zhou said that" << endl;
    ofs << "we must kill all black nigger" << endl;
    //4.�ر������
    ofs.close();
}

TEST(fileOperate, read) /* NOLINT */
{
    ifstream ifs;
    ifs.open(R"(E:\Cpp Projects\Diluc\phase4\test.txt)", ios::in);
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //������
    //1.���û�������
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