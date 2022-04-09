#include <ostream>

// cl women.cpp /d1reportSingleClassLayoutGirl


using namespace std;

class Woman {
public:

    virtual void wear() {
    }
};

class Girl : public Woman {
public:
//    void wear() override {
//    }
};

class Lady : public Woman {
public:
    void wear() override {
    }
};

//int main(){
//    return 0;
//}

