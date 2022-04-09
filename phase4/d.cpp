#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

namespace polymorphic {
    /*
    * 多态：
    *  一.静态多态
    *      1.函数重载  2.运算符重载
    *  二.多态多态
    *      1.派生类   2.虚函数
    */
    class Woman {
    public:
        /*
         * 虚函数 是在基类中使用关键字 virtual 声明的函数。
         * 如果使用了virtual关键字，程序将根据引用或指针【指向的对象的类型】来选择方法，而非使用引用类型或指针类型来选择方法。
         */
        virtual void wear() {
            cout << "女人穿衣" << endl;
        }

        void eat() {
            cout << "女人吃饭" << endl;
        }

        virtual void use() = 0;
    };

    class Girl : public Woman {
    public:
        void wear() override {
            cout << "中学女生穿骚JK" << endl;
        }

        void use() override {
            cout << "中学女生冰清玉洁" << endl;
        }
    };

    class Lady : public Woman {
    public:
        void wear() override {
            cout << "女士穿黑丝高跟骚包臀" << endl;
        }

        void eat() {
            cout << "女士让男人请客在米其林吃饭" << endl;
        }

        void use() override {
            cout << "女士使用大黑屌" << endl;
        }
    };
}

using namespace polymorphic;

void doWear(Woman &woman) {
    woman.wear();
}
/*
 * C++多态实现流程：
 * 1.得有继承关系，比如类A派生类B
 * 2.A存在成员函数x，且x为虚函数或纯虚函数
 * 3.B重写x
 * 4.A引用指向B对象
 * 5.调用A.x
 */
TEST(polymorphic, a) /* NOLINT */
{
    Girl girl;
    doWear(girl);
    Lady lady;
    doWear(lady);
}
/*
 * 联编是指一个计算机程序自身彼此关联的过程,在这个联编过程中,
 * 需要确定程序中的操作调用(函数调用)与执行该操作(函数)的代码段之间的映射关系;
 * 按照联编所进行的阶段不同,可分为静态联编和动态联编。
 *
 * 静态联编:
 * 是指联编工作是在程序编译连接阶段进行的,这种联编又称为早期联编;因为这种联编是在程序开始运行之前完成的;
 * 在程序编译阶段进行的这种联编又称静态束定;在编译时就解决了程序中的操作调用与执行该操作代码间的关系,
 * 确定这种关系又被称为束定;编译时束定又称为静态束定;
 *
 * 动态联编:
 * 编译程序在编译阶段并不能确切地知道将要调用的函数,只有在程序执行时才能确定将要调用的函数,
 * 为此要确切地知道将要调用的函数,要求联编工作在程序运行时进行,这种在程序运行时进行的联编工作被称为动态联编,
 * 或动态束定,又叫晚期联编;动态联编在编译的时候还是不知道到底应该选择哪个func函数，只有在真正执行的时候，它才确定。
 *
 * C++规定:动态联编是在【虚函数】的支持下实现的。
 * 基类中一个函数被virtual修饰后，当基类指针指向子类对象时，调用该函数，
 * 将不再按照指针类型来调用基类的这个函数，而是按照右值即子类对象的类型调用子类对象的函数
 */
TEST(polymorphic, virtualFunc) /* NOLINT */
{
    Woman* lady = new Lady;
    lady->eat();
    lady->wear();
}

/*
 * 无实现（{...}替换成 =0，固定写法）的虚函数；只要有纯虚函数，就是抽象类。
 * 抽象类：1.无法实例化对象 2.如果抽象类的子类不重写父类的纯虚函数，子类也是抽象类
 */
TEST(polymorphic, pureVirtualFunc) /* NOLINT 纯虚函数*/
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

    /* 这里不是=0，而是=default。
     * =default相当于在类外对纯虚析构进行了空实现，virtual ~mkDrinkProg(){}，
     * 但有区别，=default可以使类保持POD类型，从而保留编译器对类的优化。
     *
     * 虚析构、纯虚析构也都需要代码实现，否则报error LNK2019: 无法解析的外部符号
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
        cout << "150ml 85°C热水" << endl;
    }

    void addMainMaterial() override {
        cout << "加入咖啡粉" << endl;
    }

    void addIngredients() override {
        cout << "加入糖、牛奶" << endl;
    }
};

class makeTeaProg : public mkDrinkProg{
public:

    explicit makeTeaProg(string shopName) : mkDrinkProg(std::move(shopName)) {
    }

    ~makeTeaProg() override {
        if (shopName != nullptr){
            cout << "释放shopName，不用判空置空只是需要确认shopName被释放了" << endl;
            delete shopName;
            shopName = nullptr;
        }
        cout << "制茶の析构调用" << endl;
    }

    void prepareWater() override {
        cout << "300ml 100℃沸水" << endl;
    }

    void addMainMaterial() override {
        cout << "加入茶叶" << endl;
    }

    void addIngredients() override {
        cout << "加入冷寂星光" << endl;
    }
};

void makeDrink(mkDrinkProg* Prog){
    Prog->makeDrink();
    delete Prog;
}

TEST(polymorphic, VirtualDect) /* NOLINT 虚析构函数*/
{   
    /*
     * 这里是基类指针指向子类实例 mkDrinkProg* Prog = new makeTeaProg，
     * 如果基类mkDrinkProg不使用虚析构函数，在delete Prog即
     * 通过基类指针释放子类实例堆空间，将只会调用基类的析构函数而不会调用子类的，从而导致内存泄露。
     *
     * 原因：
     * 这是因为该语句是静态联编的，而基函数void makeDrink(mkDrinkProg* Prog)本身的执行逻辑
     * 属于动态内存分配（动态联编,或动态束定,又叫晚期联编），
     * 编译器编译到此时，不可能知道此时 mkDrinkProg 到底指向哪个类型的对象，它
     * 只根据 p 的类型是 CShape * 来决定应该调用 CShape 类的析构函数。
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
 * 虚析构和纯虚析构的共性：
 * 可以解决父类指针释放子类对象
 * 【都需要有具体的函数实现，不然报error LNK2019: 无法解析的外部符号，跟有没有堆内属性无关】
 *
 * 虚析构和纯虚析构的区别：
 * 如果是纯虚析构，该类属于抽象类，无法实例化对象
 */
TEST(polymorphic, pureVirtualDect) /* NOLINT 纯虚析构*/
{
    Element* fire = new Fire;

}