#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

namespace a9 {
    template<class ageType = int, class incomeType = double>
    class Person {
    public:
        string name;
        ageType age;
        incomeType income;

        Person(string name, ageType age, incomeType income) : name(std::move(name)), age(age), income(income) {}

        friend ostream &operator<<(ostream &os, const Person &person) {
            os << "name: " << person.name << " age: " << person.age << " income: " << person.income;
            return os;
        }

        void show1() {
            /*
             * ��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
             */
            income.niggerFunc();
            cout << "nigga" << endl;
        }

        void showMe() {
            cout << this->name << this->age << this->income << endl;
        }
    };
}

using namespace a9;

/*
 * ��ʹ��һ����ģ��ʱ�����Ǳ����ṩ������Ϣ����������֪����Щ������Ϣ����ʽģ��ʵ��
 * ��explicit template argument���б����Ǳ��󶨵�ģ�������������ʹ����Щģ��ʵ����ʵ�������ض����ࡣ
 *
 * �������������ǵ� Blob ģ��ʵ������һ����ʱ��������д Blob ģ�壬
 * ��ģ�����T ��ÿ��ʵ���滻Ϊ������ģ��ʵ�Σ��ڱ������� int��
 *
 * һ����ģ���ÿ��ʵ�����γ�һ���������ࡣ���� Blob<string>���κ��� Note
 * ��Blob ���Ͷ�û�й�����Ҳ������κ�����Blob ���͵ĳ�Ա���������Ȩ�ޡ�Ӧ�ü�ס��ģ������ֲ���һ����������
 */
TEST(classTemplate, a) /* NOLINT */
{
    Person<int, double> simaren("������", 20, 0);
    cout << simaren << endl;
}

TEST(classTemplate, diffWithFunctionTemplate) /* NOLINT */
{
    //1.��ģ�岻���Զ������Ƶ�������ָ������
//    Person simaren("������", 20, 0);

    //2.����ģ�������п���ָ��Ĭ������
    Person<> p("�ѧ��", 18, 0);
    cout << p << endl;
}

//��ʽһ����ͨ��������ȷָ����εľ����������ͣ����
void way1(Person<int, double> &person) {
    cout << person.name << person.age << person.income << endl;
}

//��ʽ��������ģ�壬����ָ������ĸ������Ͳ������ɲ��ֿ�ȫ��
template<class ageType>
void way2(Person<ageType, int> &person) {
    cout << person.name << person.age << person.income << endl;
    cout << typeid(ageType).name() << endl;
}

template<class ageType, class incomeType>
void way22(Person<ageType, incomeType> &person) {
    cout << person.age << person.income << endl;
    cout << typeid(ageType).name() << endl;
    cout << typeid(incomeType).name() << endl;
}

//��ʽ��������ģ�壬���������б���
template<class T>
void way3(T &person) {
    cout << person.name << person.age << person.income << endl;
    cout << typeid(person).name() << endl;
}

TEST(classTemplate, usAsFuncArgs) /* NOLINT ����ʹ����ģ�������Ϊ���*/
{
    Person<int, double> person("���", 20, -2000);
//    way1(person);
//    way2(person);
    way3(person);
}

namespace p5b {
    template<class T, class R>
    class Lady;

    //No candidate function template was found for dependent friend function template specialization
    template<class T, class R>
    void nightSkirtShow(Lady<T, R> lady);

    template<class T, class R>
    class Lady {
        T name;
        R age;

        friend void ladyDaiShow(Lady<T, R> lady) {
            cout << "����ģ�����Ԫȫ�ֺ�������ģ����ʵ�֡�֮Ůʿ����" << endl;
            cout << lady.name << endl;
            cout << lady.age << endl;
        }

        /*
         * 1.���಻ͬ������ģ����Ҫ����ĳȫ�ֺ���Ϊ��Ԫ֮ǰ����ȫ�ֺ�������������
         * 2.������ģ�������ģ���з�����Ϊ���͵ü���ģ�����Ͳ�������ɺ���ģ�����״
         * 3.Ϊ�˸ú��������Ϸ�������������Ŀ����ģ��
         *
         * ��������躯��ģ��funcBΪ��ģ��clsA������������Ԫ��˳��ӦΪ��
         *   ��clsA����
         *   ��funcB����
         *   ��clsA������funcBΪ��Ԫ
         *   ��funcBʵ��
         *   ���Тܿɺϲ�����
         *
         * ����1�Ŀ���ԭ��
         * ģ������������֡á� ��Щ��������ģ����������� ����Щ������ģ�����������
         * ��ʹ��ģ��ʱ�����в�������ģ����������ֶ������ǿɼ��ģ�������ģ����ṩ������֤�ġ�
         * ���ң�ģ����ṩ�߱��뱣֤����ģ�屻ʵ����ʱ��ģ��Ķ��壬������ģ��ĳ�Ա�Ķ��壬Ҳ�����ǿɼ��ġ�
         * ����ʵ����ģ������к����������Լ������͹�����������������������ǿɼ��ģ�������ģ����û�����֤�ġ�
         */
        friend void nightSkirtShow<>(Lady<T, R> lady);

