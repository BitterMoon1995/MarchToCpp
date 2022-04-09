#include <gtest/gtest.h>
#include <string>

using namespace std;

/* 宏的使用
 * 1.文本替换
 * 2.替换成空串，即删除宏
 * ★3.条件编译
 */

//基本使用
//定义宏，并替换为 1。宏本质就是预编译阶段的文本替换死妈了
#define a 1
//定义宏，并替换为 “白色内内”
#define b "白色内内"

TEST(macro,sima) /* NOLINT */
{
    cout << a << endl;
    cout << b << endl;
}

//不基本装怪使用之 #define X
//定义宏nigger，并在预处理过程中将其替换为【空字符串（即删除）】。
//这样做主要是为了标记某些内容，使程序阅读者能够清楚标记表明的意义，同时又不影响被编译的源代码。
#define nigger

TEST(macro,siqinma) /* NOLINT */
{
    cout << nigger + "前面有什么？"<< endl;
}

//开始死妈之#if  #endif

/*
 * 1.定义宏sidiema为3，注意必须是宏静态常量都不好使
 * 2.如果sidiema等于0，编译代码段1
 * 3.否则如果sidiema等于1，编译代码段2
 * 4.否则编译代码段3，其他全部忽略编译
 */
TEST(macro,sidiema) /* NOLINT */
{
#define sidiema 1
#if sidiema == 0
    cout << "c == 0成立，编译本程序段" << endl;//代码段1
#elif sidiema == 1
    cout << "c == 1成立，编译本程序段" << endl;//代码段2
#else
    cout << "都不成立，编译本程序段" << endl;//代码段3
#endif
}

/*
 * 破防了
 */
TEST(macro,siquanjia) /* NOLINT */
{
#ifndef siquanjia
    cout << "是否没有定义死全家？" << endl;
#define siquanjia
    cout << "是，定义死全家" << endl;
#else
    cout << "否" << endl;
#endif

#ifdef siquanjia
    cout << "是否定义了死全家？" << endl;
#undef siquanjia
    cout << "是。并取消定义" << endl;
#else
    cout << "否" << endl;
#endif
}

/*
 * 1.杂种把宏写得无孔不入、无处不在，函数声明、形参列表、块内、函数内。。。。。。
 * 2.宏函数怎么灰事呢
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
    cout << "司马了" << endl;
}

#define zazhong
//#ifdef zazhong
//#undef zazhong
//#endif
TEST(macro,macroPrefix) /* NOLINT */
{
    zazhong sima();
}
