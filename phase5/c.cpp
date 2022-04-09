#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <ostream>

#include "myArray.hpp"

using namespace std;

TEST(myArray,a) /* NOLINT */
{
    MyArray<int> myArray(5);
    MyArray<int> myArray2(myArray);
    MyArray<int> myArray3 = myArray;

    myArray.add(1).add(2);
    myArray.traverse();
    cout << myArray.getSize() << endl;
    cout << myArray.getCapacity() << endl;

    myArray.pop();
    myArray.traverse();
    cout << myArray.getSize() << endl;
    cout << myArray.getCapacity() << endl;
}