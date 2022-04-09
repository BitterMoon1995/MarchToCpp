#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;
/**
 * 优菈老婆之运算符重载
 * 编译器通过翻译特定的operator函数来重载各个运算符
 */

class Employee{
    int salary;
    int bonus;
    double* wifeLoan;
public:
    /*
     * 总书记指示：指针属性最好约定一个合法初值，注意不能是nullptr（本来是nullptr）！
     * 否则在构造对象时，只要不给指针属性值，就花式报
     * unknown file: error: SEH exception with code 0xc0000005 thrown in the test body.
     * 花式报非法内存给总书记整麻了。
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

    //使用成员函数进行重载该类的运算符
    Employee operator+(Employee& employee) const{
        Employee temp;
        temp.salary = this->salary + employee.salary;
        temp.bonus = this->bonus + employee.bonus;
        return temp;
    }
    //operator函数本身也可以进行函数重载
    Employee operator+(int extraGain) const{
        Employee employee;
        employee.salary = this->salary;
        employee.bonus = this->bonus + extraGain;
        return employee;
    }

    /* 定义全局（友元）函数重载左移运算符，理由：
     * 如果要实现惯用输出格式 cout << object << endl，只能用这种方式，
     * 即我们是在为类ostream重载其左移运算符，而重载函数的参数是我们的目标类Employee。
     * 同时为了重载函数能够访问类Employee的私有属性，将其在该类中定义为友元函数。
     *
     * 函数返回ostream&以方便链式调用。
     *
     * 如果定义为Employee的成员函数，则表示仅重载类Employee的左移运算符，
     * 会出现employee<<cout（=employee.operator<<）这样不自然的代码
     * */
    friend ostream& operator<<(ostream& output,Employee& employee){
        output << "基本工资："<< employee.salary << endl;
        output << "奖金外快："<< employee.bonus << endl;
        output << "社畜房贷：" << *employee.wifeLoan << endl;
        return output;
    }

    /*
     * 重载前置递增运算符
     * 返回&Emoployee，理由：
     * 自增运算本身一般都有结果，比如本来的i=1,++i就等于2，
     * 如果要输出employee前置自增的结果cout << ++godz << endl，就需要有返回值，不能返回null；
     * 必须返回自身对象引用，否则++(++employee)的结果等于++employee，
     * 因为第n+1次自增操作的对象永远都是第一次自增结果的值拷贝。
     */
    Employee& operator++(){
        salary += 100;
        return *this;
    }
    /*
     * 重载后置递增运算符
     * C++通过占位符参数int区分前置递增重载与后置递增重载，后置递增就得为该参数。
     * 后置递增的逻辑是，先新建临时值以记录当前对象的状态，再进行增加运算，再返回之前记录的临时值。
     * 与前置递增相反，后置递增必须返回值，因为不能返回局部变量的引用
     */
    Employee operator++(int ){
        const Employee temp = *this;
        salary += 100;
        return temp;
    }

    Employee& operator=(const Employee& employee){
        /* 自赋值检查
         * 下方的指针属性释放会产生自赋值问题即：如果我自己给自己赋值呢？
         * 比如Employee godz(5000,2000,2500000);godz=godz;
         * 不难看出如果源对象和目标对象是同一个对象而不作检查，
         * 那么godz的wifeLoan会被释放，然后被深拷贝为一个空指针，导致godz的数据结构被破坏。
         * 如果wifeLoan并不是double而是类对象，问题会更严重。
         *
         * 所以如果发现是对象在用自己给自己赋值，一个直接返回自己的引用*/
        if (this == &employee)
            return *this;

        salary = employee.salary;
        bonus = employee.bonus;

        /*
         * 如果目标对象的指针属性非空，要先释放空间、指空，再为其进行深拷贝。
         * 不然它之前指向的那个玩意儿永远得不到内存释放，不就泄露了。
         * 注意【不需要】检查wifeLoan是否为空，delete关键字本身就会检查空指针，delete空指针也是合法的。
         */
        delete wifeLoan;
        wifeLoan = new double (*employee.wifeLoan);

        return *this;
    }

    //重载关系运算符之大于号
    bool operator>(const Employee& employee) const{
        if ((salary + bonus) > (employee.salary + employee.bonus))
            return true;
        return false;
    }

    //重载函数调用运算符 “ () ”
    void operator()() const{
        cout << "【员工收入之大扒皮】" << endl;
        cout << "工资："<< salary << endl;
        cout << "奖金："<< bonus << endl;
    }
    void operator()(const string& name) const{
        printf("隆重介绍新员工【%s】！！！\n",name.c_str());
    }
};

//全局函数运算符重载。 不好使，在类外访问不到私有属性非得要getset
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
 * 同一类的各个对象之间可以通过 = 进行相互赋值，但是如果类存在指针属性，默认的赋值运算会进行浅拷贝，
 * 导致共享属性问题，从而在析构等函数调用时出现Assertion failed: _CrtIsValidHeapPointer(block)。
 *
 * 所以如果类存在指针属性，必须重载赋值运算符。
 *
 * 还要为存在指针属性的类，考虑自赋值问题。
 */
TEST(operatorReload,assign) /* NOLINT 赋值运算符重载*/
{
    Employee yanghuan(4000,1000,2500000);

    Employee godz;
    Employee wpc;
    godz = wpc = yanghuan;
    cout << godz << endl;
    cout << wpc << endl;
}

TEST(operatorReload,relationalOperator) /* NOLINT 关系运算符重载*/
{
    Employee godz(5000,2000,0);
    Employee wpc(4000,1000,2500000);
    Employee mdw(7000,5000,0);
    cout << (godz > wpc) << endl;
    cout << (godz > mdw) << endl;
}
/*
 * 函数调用运算符的重载非常灵活，没有固定的写法。
 * 有时难以区分到底是在调用函数还是在调用对象的函数调用。
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

TEST(operatorReload,invokeOperator) /* NOLINT 函数调用运算符重载（仿函数）*/
{
//    Employee godz(5000,2000,0);
//    godz("周子瑞周神");
//    godz();
    Plus plus;
    cout << plus(1,1) << endl;
    cout << plus2(1,1) << endl;

    //用匿名对象来猴（匿名仿函数对象）
    cout << Plus()(1,1) << endl;
}