    public:
        Lady() {
            cout << typeid(name).name() << endl;
            cout << typeid(age).name() << endl;
        }

        Lady(T name, R age);

        /*
         * ������ʹ��һ����ģ������ʱ�����ṩģ��ʵ�Σ�����һ������һ�����⣺
         * ����ģ���Լ����������У����ǿ���ֱ��ʹ��ģ���������ṩʵ�Ρ�
         */
        void wearDress(Lady lady) {
            cout << lady.name << endl;
            cout << "Сɧɧ���������ɧ" << endl;
        }

        void ladyShow();
    };

    template<class T, class R>
    void nightSkirtShow(Lady<T, R> lady) {
        cout << "����ģ�����Ԫȫ�ֺ�������ģ������������ģ����ʵ�֡�֮Ůʿ˯ȹ����" << endl;
        cout << lady.name << endl;
        cout << lady.age << endl;
    }

    class Derived : public Lady<string, long> {

    public:
    };

//    class Derived2 : public Lady<T>{
//
//    };
//
//    class Derived3 : public Lady{
//
//    };

    template<class T, class R>
    class Derived4 : public Lady<T, R> {

    };

}

using namespace p5b;
/*
 * 1.����̳���ģ��ʱ�����������ȷָ�������е����з���
 * 2.��������ָ�������е����ͣ�����Ҳ��Ҫ��Ϊ��ģ��
 */
TEST(classTemplate, inheritance) /* NOLINT */
{
    Derived derived;
    Derived4<int, string> nigga;
}

//1.���캯��������ʵ��
template<class T, class R>
Lady<T, R>::Lady(T name, R age) {
    this->name = name;
    this->age = age;
}

//2.��Ա����������ʵ��
template<class T, class R>
void Lady<T, R>::ladyShow() {
    cout << this->name << endl;
    cout << "Ϊ��ұ������´���" << endl;
}



//'Lady' is not a class, namespace, or enumeration
//void Lady::ladyShow() {
//    cout << this->name << endl;
//    cout << "Ϊ��ұ������´���" << endl;
//}


/*
 * �������κ�����ͬ�����Ǽȿ�������ģ���ڲ���Ҳ��������ģ���ⲿΪ�䶨���Ա������
 * �Ҷ�������ģ���ڵĳ�Ա��������ʽ����Ϊ������������ģ��ĳ�Ա����������һ����ͨ������
 * ���ǣ���ģ���ÿ��ʵ���������Լ��汾�ĳ�Ա��������ˣ���ģ��ĳ�Ա�������к�ģ����ͬ��ģ�������
 * �������������ģ��֮��ĳ�Ա�����ͱ����Թؼ��� template ��ʼ�������ģ������б�
 * ������һ���������������ⶨ��һ����Աʱ������˵����Ա�����ĸ��ࡣ
 * ���ң���һ��ģ�����ɵ���������б��������ģ��ʵ�Ρ������Ƕ���һ����Ա����ʱ��ģ��ʵ����ģ���β���ͬ��
 * �������� strB1ob ��һ�������ĳ�Ա����ret-type StrBlob;:member-namefparm-list)
 * ��Ӧ�� Blob �ĳ�ԱӦ���������ġ� template <typename T>
 */
TEST(classTemplate, memFuncOutSide) /* NOLINT ��ģ��ĳ�Ա�����������ʵ��*/
{
    Lady<string, int> lady("Сɧɧ", 27);
    lady.ladyShow();
}

/*
 * ������������һ��ģ�嶨��ʱ�����������ɴ��롣ֻ�е�����ʵ������ģ���һ���ض��汾ʱ��
 * �������Ż����ɴ��롣������ʹ�ã������Ƕ��壩ģ��ʱ�������������ɴ��룬
 * ��һ����Ӱ�������������֯�����Լ������ʱ����⵽��ͨ���������ǵ���һ������ʱ��
 * ������ֻ��Ҫ���պ��������������Ƶģ�������ʹ��һ�������͵Ķ���ʱ���ඨ������ǿ��õģ�
 * ����Ա�����Ķ��岻���Ѿ����֡���ˣ����ǽ��ඨ��ͺ�����������ͷ�ļ��У�
 * ����ͨ��������ĳ�Ա�����Ķ������Դ�ļ��С�ģ����ͬ;Ϊ������һ��ʵ�����汾��
 * ��������Ҫ���պ���ģ�����ģ���Ա�����Ķ��塣��ˣ����ģ����벻ͬ��ģ���ͷ�ļ�ͨ���Ȱ�������Ҳ�������塣
 */
#include "swiss.hpp"

TEST(classTemplate, subfileWritine) /* NOLINT ��ģ��ķ��ļ���д*/
{
    Swiss<string, int> zzr("������", 25);
    zzr.show();
}

/*
 * 1.��ģ�����Ԫȫ�ֺ���ֱ������ģ����ʵ�֣�ֱ��д
 * 2.��ģ�����Ԫȫ�ֺ�������ģ����ʵ�֣��ܲ���д����������
 */


TEST(classTemplate, withFriend) /* NOLINT ��ģ������Ԫ*/
{
    Lady<string, int> lady("������", 24);
//    ladyDaiShow(lady);
    nightSkirtShow(lady);
}