#include <string>
using namespace std;

template<typename T>
class MyArray{
    T* addr;//堆区开辟的数组的指针
    int capacity;
    int size;

public:
    MyArray(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->addr = new T[capacity];
    }

    ~MyArray(){
        delete addr;
    }

    MyArray(const MyArray& myArr){
        this->capacity = myArr.capacity;
        this->size = myArr.size;

        this->addr = new T[capacity];

        for (int i = 0; i < size; ++i) {
            this->addr[i] = myArr.addr[i];
        }
    }

    MyArray& operator=(const MyArray& myArr){
        if (this == myArr)
            return *this;

        delete addr;

        this->capacity = myArr.capacity;
        this->size = myArr.size;
        this->addr = new T[capacity];

        for (int i = 0; i < size; ++i) {
            this->addr[i] = myArr.addr[i];
        }

        return *this;
    };

    MyArray& add(const T& val){
        if (size == capacity)
            return *this;
        addr[size] = val;
        size++;
        return *this;
    }

    bool pop(){
        if (size == 0)
            return false;
        size--;
    }

    //如果要使返回值作为左值，需返回引用
    T& operator[](int index){
        return addr[index];
    }

    void traverse(){
        for (int i = 0; i < size; ++i) {
            cout << addr[i] << endl;
        }
    }

    int getCapacity() const {
        return capacity;
    }

    int getSize() const {
        return size;
    }
};