#include <string>
#include <utility>
using namespace std;


namespace modelA{
    class Person{
        string name;
        int age;
    public:
        Person() {}

        Person(string name, int age) : name(std::move(name)), age(age) {}

        const string &getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }
    };
};

