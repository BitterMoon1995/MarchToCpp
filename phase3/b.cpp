#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class Person{
    string name;
    int age{};
public:
    //���캯�������в���
    Person(){
        cout << "���캯������" << endl;
    };

    Person(const string &name, int age) : name(name), age(age) {
        cout << "�вΣ�ȫ�Σ��������" << endl;
    }

    Person(int age) : age(age) {
        cout << "�вΣ�age���������" << endl;
    }

    Person(const Person& person){
        name = person.name;
        age = person.age;
        cout << "�������캯������" << endl;
    }
    //�������������в���
    ~Person(){
        cout << "������������" << endl;
    }

    friend ostream &operator<<(ostream &os, const Person &person) {
        os << "name: " << person.name << " age: " << person.age;
        return os;
    }
};

TEST(ctAndDect,alpha) /* NOLINT   ���캯������������*/
{
    //Ĭ�ϵ����޲ι���
    Person person;
    //��Ҫ�����ŷ������޲ι��죬�����Żᱻ����Ϊ��������
//    Person person1();
}

TEST(ctAndDect,withArgs) /* NOLINT   �вι���*/
{
    //���ŵ����вι���
    Person person1("nigger",6);
    //��ʽ�����вι���
    Person person2 = Person("nigga",16);
    //��ʽת�������вι���
    Person person3 = 25;
}

TEST(ctAndDect,anonymous) /* NOLINT    ��������*/
{
    //��������
    Person("֣ˬ����",888);
    cout << "�������������������ִ����Ϻ���������" << endl;
}

TEST(ctAndDect,copy) /* NOLINT   ��������*/
{
    Person person = Person("nigga",16);
    //���ŵ��ÿ�������
    Person person1(person);
    //��ʽ
    Person person2 = Person(person);
    //��ʽ
    Person person3 = person;
}

void outPerson(Person person){
    cout << person << endl;
}

Person returnPerson(){
    Person person;
    return person;
}

/*
 * ʱ����
 * 1.ʹ��һ���Ѵ����Ķ�������ʼ��һ���¶���
 * 2.ֵ���ݵķ�ʽ���������ݲ���
 * 3.��ֵ���ؾֲ�����
 */
TEST(ctAndDect,timingOfCopy) /* NOLINT  ��������ĵ���ʱ��*/
{
//    Person nigger("���", 20);
//    Person person1(nigger);
//    cout << person1 << endl;
//    outPerson(nigger);
    Person p = returnPerson();
    cout << (int*)&p << endl;
}


