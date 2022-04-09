#include <gtest/gtest.h>
#include <string>
#include <utility>

using namespace std;

/*
 * 模板是 C++中泛型编程的基础。一个模板就是一个创建类或函数的蓝图或者说公式。
 * 当使用一个 vector 这样的泛型类型，或者 find 这样的泛型函数时，
 * 我们提供足够的信息，将蓝图转换为特定的类或函数。这种转换发生在编译时。
 */

template<typename T>
void iSwap(T& a,T& b){
    T temp = a;
    a = b;
    b = temp;
}
/*
 * 当编译器遇到一个模板定义时，它并不生成代码。只有当我们实例化出模板的一个特定版本时，编译器才会生成代码。
 * 当我们使用（而不是定义）模板时，编译器才生成代码。
 */
TEST(functionTemplate,swapImplementByTemplate) /* NOLINT 通过函数模板实现交换两个值*/
{
    int a = 43;
    int b = 96;
    char c = 'b';
    //1.自动类型推导
    /*
     *
     */
    iSwap(a,b);

    //自动类型推导传入的数据类型必须与模板规范一致
//    iSwap(a,c);

    //2.显式指定类型
    iSwap<int>(a,b);

    cout << a << b << endl;

}

template<typename T>
void nigger(){
    cout << "尼哥儿" << endl;
}
/*
 * T的具体类型必须被明确指定，模板才可以使用
 */
TEST(functionTemplate,TmustBeAssign) /* NOLINT */
{
    int a = 10;
    //这种情况就不再支持自动推导了
//    nigger(a);
    nigger<int>();
}

int myAdd(int a,int b){
    return a + b;
}

template<typename T>
int iAdd(T a,T b){
    return a + b;
}

/*
 * 关于隐式类型转换：
 * 1.普通函数调用可以发生隐式类型转换
 * 2.模板函数，如果是自动推导，则不能隐式转换；
 * 如果显式指定了T的类型，可以转
 */
TEST(functionTemplate,implicitConvertion) /* NOLINT */
{
    char a = 'a';
    char b = 'b';
    int c = 1;
    cout << myAdd(a,b) << endl;
//    cout << iAdd(a,c) << endl;
    cout << iAdd<int>(a,c) << endl;
}

void myPrint(int a,int b);

void myPrint(int a,int b){
    cout << "普通函数调用" << endl;
}

template<class T>
void myPrint(T a,T b){
    cout << "函数模板调用" << endl;
}

template<class T>
void myPrint(T a,T b,T c){
    cout << "重载の函数模板调用" << endl;
}
/*
 * 1.优先调用普函。即使普函连实现都没有
 * 2.可以通过空模板参数列表（加个空中括号）强制调用函模
 * 3.函模也可以重载
 * 4.如果函模更优匹配（指调用时同名的普函需要类型隐式转换），优先调用
 */
TEST(functionTemplate,rulesOfInvoke) /* NOLINT 调用规则*/
{
    int a = 10;
    int b = 20;
    myPrint(a,b);

    myPrint<>(a,b);

    myPrint(a,a,a);

    char c1 = 's';
    char c2 = 'b';
    myPrint(c1,c2);
}

namespace functionTemplate{
    class Girl{
    public:
        string name;
        int age;
        float faceScore;
        float shapeScore;

        Girl(string name, float faceScore, float shapeScore) : name(std::move(name)), faceScore(faceScore),
                                                                      shapeScore(shapeScore) {}
    };
    float totalPoints(Girl& girl){
        return girl.faceScore * 1.2f + girl.shapeScore;
    }
}

using namespace functionTemplate;

template<class T>
bool greaterThan(T& a,T& b){
    return a > b;
}

template<>
bool greaterThan(Girl& a,Girl& b){
    return totalPoints(a) > totalPoints(b);
}
/*
 * 当定义函数模板的特例化版本时，我们本质上接管了编译器的工作。
 * 即，我们为原模板的一个特殊实例提供了定义。重要的是要弄清∶一个特例化版本本质上是一个实例，
 * 而非函数名的一个重载版本。特例化的本质是实例化一个模板，而非重载它。因此，特例化不影响函数匹配。
 */
TEST(functionTemplate,specialization) /* NOLINT 模板应对特殊数据类型*/
{
    Girl ylm("荔茗",6.0,6.5);
    Girl wyw("雨薇",7.0,4.0);
    cout << greaterThan(wyw,ylm) << endl;

}
//接收一个容器的迭代器it和偏移量n，并返回it+n的解引用
template<typename T>
auto trt(T it, int n) -> decltype(*it){
    it += n;
    return *it;
}

/*
 * 此例中，我们知道函数应该返回*it，而且知道我们可以用 decltype（*it）来获取此表达式的类型。
 * 但是，在编译器遇到函数的参数列表之前，it 都是不存在的。为了定义此函数，我们必须使用尾置返回类型。
 * 由于尾置返回出现在参数列表之后，它可以使用函数的参数。
 * 此例中我们通知编译器 trt 的返回类型与解引用 it 参数的结果类型相同。
 * 解引用运算符返回一个左值，因此通过 decltype 推断的类型为 it 表示的元素的类型的引用。
 * 因此，如果对一个 string 序列调用 trt，返回类型将是 string&。如果是 int 序列，则返回类型是 int&。
 */
TEST(functionTemplate,trailing_return_type) /* NOLINT 尾置返回类型*/
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << trt(v.begin(),2) << endl;
}