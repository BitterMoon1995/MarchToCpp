#include <gtest/gtest.h>

using namespace std;

const double pi = 3.14;

class Circle{
public:
    string color;
    double radius;
    //如果成员方法不会改变成员变量，那么可以在方法名后加个const修饰
    double getCircumference() const{
        return 2 * pi * radius;
    }
    void setRadius(double new_radius){
        radius = new_radius;
    }
};
/*
 * 封装的意义1：将属性和行为作为一个整体，来表现现实中的事物
 */
TEST(encapsulation, meaning1) /* NOLINT */
{
    Circle circle;
    circle.color = "绿色";
    circle.radius = 10;
    double cf = circle.getCircumference();
    cout << cf << endl;

    circle.setRadius(5);
    cout << circle.getCircumference() << endl;
}

class FemaleAnimal{
private:
    int exNum{};
protected:
    int age{};
public:
    string name;
    void setAnimalsExNum(int exNum_New){
        exNum = exNum_New;
    }
    int femaleAnimalDeathMon(){
        return exNum *= 10;
    }
};

/*
 * 封装的意义2：类在设计时，可以把属性和行为放在不同的权限下，加以控制
 */
TEST(encapsulation, meaning2) /* NOLINT */
{
    FemaleAnimal femaleAnimal;
    femaleAnimal.setAnimalsExNum(2);
    cout << femaleAnimal.femaleAnimalDeathMon() << endl;
}

class TestClass{
    string name;
};

struct TestStruct{
    string name;
    void n(){
        cout << "nigga is coming:" << endl;
        cout << name << endl;
    }
};
/*
 * 都可以作为【类】使用，只不过默认的权限不同：
 * class默认为private，struct为public
 */
TEST(encapsulation, classVsStruct) /* NOLINT */
{
    TestClass testClass;
//    testClass.name;
    TestStruct testStruct;
    testStruct.name = "jack";
    testStruct.n();
}