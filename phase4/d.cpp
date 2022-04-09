#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

namespace polymorphic {
    /*
    * ��̬��
    *  һ.��̬��̬
    *      1.��������  2.���������
    *  ��.��̬��̬
    *      1.������   2.�麯��
    */
    class Woman {
    public:
        /*
         * �麯�� ���ڻ�����ʹ�ùؼ��� virtual �����ĺ�����
         * ���ʹ����virtual�ؼ��֣����򽫸������û�ָ�롾ָ��Ķ�������͡���ѡ�񷽷�������ʹ���������ͻ�ָ��������ѡ�񷽷���
         */
        virtual void wear() {
            cout << "Ů�˴���" << endl;
        }

        void eat() {
            cout << "Ů�˳Է�" << endl;
        }

        virtual void use() = 0;
    };

    class Girl : public Woman {
    public:
        void wear() override {
            cout << "��ѧŮ����ɧJK" << endl;
        }

        void use() override {
            cout << "��ѧŮ���������" << endl;
        }
    };

    class Lady : public Woman {
    public:
        void wear() override {
            cout << "Ůʿ����˿�߸�ɧ����" << endl;
        }

        void eat() {
            cout << "Ůʿ����������������ֳԷ�" << endl;
        }

        void use() override {
            cout << "Ůʿʹ�ô�ڌ�" << endl;
        }
    };
}

using namespace polymorphic;

void doWear(Woman &woman) {
    woman.wear();
}
/*
 * C++��̬ʵ�����̣�
 * 1.���м̳й�ϵ��������A������B
 * 2.A���ڳ�Ա����x����xΪ�麯�����麯��
 * 3.B��дx
 * 4.A����ָ��B����
 * 5.����A.x
 */
TEST(polymorphic, a) /* NOLINT */
{
    Girl girl;
    doWear(girl);
    Lady lady;
    doWear(lady);
}
/*
 * ������ָһ���������������˴˹����Ĺ���,��������������,
 * ��Ҫȷ�������еĲ�������(��������)��ִ�иò���(����)�Ĵ����֮���ӳ���ϵ;
 * �������������еĽ׶β�ͬ,�ɷ�Ϊ��̬����Ͷ�̬���ࡣ
 *
 * ��̬����:
 * ��ָ���๤�����ڳ���������ӽ׶ν��е�,���������ֳ�Ϊ��������;��Ϊ�����������ڳ���ʼ����֮ǰ��ɵ�;
 * �ڳ������׶ν��е����������ֳƾ�̬����;�ڱ���ʱ�ͽ���˳����еĲ���������ִ�иò��������Ĺ�ϵ,
 * ȷ�����ֹ�ϵ�ֱ���Ϊ����;����ʱ�����ֳ�Ϊ��̬����;
 *
 * ��̬����:
 * ��������ڱ���׶β�����ȷ�е�֪����Ҫ���õĺ���,ֻ���ڳ���ִ��ʱ����ȷ����Ҫ���õĺ���,
 * Ϊ��Ҫȷ�е�֪����Ҫ���õĺ���,Ҫ�����๤���ڳ�������ʱ����,�����ڳ�������ʱ���е����๤������Ϊ��̬����,
 * ��̬����,�ֽ���������;��̬�����ڱ����ʱ���ǲ�֪������Ӧ��ѡ���ĸ�func������ֻ��������ִ�е�ʱ������ȷ����
 *
 * C++�涨:��̬�������ڡ��麯������֧����ʵ�ֵġ�
 * ������һ��������virtual���κ󣬵�����ָ��ָ���������ʱ�����øú�����
 * �����ٰ���ָ�����������û����������������ǰ�����ֵ�������������͵����������ĺ���
 */
TEST(polymorphic, virtualFunc) /* NOLINT */
{
    Woman* lady = new Lady;
    lady->eat();
    lady->wear();
}

/*
 * ��ʵ�֣�{...}�滻�� =0���̶�д�������麯����ֻҪ�д��麯�������ǳ����ࡣ
 * �����ࣺ1.�޷�ʵ�������� 2.�������������಻��д����Ĵ��麯��������Ҳ�ǳ�����
 */
