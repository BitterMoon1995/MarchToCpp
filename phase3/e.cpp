#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;
/**
 * ��ǉ����֮���������
 * ������ͨ�������ض���operator���������ظ��������
 */

class Employee{
    int salary;
    int bonus;
    double* wifeLoan;
public:
    /*
     * �����ָʾ��ָ���������Լ��һ���Ϸ���ֵ��ע�ⲻ����nullptr��������nullptr����
     * �����ڹ������ʱ��ֻҪ����ָ������ֵ���ͻ�ʽ��
     * unknown file: error: SEH exception with code 0xc0000005 thrown in the test body.
     * ��ʽ���Ƿ��ڴ������������ˡ�
     */
    Employee() {
        wifeLoan = new double (0);
    }

    Employee(int salary, int bonus) : salary(salary), bonus(bonus) {}

    Employee(int salary, int bonus, double wifeLoan) : salary(salary), bonus(bonus){
        this->wifeLoan = new double (wifeLoan);
    }

    ~Employee() {
        if (wifeLoan != nullptr) {
            delete wifeLoan;
            wifeLoan = nullptr;
        }
    }

    //ʹ�ó�Ա�����������ظ���������
    Employee operator+(Employee& employee) const{
        Employee temp;
        temp.salary = this->salary + employee.salary;
        temp.bonus = this->bonus + employee.bonus;
        return temp;
    }
    //operator��������Ҳ���Խ��к�������
    Employee operator+(int extraGain) const{
        Employee employee;
        employee.salary = this->salary;
        employee.bonus = this->bonus + extraGain;
        return employee;
    }

    /* ����ȫ�֣���Ԫ������������������������ɣ�
     * ���Ҫʵ�ֹ��������ʽ cout << object << endl��ֻ�������ַ�ʽ��
     * ����������Ϊ��ostream����������������������غ����Ĳ��������ǵ�Ŀ����Employee��
     * ͬʱΪ�����غ����ܹ�������Employee��˽�����ԣ������ڸ����ж���Ϊ��Ԫ������
     *
     * ��������ostream&�Է�����ʽ���á�
     *
     * �������ΪEmployee�ĳ�Ա���������ʾ��������Employee�������������
     * �����employee<<cout��=employee.operator<<����������Ȼ�Ĵ���
     * */
    friend ostream& operator<<(ostream& output,Employee& employee){
        output << "�������ʣ�"<< employee.salary << endl;
        output << "������죺"<< employee.bonus << endl;
        output << "���󷿴���" << *employee.wifeLoan << endl;
        return output;
    }

    /*
     * ����ǰ�õ��������
     * ����&Emoployee�����ɣ�
     * �������㱾��һ�㶼�н�������籾����i=1,++i�͵���2��
     * ���Ҫ���employeeǰ�������Ľ��cout << ++godz << endl������Ҫ�з���ֵ�����ܷ���null��
     * ���뷵������������ã�����++(++employee)�Ľ������++employee��
     * ��Ϊ��n+1�����������Ķ�����Զ���ǵ�һ�����������ֵ������
     */
    Employee& operator++(){
        salary += 100;
        return *this;
    }
    /*
     * ���غ��õ��������
     * C++ͨ��ռλ������int����ǰ�õ�����������õ������أ����õ����͵�Ϊ�ò�����
     * ���õ������߼��ǣ����½���ʱֵ�Լ�¼��ǰ�����״̬���ٽ����������㣬�ٷ���֮ǰ��¼����ʱֵ��
     * ��ǰ�õ����෴�����õ������뷵��ֵ����Ϊ���ܷ��ؾֲ�����������
     */
    Employee operator++(int ){
        const Employee temp = *this;
        salary += 100;
        return temp;
    }

