#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

using namespace std;

class House{
    //如何让函数myNigga进入公主の闺房
    friend void myNigga(House& house);
    string bedroom;
public:
    string livingRoom;

    House(string bedroom, string livingRoom) : bedroom(std::move(bedroom)), livingRoom(std::move(livingRoom)) {}
};

void myNigga(House& house){
    cout << house.livingRoom << endl;
    cout << house.bedroom << endl;
}

TEST(the_friend,functionAsFriend) /* NOLINT */
{
    House princessHouse("公主卧室","公主客厅");
    myNigga(princessHouse);
}

