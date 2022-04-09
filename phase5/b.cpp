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
             * 类模板中的成员函数在调用时才创建
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
 * 当使用一个类模板时，我们必须提供额外信息。我们现在知道这些额外信息是显式模板实参
 * （explicit template argument）列表，它们被绑定到模板参数。编译器使用这些模板实参来实例化出特定的类。
 *
 * 当编译器从我们的 Blob 模板实例化出一个类时，它会重写 Blob 模板，
 * 将模板参数T 的每个实例替换为给定的模板实参，在本例中是 int。
 *
 * 一个类模板的每个实例都形成一个独立的类。类型 Blob<string>与任何其 Note
 * 他Blob 类型都没有关联，也不会对任何其他Blob 类型的成员有特殊访问权限。应该记住类模板的名字不是一个类型名。
 */
TEST(classTemplate, a) /* NOLINT */
{
    Person<int, double> simaren("死妈人", 20, 0);
    cout << simaren << endl;
}

TEST(classTemplate, diffWithFunctionTemplate) /* NOLINT */
{
    //1.类模板不能自动类型推导，必须指定类型
//    Person simaren("死妈人", 20, 0);

    //2.在类模板声明中可以指定默认类型
    Person<> p("穷狗学生", 18, 0);
    cout << p << endl;
}

//方式一：普通函数，明确指定入参的具体数据类型，最常用
void way1(Person<int, double> &person) {
    cout << person.name << person.age << person.income << endl;
}

//方式二：函数模板，按需指定对象的各个类型参数，可部分可全部
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

//方式三：函数模板，整个参数列表泛化
template<class T>
void way3(T &person) {
    cout << person.name << person.age << person.income << endl;
    cout << typeid(person).name() << endl;
}

TEST(classTemplate, usAsFuncArgs) /* NOLINT 函数使用类模板对象作为入参*/
{
    Person<int, double> person("尼哥", 20, -2000);
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
            cout << "【类模板的友元全局函数在类模板内实现】之女士大秀" << endl;
            cout << lady.name << endl;
            cout << lady.age << endl;
        }

        /*
         * 1.与类不同，在类模板内要声明某全局函数为友元之前，该全局函数必须先声明
         * 2.其在类模板外对类模板有访问行为，就得加上模板类型参数，变成函数模板的形状
         * 3.为了该函数声明合法，必须先声明目标类模板
         *
         * 所以如果设函数模板funcB为类模板clsA的类外声明友元，顺序应为：
         *   ①clsA声明
         *   ②funcB声明
         *   ③clsA中声明funcB为友元
         *   ④funcB实现
         *   其中④可合并到②
         *
         * 关于1的可能原因：
         * 模板包含两种名字∶● 那些不依赖于模板参数的名字 ●那些依赖于模板参数的名字
         * 当使用模板时，所有不依赖于模板参数的名字都必须是可见的，这是由模板的提供者来保证的。
         * 而且，模板的提供者必须保证，当模板被实例化时，模板的定义，包括类模板的成员的定义，也必须是可见的。
         * 用来实例化模板的所有函数、类型以及与类型关联的运算符的声明都必须是可见的，这是由模板的用户来保证的。
         */
        friend void nightSkirtShow<>(Lady<T, R> lady);

    public:
        Lady() {
            cout << typeid(name).name() << endl;
            cout << typeid(age).name() << endl;
        }

        Lady(T name, R age);

        /*
         * 当我们使用一个类模板类型时必须提供模板实参，但这一规则有一个例外：
         * 在类模板自己的作用域中，我们可以直接使用模板名而不提供实参∶
         */
        void wearDress(Lady lady) {
            cout << lady.name << endl;
            cout << "小骚骚穿晚礼服发骚" << endl;
        }

        void ladyShow();
    };

    template<class T, class R>
    void nightSkirtShow(Lady<T, R> lady) {
        cout << "【类模板的友元全局函数在类模板中声明在类模板外实现】之女士睡裙大秀" << endl;
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
 * 1.父类继承类模板时，子类必须明确指定父类中的所有泛型
 * 2.如果想灵活指定父类中的类型，子类也需要变为类模板
 */
TEST(classTemplate, inheritance) /* NOLINT */
{
    Derived derived;
    Derived4<int, string> nigga;
}

//1.构造函数的类外实现
template<class T, class R>
Lady<T, R>::Lady(T name, R age) {
    this->name = name;
    this->age = age;
}

//2.成员函数的类外实现
template<class T, class R>
void Lady<T, R>::ladyShow() {
    cout << this->name << endl;
    cout << "为大家表演内衣大秀" << endl;
}



//'Lady' is not a class, namespace, or enumeration
//void Lady::ladyShow() {
//    cout << this->name << endl;
//    cout << "为大家表演内衣大秀" << endl;
//}


/*
 * 与其他任何类相同，我们既可以在类模板内部，也可以在类模板外部为其定义成员函数，
 * 且定义在类模板内的成员函数被隐式声明为内联函数。类模板的成员函数本身是一个普通函数。
 * 但是，类模板的每个实例都有其自己版本的成员函数。因此，类模板的成员函数具有和模板相同的模板参数。
 * 因而，定义在类模板之外的成员函数就必须以关键字 template 开始，后接类模板参数列表。
 * 与往常一样，当我们在类外定义一个成员时，必须说明成员属于哪个类。
 * 而且，从一个模板生成的类的名字中必须包含其模板实参。当我们定义一个成员函数时，模板实参与模板形参相同。
 * 即，对于 strB1ob 的一个给定的成员函数ret-type StrBlob;:member-namefparm-list)
 * 对应的 Blob 的成员应该是这样的∶ template <typename T>
 */
TEST(classTemplate, memFuncOutSide) /* NOLINT 类模板的成员函数的类外的实现*/
{
    Lady<string, int> lady("小骚骚", 27);
    lady.ladyShow();
}

/*
 * 当编译器遇到一个模板定义时，它并不生成代码。只有当我们实例化出模板的一个特定版本时，
 * 编译器才会生成代码。当我们使用（而不是定义）模板时，编译器才生成代码，
 * 这一特性影响了我们如何组织代码以及错误何时被检测到。通常，当我们调用一个函数时，
 * 编译器只需要掌握函数的声明。类似的，当我们使用一个类类型的对象时，类定义必须是可用的，
 * 但成员函数的定义不必已经出现。因此，我们将类定义和函数声明放在头文件中，
 * 而普通函数和类的成员函数的定义放在源文件中。模板则不同;为了生成一个实例化版本，
 * 编译器需要掌握函数模板或类模板成员函数的定义。因此，与非模板代码不同，模板的头文件通常既包括声明也包括定义。
 */
#include "swiss.hpp"

TEST(classTemplate, subfileWritine) /* NOLINT 类模板的分文件编写*/
{
    Swiss<string, int> zzr("周子瑞", 25);
    zzr.show();
}

/*
 * 1.类模板的友元全局函数直接在类模板内实现，直接写
 * 2.类模板的友元全局函数在类模板外实现，很不好写，建议算了
 */


TEST(classTemplate, withFriend) /* NOLINT 类模板与友元*/
{
    Lady<string, int> lady("朴智妍", 24);
//    ladyDaiShow(lady);
    nightSkirtShow(lady);
}