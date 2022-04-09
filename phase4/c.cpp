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
//        cout << "爹的构造函数调用" << endl;
//    }
//    ~Dad() {
//        cout << "爹的析构函数调用" << endl;
//    }

    void killNigger(){
        cout << "父亲屠杀黑人" << endl;
    }

    void killNigger(int number){
        printf("父亲屠杀%d只黑人",number);
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
//        cout << "大儿的构造函数调用" << endl;
//    }
//    ~Son1() {
//        cout << "大儿析构函数调用" << endl;
//    }

    int son1Age = 12;
    int girlfriendAge = 0;

    void killNigger(){
        cout << "大儿屠杀黑人" << endl;
    }

    void killNigger(int number){
        printf("大儿屠杀%d只黑人",number);
    }

    static string race;
};
string Son1::race = "黑黄混血小nigger";


class Son2: protected Dad{

};
class Son3: private Dad{

};

class Grandson: public Son3 {

};

/*
 * 父类的私有属性，无论如何都无法继承。
 * 公有继承：父类的公有到子类还是公有，父类的保护到子类还是保护。
 * 保护继承：父类的公有和保护到子类都是保护。
 * 私有继承：都是私有。
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

TEST(inheritance,ramModelOfInheritance) /* NOLINT 继承的对象/内存模型*/
{
    //子类会继承父类所有属性，包括私有的，不过编译器会隐藏私有的。
//    cout << sizeof(Dad) << endl;
//    cout << sizeof(Son1) << endl;

    Dad dad;
    Son1 son1;
    cout << &dad.age << endl;
    cout << &son1.age << endl;
}

/*
 * 顺序为：父构造——子构造——子析构——父析构
 */
TEST(inheritance,constructAndDect) /* NOLINT 继承时的构造/析构顺序*/
{
    Son1 son1;
    string s = "nigger";
}

/*
 * 同名时，子类会隐藏父类的成员，在访问时也会调用自己的成员；
 * 如果要在子类中调用父类的成员，需要加父类作用域限定
 */
TEST(inheritance,nonStaticMemberNameDuplicate) /* NOLINT 继承时非静态同名成员处理*/
{
    Son1 son;
//    cout << son.girlfriendAge << endl;
//    cout << son.Dad::girlfriendAge << endl;

    son.killNigger();
    son.Dad::killNigger(88);
}

TEST(inheritance,staticMemberNameDuplicate) /* NOLINT 继承时静态同名成员处理*/
{
//    Son1 son;
//    cout << son.race << endl;
//    cout << son.Dad::race << endl;

    cout << Son1::race << endl;
    /*
     * 第一个限定符：代表通过类名的方式访问
     * 第二个限定符：代表父类作用域
     */
    cout << Son1::Dad::race << endl;
}

class Stepfather{
public:
    int monthlySalary = 30000;
    int age = 40;
    string race = "忠国人！";
    
    int girlfriendAge = 45;
};

class BeijingBoy : public Dad, public Stepfather{
public:
};

/*
 * 如果多个父类存在同名成员，必须加作用域区分
 */
TEST(inheritance,multipleInherit) /* NOLINT 继承时静态同名成员处理*/
{
    BeijingBoy liuxiaoyu;
    cout << liuxiaoyu.monthlySalary << endl;
//    cout << liuxiaoyu.age << endl;二义
    cout << liuxiaoyu.Stepfather::age << endl;
}

class Human:virtual public Animal{

};

class Katzlane: public Human, public Cat{

};

/*
 * 菱形继承：
 * 小坏喵迪奥娜的家族Katzlane有两个父类：Human 和Cat，同时这两个父类又继承自Animal。
 * 四个类共同组成了一个菱形。
 * 菱形问题即：
 * Animal类有一个int age属性，Katzlane类通过两个父类也继承了这个age属性，
 * 每次Katzlane类的实例想要使用该属性时，都需要指定某个父类的作用域。
 * 然而问题在于，无论从逻辑上还是编码上，Katzlane类应该需要一个只属于他的age属性。
 *
 * 菱形问题解决：虚 の 继 承
 * 让Katzlane的两个父类虚继承Animal，使其成为虚基类。
 */
TEST(inheritance,rhombusInherit) /* NOLINT 菱形继承*/
{
    Katzlane diona;
//    diona.Cat::age = 12;
//    cout << diona.Cat::age << endl;
//    cout << diona.Human::age << endl;有狗

    diona.Cat::age = 14;
    diona.age = 12;
    cout << diona.age << endl;
}

/*
 * 虚继承的目的是让某个类做出声明，承诺愿意共享它的基类。
 * 其中，这个被共享的基类就称为虚基类（Virtual Base Class），本例中的 A 就是一个虚基类。
 * 在这种机制下，不论虚基类在继承体系中出现了多少次，在派生类中都只包含一份虚基类的成员。
 *
 * 观察这个新的继承体系，我们会发现虚继承的一个不太直观的特征：必须在虚派生的真实需求出现前就已经完成虚派生的操作。
 * 在上图中，当定义 D 类时才出现了对虚派生的需求，但是如果 B 类和 C 类不是从 A 类虚派生得到的，
 * 那么 D 类还是会保留 A 类的两份成员。

换个角度讲，虚派生只影响从指定了虚基类的派生类中进一步派生出来的类，它不会影响派生类本身。

在实际开发中，位于中间层次的基类将其继承声明为虚继承一般不会带来什么问题。通常情况下，
 使用虚继承的类层次是由一个人或者一个项目组一次性设计完成的。对于一个独立开发的类来说，
 很少需要基类中的某一个类是虚基类，况且新类的开发者也无法改变已经存在的类体系。

C++标准库中的 iostream 类就是一个虚继承的实际应用案例。iostream 从 istream 和 ostream 直接继承而来，
 而 istream 和 ostream 又都继承自一个共同的名为 base_ios 的类，是典型的菱形继承。
 此时 istream 和 ostream 必须采用虚继承，否则将导致 iostream 类中保留两份 base_ios 类的成员。
 */