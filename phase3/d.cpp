#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class Palace;
/*
 * �����Ԫ�����Ƕ��������ⲿ������Ȩ�����������˽�У�private����Ա�ͱ�����protected����Ա��
 * ������Ԫ������ԭ��������Ķ����г��ֹ���������Ԫ���������ǳ�Ա������
 * ��Ԫ������һ���������ú�������Ϊ��Ԫ��������ԪҲ������һ���࣬���౻��Ϊ��Ԫ�࣬����������£������༰�����г�Ա������Ԫ��

 * 1.ȫ�ֺ�������Ԫ 2.��Ա��������Ԫ 3.���ж�����Ԫ����
 *
 * �̵�ʮ���ó�Ա��������Ԫ�����ɣ�
 * ����A��func a(B b)����B����Ԫ��Ա����Ϊ����������
 * 1.��B����A֮ǰǰ�������������������Ƿ�
 * 2.��A����Bʵ��֮ǰʵ�֣�������Ԫ�����Ƿ�
 * 3.����a����Bʵ��֮��ʵ�֣�����ú����ж���B��˽�г�Ա���ʷǷ�
 * ����˳������ǣ�B��������Aʵ����a��������Bʵ�֡���aʵ�֣���������
 */
class Ladybro{
public:
    void visit(const Palace& palace);
};

class Palace{
    string bedroom;
    double cost;

    //��Ԫ��������������
    //ʹĳһ��������Է���Ŀ�����˽�г�Ա�����������������д��Ŀ��������friend���μ���
    //�����ȫ�ֺ���myNigga���빫���ι뷿��
    friend void myNigga(Palace &house);
    //������Ԫ��
    friend class Nigger;
    //������Ԫ��Ա����
    friend void Ladybro::visit(const Palace& palace);

public:
    string livingRoom;

    Palace();

    Palace(string bedroom, string livingRoom) : bedroom(std::move(bedroom)), livingRoom(std::move(livingRoom)) {}

    Palace(string bedroom, string livingRoom, double cost) : bedroom(std::move(bedroom)), cost(cost),
                                                                                   livingRoom(std::move(livingRoom)) {}
    //��Ԫ���������ж��壬�������������������������ǳ�Ա�������ǳ�Ա�������ǳ�Ա������Ҳ���ܱ��̳�
    friend void princeVisit(Palace& palace){
        cout << "�����ӡ���Ǳ����ѣ�" << endl;
        cout << palace.cost << endl;
    }
};

void Ladybro::visit(const Palace& palace) {
    cout << "��ɧ���ۡ�����Сɧ�����ģ�" << endl;
    cout << palace.bedroom << endl;
}

void myNigga(Palace& house){
    cout << house.livingRoom << endl;
    cout << house.bedroom << endl;
}

TEST(the_friend,globalFunctionAsFriend) /* NOLINT */
{
    Palace princessPalace("��������", "��������");
    myNigga(princessPalace);
}

class Nigger{
public:
    void visit(Palace palace);
};


//�������ү������ʵ�ֳ�Ա������
void Nigger::visit(Palace palace) {
    cout << "���ڹ����ʣ�" << endl;
    cout << palace.bedroom << endl;
}

TEST(the_friend,classAsFriend) /* NOLINT */
{
    Palace princessPalace("��������", "��������");
    Nigger nigger;
    nigger.visit(princessPalace);
}

TEST(the_friend,memberFunctionAsFriend) /* NOLINT */
{
    Palace princessPalace("��������", "��������");
    Ladybro ladybro;
    ladybro.visit(princessPalace);
}

TEST(the_friend,declareInClass) /* NOLINT ��Ԫ���������ж���*/
{
    Palace ladyWeier("��������", "��������",580000000);
    princeVisit(ladyWeier);
}
