#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>
#include <cstring>

using namespace std;

namespace a2 {
    class Person {
        string name;
        int age{};
    public:
        //���캯�������в���
        Person() {
            cout << "���캯������" << endl;
        };

        Person(string name, int age) : name(std::move(name)), age(age) {
            cout << "����ʼ���б�ʽ��" << endl;
            cout << "�вΣ�ȫ�Σ��������" << endl;
        }

        Person(int age) : age(age) {
            cout << "�вΣ�age���������" << endl;
        }

        Person(const Person &person) {
            name = person.name;
            age = person.age;
            cout << "�������캯������" << endl;
        }

        //�������������в���
        ~Person() {
            cout << "������������" << endl;
        }

        friend ostream& operator<<(ostream &os, const Person &person) {
            os << "name: " << person.name << " age: " << person.age;
            return os;
        }
    };
}
using namespace a2;

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

class Girl{
    int age;
    string name;

public:
//    Girl(int age, string name) : age(age), name(std::move(name)) {}

    Girl(Girl const &girl) {
    age = girl.age;
    name = girl.name;
    }

    friend ostream &operator<<(ostream &os, const Girl &girl) {
        os << "age: " << girl.age << " name: " << girl.name;
        return os;
    }
};

/* Ĭ�Ϲ��캯����
 * Ĭ������£����������ٸ�һ�������3�����캯����
 * Ĭ�Ϲ��죨�޲Ρ���ʵ�֣���Ĭ���������޲Ρ���ʵ�֣���Ĭ�Ͽ�����ֵ�����������ԣ�
 *
 * ���캯���ṩ����
 * ����û������вι��죬C++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ������죻
 * ����û����忽�����죬C++�����ṩ�������й��캯��
 */
TEST(ctAndDect,ruleOfCstFunc) /* NOLINT  ���캯���ĵ��ù���*/
{
//    Girl girl1(14,"ʮ�Ľ���");
//    Girl girl2(girl1);
//    cout << girl2 << endl;

//    Girl girl;
}

class Game{
public:
    int price;
    double* revenue;

    Game(int price, double revenue) {
        this->price = price;
        this->revenue = new double (revenue);
    }

    /* ��������ڶ������ٵ����ݣ�Ҫ�������������ͷ�
     * delete ������������ͷ�new�������̬������ڴ�ռ䣬
     * ����ͷ�һ���Ѿ��ͷ��˵�ָ�룬�����ᱨ��
     *
     * �ͷ�һ��ָ�룬������ʹ��ָ���ֵ��Ϊ NULL��
     * */
    virtual ~Game() {
        if (revenue != nullptr){
            delete revenue;
            revenue = nullptr;
        }
        cout << "��������" << endl;
    }

    friend ostream &operator<<(ostream &os, const Game &game) {
        os << "price: " << game.price << " revenue: " << *game.revenue;
        return os;
    }

    Game(const Game& game_){
        price = game_.price;
        //���
        revenue = new double (*game_.revenue);
    }
};
/*
 * Ĭ�Ͽ������캯��Ϊ��ǳ��������
 * �ڽ��ж��󿽱�ʱ��ǳ����ֻ�ὫԴ������������Ե�ֵ��ֵ���¶���
 *
 * ������д������û�ָ�����ԣ�ǳ����Ҳֻ�Ὣ��ֵ��������ĳһ����ĵ�ֵַ��ֵ���¶���
 * �����¶�����Դ����������ȫ������ͳһ�������ԡ�
 *
 * ����������ǽ�����������дΪ����������ڶ���Ϊ�¶����ָ�����Դ�����Ӧ�Ķ���
 */
TEST(ctAndDect,deepAndShallow) /* NOLINT  �����ǳ����*/
{
    Game genshin(648, 1000000);
    Game wzry(genshin);
    *wzry.revenue *= 20;
    cout << wzry << endl;
}

TEST(ctAndDect,initializedList) /* NOLINT  ���캯���ĳ�ʼ���б�*/
{
    Person person("���",16);
    cout << person << endl;
}

class Phone{
    string name;
    int price;

public:
    friend ostream &operator<<(ostream &os, const Phone &phone) {
        os << "name: " << phone.name << " price: " << phone.price;
        return os;
    }

    Phone() {};

    Phone(string name, int price) : name(std::move(name)), price(price) {
        cout << "Phone���캯������" << endl;
    }

    virtual ~Phone() {
        cout << "Phone������������" << endl;
    }
};

class JK{
    string name;
    int age;
    Phone phone;

public:
    friend ostream &operator<<(ostream &os, const JK &jk) {
        os << "name: " << jk.name << " age: " << jk.age << " phone: " << jk.phone;
        return os;
    }

    JK(string name, int age, const Phone &phone) : name(std::move(name)), age(age), phone(phone) {}

    virtual ~JK() {
        cout << "JK������������" << endl;
    }
};

/*
 * ��a��Ϊ��B�ĳ�Ա����ʱ���ڹ���Bʱ���ȵ���a�Ĺ��죬������Bʱ���ȵ���B������(�빹���෴)
 */
TEST(ctAndDect,objectAsMember) /* NOLINT �����Ա�����������ĳ�Ա*/
{
    JK zyw("����ޱ", 13, Phone("iphone 8", 7000));
    cout << zyw << endl;
}