    Employee& operator=(const Employee& employee){
        /* �Ը�ֵ���
         * �·���ָ�������ͷŻ�����Ը�ֵ���⼴��������Լ����Լ���ֵ�أ�
         * ����Employee godz(5000,2000,2500000);godz=godz;
         * ���ѿ������Դ�����Ŀ�������ͬһ�������������飬
         * ��ôgodz��wifeLoan�ᱻ�ͷţ�Ȼ�����Ϊһ����ָ�룬����godz�����ݽṹ���ƻ���
         * ���wifeLoan������double������������������ء�
         *
         * ������������Ƕ��������Լ����Լ���ֵ��һ��ֱ�ӷ����Լ�������*/
        if (this == &employee)
            return *this;

        salary = employee.salary;
        bonus = employee.bonus;

        /*
         * ���Ŀ������ָ�����Էǿգ�Ҫ���ͷſռ䡢ָ�գ���Ϊ����������
         * ��Ȼ��֮ǰָ����Ǹ��������Զ�ò����ڴ��ͷţ�����й¶�ˡ�
         * ע�⡾����Ҫ�����wifeLoan�Ƿ�Ϊ�գ�delete�ؼ��ֱ���ͻ����ָ�룬delete��ָ��Ҳ�ǺϷ��ġ�
         */
        delete wifeLoan;
        wifeLoan = new double (*employee.wifeLoan);

        return *this;
    }

    //���ع�ϵ�����֮���ں�
    bool operator>(const Employee& employee) const{
        if ((salary + bonus) > (employee.salary + employee.bonus))
            return true;
        return false;
    }

    //���غ������������ �� () ��
    void operator()() const{
        cout << "��Ա������֮���Ƥ��" << endl;
        cout << "���ʣ�"<< salary << endl;
        cout << "����"<< bonus << endl;
    }
    void operator()(const string& name) const{
        printf("¡�ؽ�����Ա����%s��������\n",name.c_str());
    }
};

//ȫ�ֺ�����������ء� ����ʹ����������ʲ���˽�����Էǵ�Ҫgetset
//Employee operator+(Employee& a,Employee& b){
//    Employee temp;
//    temp.setSalary(a.getSalary() + b.getSalary());
//    temp.setBonus(a.getBonus() + b.getBonus());
//    return temp;
//}



TEST(operatorReload,plusSign) /* NOLINT */
{
    Employee godz(5000,2000);
//    Employee wyw(2000,500);
//    Employee total = godz + wyw;
//    cout << total << endl;

    int dnfMoveBrick = 5;
    Employee godz2 = godz + dnfMoveBrick;
    cout << godz2 << endl;
}

TEST(operatorReload,lestShift) /* NOLINT */
{
    Employee godz(5000,2000);
    cout << godz << endl;
}

TEST(operatorReload,selfIncrement) /* NOLINT */
{
    Employee godz(5000,2000);
//    cout << ++(++godz) << endl;
//    cout << godz << endl;

//    cout << (godz++)++ << endl;
    godz++;
    godz++;
    cout << godz << endl;
}
/*
 * ͬһ��ĸ�������֮�����ͨ�� = �����໥��ֵ��������������ָ�����ԣ�Ĭ�ϵĸ�ֵ��������ǳ������
 * ���¹����������⣬�Ӷ��������Ⱥ�������ʱ����Assertion failed: _CrtIsValidHeapPointer(block)��
 *
 * ������������ָ�����ԣ��������ظ�ֵ�������
 *
 * ��ҪΪ����ָ�����Ե��࣬�����Ը�ֵ���⡣
 */
TEST(operatorReload,assign) /* NOLINT ��ֵ���������*/
{
    Employee yanghuan(4000,1000,2500000);

    Employee godz;
    Employee wpc;
    godz = wpc = yanghuan;
    cout << godz << endl;
    cout << wpc << endl;
}

TEST(operatorReload,relationalOperator) /* NOLINT ��ϵ���������*/
{
    Employee godz(5000,2000,0);
    Employee wpc(4000,1000,2500000);
    Employee mdw(7000,5000,0);
    cout << (godz > wpc) << endl;
    cout << (godz > mdw) << endl;
}
/*
 * ������������������طǳ���û�й̶���д����
 * ��ʱ�������ֵ������ڵ��ú��������ڵ��ö���ĺ������á�
 */
class Plus{
public:
    int operator()(int a,int b){
        return a + b;
    }
};

int plus2(int a ,int b){
    return a + b;
}

TEST(operatorReload,invokeOperator) /* NOLINT ����������������أ��º�����*/
{
//    Employee godz(5000,2000,0);
//    godz("����������");
//    godz();
    Plus plus;
    cout << plus(1,1) << endl;
    cout << plus2(1,1) << endl;

    //������������������º�������
    cout << Plus()(1,1) << endl;
}