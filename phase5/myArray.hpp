#include <string>
using namespace std;

template<typename T>
class MyArray{
    T* addr;//�������ٵ������ָ��
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

    //���Ҫʹ����ֵ��Ϊ��ֵ���践������
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