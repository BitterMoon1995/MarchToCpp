#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class Animal{
public:
    int age;
};

class Cat:virtual public Animal{
};


TEST(inheritance,alpha) /* NOLINT */
{
    Cat cat;
    cat.age = 1;
}

class Dad{
public:
    int age = 47;
    int girlfriendAge = 28;

//    Dad() {
//        cout << "���Ĺ��캯������" << endl;
//    }
//    ~Dad() {
//        cout << "����������������" << endl;
//    }

    void killNigger(){
        cout << "������ɱ����" << endl;
    }

    void killNigger(int number){
        printf("������ɱ%dֻ����",number);
    }

    static string race;

protected:
    int fatherIncome = 3000;
private:
    int creditNum = 888888;
};
string Dad::race = "nigger";


class Son1: public Dad{
public:
//    Son1() {
//        cout << "����Ĺ��캯������" << endl;
//    }
//    ~Son1() {
//        cout << "���������������" << endl;
//    }

    int son1Age = 12;
    int girlfriendAge = 0;

    void killNigger(){
        cout << "�����ɱ����" << endl;
    }

    void killNigger(int number){
        printf("�����ɱ%dֻ����",number);
    }

    static string race;
};
string Son1::race = "�ڻƻ�ѪСnigger";


class Son2: protected Dad{

};
class Son3: private Dad{

};

class Grandson: public Son3 {

};

/*
 * �����˽�����ԣ�������ζ��޷��̳С�
 * ���м̳У�����Ĺ��е����໹�ǹ��У�����ı��������໹�Ǳ�����
 * �����̳У�����Ĺ��кͱ��������඼�Ǳ�����
 * ˽�м̳У�����˽�С�
 */
TEST(inheritance,threeInheritWay) /* NOLINT */
{
    Son1 son1;
    cout << son1.age << endl;
//    cout << son1.fatherIncome << endl;

    Son2 son2;
//    cout << son2.age << endl;

    Grandson grandson;
//    cout << grandson.age << endl;
}

TEST(inheritance,ramModelOfInheritance) /* NOLINT �̳еĶ���/�ڴ�ģ��*/
{
    //�����̳и����������ԣ�����˽�еģ�����������������˽�еġ�
//    cout << sizeof(Dad) << endl;
//    cout << sizeof(Son1) << endl;

    Dad dad;
    Son1 son1;
    cout << &dad.age << endl;
    cout << &son1.age << endl;
}

/*
 * ˳��Ϊ�������졪���ӹ��졪������������������
 */
TEST(inheritance,constructAndDect) /* NOLINT �̳�ʱ�Ĺ���/����˳��*/
{
    Son1 son1;
    string s = "nigger";
}

/*
 * ͬ��ʱ����������ظ���ĳ�Ա���ڷ���ʱҲ������Լ��ĳ�Ա��
 * ���Ҫ�������е��ø���ĳ�Ա����Ҫ�Ӹ����������޶�
 */
TEST(inheritance,nonStaticMemberNameDuplicate) /* NOLINT �̳�ʱ�Ǿ�̬ͬ����Ա����*/
{
    Son1 son;
//    cout << son.girlfriendAge << endl;
//    cout << son.Dad::girlfriendAge << endl;

    son.killNigger();
    son.Dad::killNigger(88);
}

TEST(inheritance,staticMemberNameDuplicate) /* NOLINT �̳�ʱ��̬ͬ����Ա����*/
{
//    Son1 son;
//    cout << son.race << endl;
//    cout << son.Dad::race << endl;

    cout << Son1::race << endl;
    /*
     * ��һ���޶���������ͨ�������ķ�ʽ����
     * �ڶ����޶�����������������
     */
    cout << Son1::Dad::race << endl;
}

class Stepfather{
public:
    int monthlySalary = 30000;
    int age = 40;
    string race = "�ҹ��ˣ�";
    
    int girlfriendAge = 45;
};

class BeijingBoy : public Dad, public Stepfather{
public:
};

/*
 * �������������ͬ����Ա�����������������
 */
TEST(inheritance,multipleInherit) /* NOLINT �̳�ʱ��̬ͬ����Ա����*/
{
    BeijingBoy liuxiaoyu;
    cout << liuxiaoyu.monthlySalary << endl;
//    cout << liuxiaoyu.age << endl;����
    cout << liuxiaoyu.Stepfather::age << endl;
}

class Human:virtual public Animal{

};

class Katzlane: public Human, public Cat{

};

/*
 * ���μ̳У�
 * С�����ϰ��ȵļ���Katzlane���������ࣺHuman ��Cat��ͬʱ�����������ּ̳���Animal��
 * �ĸ��๲ͬ�����һ�����Ρ�
 * �������⼴��
 * Animal����һ��int age���ԣ�Katzlane��ͨ����������Ҳ�̳������age���ԣ�
 * ÿ��Katzlane���ʵ����Ҫʹ�ø�����ʱ������Ҫָ��ĳ�������������
 * Ȼ���������ڣ����۴��߼��ϻ��Ǳ����ϣ�Katzlane��Ӧ����Ҫһ��ֻ��������age���ԡ�
 *
 * �������������� �� �� ��
 * ��Katzlane������������̳�Animal��ʹ���Ϊ����ࡣ
 */
TEST(inheritance,rhombusInherit) /* NOLINT ���μ̳�*/
{
    Katzlane diona;
//    diona.Cat::age = 12;
//    cout << diona.Cat::age << endl;
//    cout << diona.Human::age << endl;�й�

    diona.Cat::age = 14;
    diona.age = 12;
    cout << diona.age << endl;
}

/*
 * ��̳е�Ŀ������ĳ����������������ŵԸ�⹲�����Ļ��ࡣ
 * ���У����������Ļ���ͳ�Ϊ����ࣨVirtual Base Class���������е� A ����һ������ࡣ
 * �����ֻ����£�����������ڼ̳���ϵ�г����˶��ٴΣ����������ж�ֻ����һ�������ĳ�Ա��
 *
 * �۲�����µļ̳���ϵ�����ǻᷢ����̳е�һ����ֱ̫�۵�����������������������ʵ�������ǰ���Ѿ�����������Ĳ�����
 * ����ͼ�У������� D ��ʱ�ų����˶������������󣬵������ B ��� C �಻�Ǵ� A ���������õ��ģ�
 * ��ô D �໹�ǻᱣ�� A ������ݳ�Ա��

�����ǶȽ���������ֻӰ���ָ�����������������н�һ�������������࣬������Ӱ�������౾��

��ʵ�ʿ����У�λ���м��εĻ��ཫ��̳�����Ϊ��̳�һ�㲻�����ʲô���⡣ͨ������£�
 ʹ����̳е���������һ���˻���һ����Ŀ��һ���������ɵġ�����һ����������������˵��
 ������Ҫ�����е�ĳһ����������࣬��������Ŀ�����Ҳ�޷��ı��Ѿ����ڵ�����ϵ��

C++��׼���е� iostream �����һ����̳е�ʵ��Ӧ�ð�����iostream �� istream �� ostream ֱ�Ӽ̳ж�����
 �� istream �� ostream �ֶ��̳���һ����ͬ����Ϊ base_ios ���࣬�ǵ��͵����μ̳С�
 ��ʱ istream �� ostream ���������̳У����򽫵��� iostream ���б������� base_ios ��ĳ�Ա��
 */