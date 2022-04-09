#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>
#include <fstream>

//释放整个命名空间到当前作用域
using namespace std;
//类型重命名
using godzInt = int;

/*
 * 先看下死妈using怎么灰事我要破防了
 */
TEST(the_enum, learnUsing) /* NOLINT */
{
    godzInt i = 0;
    cout << i << endl;
}

enum nigger {
    a = 0xff,b,c,d,e
};

static constexpr nigger f = static_cast<nigger>(0x10);

TEST(the_enum, a) /* NOLINT */
{
    cout << f << endl;
    cout << e << endl;
}

namespace theEnum{
    class Human{
    public:
        enum nigger {
            usaNigger
        };
        static constexpr nigger africaNigger = static_cast<const nigger>(0x8);
        static constexpr nigger chinaNigger = static_cast<const nigger>(0xf9);
    };
}

/*
 * 看不懂ios::out处源码，心态要崩了
 */
using namespace theEnum;
TEST(the_enum,enumInClass) /* NOLINT */
{
    cout << Human::usaNigger << endl;
    cout << Human::chinaNigger << endl;
}