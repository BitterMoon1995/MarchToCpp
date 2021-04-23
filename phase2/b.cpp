#include <gtest/gtest.h>
using namespace std;

/*
 * ���ñ�����һ��������Ҳ����˵������ĳ���Ѵ��ڱ�������һ�����֡�
 * ���ñ������������õı�����������
 * һ�������ó�ʼ��Ϊĳ���������Ϳ���ʹ�ø��������ƻ����������ָ�������
 */

TEST(reference,alpha) /* NOLINT */
{
    int a = 10;
    int& b = a;
    cout << b << endl;
    b = 4396;
    cout << a << endl;

    int& c = a;
    //a����b��b����c
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
}

TEST(reference,notice) /* NOLINT */
{
    //���ñ����ʼ��
//    int& a;

    //���ó�ʼ�������ö��󲻿��Ըı�
    int a = 10;
    int& b = a;
    int c = 20;
    b = c;//�����Ǹ���ֵ����
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
//�βε�a��ʵ��a�����ã�ֻ����������õı�����ԭ����һ����
void swap(int& a,int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

TEST(reference,asArguments) /* NOLINT */
{
    int a = 10;
    int b = 4396;
    swap(a,b);
    cout << a << b << endl;
}

int& t1(){
    int a = 10;
    return a;
}

int& t2(){
    static int a = 10;
    return a;
}

TEST(reference,asReturnValue) /* NOLINT */
{
    //��Ҫ���÷��صľֲ�����
    //ref�����õ�a��t1()ִ�������ͷ���
//    int& ref = t1();
    int& ref = t2();
    cout << ref << endl;
    cout << ref << endl;

    //�������������ķ���ֵ�Ҳ������þֲ�����ʱ���ú����ĵ��ÿ�������ֵ��
    //��Ϊ�Ըú������õĲ������ǶԸ����������õı���������в���
    t2() = 4397;
    cout << ref << endl;
    cout << ref << endl;
}

