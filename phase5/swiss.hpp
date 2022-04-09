#include <string>
#include <ostream>
using namespace std;
template<class T,class R>
class Swiss{
public:
    T name;
    R age;

    Swiss(T name,R age);
    void show();
};

template<class T,class R>
Swiss<T,R>::Swiss(T name,R age){
    this->name = name;
    this->age = age;
}

template<class T,class R>
void Swiss<T,R>::show() {
    cout << this->name << endl;
    cout << this->age << endl;
}