#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>
#include <fstream>

//�ͷ����������ռ䵽��ǰ������
using namespace std;
//����������
using godzInt = int;

/*
 * �ȿ�������using��ô������Ҫ�Ʒ���
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
 * ������ios::out��Դ�룬��̬Ҫ����
 */
using namespace theEnum;
TEST(the_enum,enumInClass) /* NOLINT */
{
    cout << Human::usaNigger << endl;
    cout << Human::chinaNigger << endl;
}