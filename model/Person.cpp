//
// Created by Administrator on 2021/5/27.
//

#include "Person.h"

#include <utility>

Person::Person(string name, int age) : name(std::move(name)), age(age) {}

