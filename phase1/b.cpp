#include <gtest/gtest.h>

using namespace std;
TEST(processControl, ifelse) /* NOLINT */
{
    int score = 500;
    if (score < 560){
        cout << "二本five" << endl;
    } else if (score < 660){
        cout << "双非five" << endl;
    } else{
        cout << "985人上人带秀" << endl;
    }
}
TEST(processControl, switchCase) /* NOLINT */
{
    int i = 2800;
    switch (i) {
        case 2800:{
            cout << "简自豪死妈" << endl;
        }
        case 4396:{
            cout << "明凯死妈" << endl;
        }
        default:{
            cout << "a" << endl;
            break;
        }
    }
}

TEST(ProcessControll,foreach) /* NOLINT */
{
//    string s = "nigger bees";
//    for (char c: s) {
//        cout << c << endl;
//    }

    int a[10] = {0,1,2,3,4,5,6,7,8,9};

    for (int &i:a){
        i++;
    }

    for (int i:a) {
        cout << i << endl;
    }
}