TEST(polymorphic, pureVirtualFunc) /* NOLINT ���麯��*/
{
//    Woman woman;
    Woman * girl = new Girl;
    girl->use();
    Lady lady;
    lady.use();
}

class mkDrinkProg{
public:
    mkDrinkProg(string shopName) : shopName(new string(std::move(shopName))) {}

    /* ���ﲻ��=0������=default��
     * =default�൱��������Դ������������˿�ʵ�֣�virtual ~mkDrinkProg(){}��
     * ��������=default����ʹ�ౣ��POD���ͣ��Ӷ�����������������Ż���
     *
     * ����������������Ҳ����Ҫ����ʵ�֣�����error LNK2019: �޷��������ⲿ����
     * */
    virtual ~mkDrinkProg() = default;

    virtual void prepareWater() = 0;
    virtual void addMainMaterial() = 0;
    virtual void addIngredients() = 0;

    void makeDrink(){
        prepareWater();
        addMainMaterial();
        addIngredients();
    }

    string* shopName;
};

class makeCoffeeProg : public mkDrinkProg{
public:
    void prepareWater() override {
        cout << "150ml 85��C��ˮ" << endl;
    }

    void addMainMaterial() override {
        cout << "���뿧�ȷ�" << endl;
    }

    void addIngredients() override {
        cout << "�����ǡ�ţ��" << endl;
    }
};

class makeTeaProg : public mkDrinkProg{
public:

    explicit makeTeaProg(string shopName) : mkDrinkProg(std::move(shopName)) {
    }

    ~makeTeaProg() override {
        if (shopName != nullptr){
            cout << "�ͷ�shopName�������п��ÿ�ֻ����Ҫȷ��shopName���ͷ���" << endl;
            delete shopName;
            shopName = nullptr;
        }
        cout << "�Ʋ����������" << endl;
    }

    void prepareWater() override {
        cout << "300ml 100���ˮ" << endl;
    }

    void addMainMaterial() override {
        cout << "�����Ҷ" << endl;
    }

    void addIngredients() override {
        cout << "��������ǹ�" << endl;
    }
};

void makeDrink(mkDrinkProg* Prog){
    Prog->makeDrink();
    delete Prog;
}

TEST(polymorphic, VirtualDect) /* NOLINT ����������*/
{   
    /*
     * �����ǻ���ָ��ָ������ʵ�� mkDrinkProg* Prog = new makeTeaProg��
     * �������mkDrinkProg��ʹ����������������delete Prog��
     * ͨ������ָ���ͷ�����ʵ���ѿռ䣬��ֻ����û�������������������������ģ��Ӷ������ڴ�й¶��
     *
     * ԭ��
     * ������Ϊ������Ǿ�̬����ģ���������void makeDrink(mkDrinkProg* Prog)�����ִ���߼�
     * ���ڶ�̬�ڴ���䣨��̬����,��̬����,�ֽ��������ࣩ��
     * ���������뵽��ʱ��������֪����ʱ mkDrinkProg ����ָ���ĸ����͵Ķ�����
     * ֻ���� p �������� CShape * ������Ӧ�õ��� CShape �������������
     *
     */
    makeDrink(new makeTeaProg("Starbucks"));
}

class Element{
public:
    virtual ~Element() = 0;
};

Element::~Element() {
    cout << "Element " << endl;
}

class Fire : public Element{
public:
    virtual ~Fire() {
        cout << "nigger" << endl;
    }
};

/*
 * �������ʹ��������Ĺ��ԣ�
 * ���Խ������ָ���ͷ��������
 * ������Ҫ�о���ĺ���ʵ�֣���Ȼ��error LNK2019: �޷��������ⲿ���ţ�����û�ж��������޹ء�
 *
 * �������ʹ�������������
 * ����Ǵ����������������ڳ����࣬�޷�ʵ��������
 */
TEST(polymorphic, pureVirtualDect) /* NOLINT ��������*/
{
    Element* fire = new Fire;

}