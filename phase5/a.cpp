#include <gtest/gtest.h>
#include <string>
#include <utility>

using namespace std;

/*
 * ģ���� C++�з��ͱ�̵Ļ�����һ��ģ�����һ���������������ͼ����˵��ʽ��
 * ��ʹ��һ�� vector �����ķ������ͣ����� find �����ķ��ͺ���ʱ��
 * �����ṩ�㹻����Ϣ������ͼת��Ϊ�ض��������������ת�������ڱ���ʱ��
 */

template<typename T>
void iSwap(T& a,T& b){
    T temp = a;
    a = b;
    b = temp;
}
/*
 * ������������һ��ģ�嶨��ʱ�����������ɴ��롣ֻ�е�����ʵ������ģ���һ���ض��汾ʱ���������Ż����ɴ��롣
 * ������ʹ�ã������Ƕ��壩ģ��ʱ�������������ɴ��롣
 */
TEST(functionTemplate,swapImplementByTemplate) /* NOLINT ͨ������ģ��ʵ�ֽ�������ֵ*/
{
    int a = 43;
    int b = 96;
    char c = 'b';
    //1.�Զ������Ƶ�
    /*
     *
     */
    iSwap(a,b);

    //�Զ������Ƶ�������������ͱ�����ģ��淶һ��
//    iSwap(a,c);

    //2.��ʽָ������
    iSwap<int>(a,b);

    cout << a << b << endl;

}

template<typename T>
void nigger(){
    cout << "����" << endl;
}
/*
 * T�ľ������ͱ��뱻��ȷָ����ģ��ſ���ʹ��
 */
TEST(functionTemplate,TmustBeAssign) /* NOLINT */
{
    int a = 10;
    //��������Ͳ���֧���Զ��Ƶ���
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
 * ������ʽ����ת����
 * 1.��ͨ�������ÿ��Է�����ʽ����ת��
 * 2.ģ�庯����������Զ��Ƶ���������ʽת����
 * �����ʽָ����T�����ͣ�����ת
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
    cout << "��ͨ��������" << endl;
}

template<class T>
void myPrint(T a,T b){
    cout << "����ģ�����" << endl;
}

template<class T>
void myPrint(T a,T b,T c){
    cout << "���ؤκ���ģ�����" << endl;
}
/*
 * 1.���ȵ����պ�����ʹ�պ���ʵ�ֶ�û��
 * 2.����ͨ����ģ������б��Ӹ��������ţ�ǿ�Ƶ��ú�ģ
 * 3.��ģҲ��������
 * 4.�����ģ����ƥ�䣨ָ����ʱͬ�����պ���Ҫ������ʽת���������ȵ���
 */
TEST(functionTemplate,rulesOfInvoke) /* NOLINT ���ù���*/
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
 * �����庯��ģ����������汾ʱ�����Ǳ����Ͻӹ��˱������Ĺ�����
 * ��������Ϊԭģ���һ������ʵ���ṩ�˶��塣��Ҫ����ҪŪ���һ���������汾��������һ��ʵ����
 * ���Ǻ�������һ�����ذ汾���������ı�����ʵ����һ��ģ�壬��������������ˣ���������Ӱ�캯��ƥ�䡣
 */
TEST(functionTemplate,specialization) /* NOLINT ģ��Ӧ��������������*/
{
    Girl ylm("����",6.0,6.5);
    Girl wyw("��ޱ",7.0,4.0);
    cout << greaterThan(wyw,ylm) << endl;

}
//����һ�������ĵ�����it��ƫ����n��������it+n�Ľ�����
template<typename T>
auto trt(T it, int n) -> decltype(*it){
    it += n;
    return *it;
}

/*
 * �����У�����֪������Ӧ�÷���*it������֪�����ǿ����� decltype��*it������ȡ�˱��ʽ�����͡�
 * ���ǣ��ڱ��������������Ĳ����б�֮ǰ��it ���ǲ����ڵġ�Ϊ�˶���˺��������Ǳ���ʹ��β�÷������͡�
 * ����β�÷��س����ڲ����б�֮��������ʹ�ú����Ĳ�����
 * ����������֪ͨ������ trt �ķ�������������� it �����Ľ��������ͬ��
 * ���������������һ����ֵ�����ͨ�� decltype �ƶϵ�����Ϊ it ��ʾ��Ԫ�ص����͵����á�
 * ��ˣ������һ�� string ���е��� trt���������ͽ��� string&������� int ���У��򷵻������� int&��
 */
TEST(functionTemplate,trailing_return_type) /* NOLINT β�÷�������*/
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout << trt(v.begin(),2) << endl;
}