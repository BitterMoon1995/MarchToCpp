#include <gtest/gtest.h>
#include <string>

using namespace std;

/* ���ʹ��
 * 1.�ı��滻
 * 2.�滻�ɿմ�����ɾ����
 * ��3.��������
 */

//����ʹ��
//����꣬���滻Ϊ 1���걾�ʾ���Ԥ����׶ε��ı��滻������
#define a 1
//����꣬���滻Ϊ ����ɫ���ڡ�
#define b "��ɫ����"

TEST(macro,sima) /* NOLINT */
{
    cout << a << endl;
    cout << b << endl;
}

//������װ��ʹ��֮ #define X
//�����nigger������Ԥ��������н����滻Ϊ�����ַ�������ɾ��������
//��������Ҫ��Ϊ�˱��ĳЩ���ݣ�ʹ�����Ķ����ܹ������Ǳ��������壬ͬʱ�ֲ�Ӱ�챻�����Դ���롣
#define nigger

TEST(macro,siqinma) /* NOLINT */
{
    cout << nigger + "ǰ����ʲô��"<< endl;
}

//��ʼ����֮#if  #endif

/*
 * 1.�����sidiemaΪ3��ע������Ǻ꾲̬����������ʹ
 * 2.���sidiema����0����������1
 * 3.�������sidiema����1����������2
 * 4.�����������3������ȫ�����Ա���
 */
TEST(macro,sidiema) /* NOLINT */
{
#define sidiema 1
#if sidiema == 0
    cout << "c == 0���������뱾�����" << endl;//�����1
#elif sidiema == 1
    cout << "c == 1���������뱾�����" << endl;//�����2
#else
    cout << "�������������뱾�����" << endl;//�����3
#endif
}

/*
 * �Ʒ���
 */
TEST(macro,siquanjia) /* NOLINT */
{
#ifndef siquanjia
    cout << "�Ƿ�û�ж�����ȫ�ң�" << endl;
#define siquanjia
    cout << "�ǣ�������ȫ��" << endl;
#else
    cout << "��" << endl;
#endif

#ifdef siquanjia
    cout << "�Ƿ�������ȫ�ң�" << endl;
#undef siquanjia
    cout << "�ǡ���ȡ������" << endl;
#else
    cout << "��" << endl;
#endif
}

/*
 * 1.���ְѺ�д���޿ײ��롢�޴����ڣ������������β��б����ڡ������ڡ�����������
 * 2.�꺯����ô������
 */

/*
 *
#if _ITERATOR_DEBUG_LEVEL < 2
#define _DEBUG_LT_PRED(pred, x, y) static_cast<bool>(pred(x, y))
#define _DEBUG_ORDER_UNWRAPPED(first, last, pred)
#define _DEBUG_ORDER_SET_UNWRAPPED(otherIter, first, last, pred)

#else // _ITERATOR_DEBUG_LEVEL < 2
#define _DEBUG_LT_PRED(pred, x, y)                _Debug_lt_pred(pred, x, y)
#define _DEBUG_ORDER_UNWRAPPED(first, last, pred) _Debug_order_unchecked(first, last, pred)
#define _DEBUG_ORDER_SET_UNWRAPPED(otherIter, first, last, pred) \
    _Debug_order_set_unchecked<otherIter>(first, last, pred)
 */


#define sum(a,b) ((a)+(b))
TEST(macro,argsMacro) /* NOLINT */
{
    int i = 1;
    int j = 2;
    cout << sum(1,2) << endl;
}

void sima(){
    cout << "˾����" << endl;
}

#define zazhong
//#ifdef zazhong
//#undef zazhong
//#endif
TEST(macro,macroPrefix) /* NOLINT */
{
    zazhong sima();
}
