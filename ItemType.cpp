

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ItemType.h"

using namepace std;

Comparisson ItemType::compareTo(ItemType item) {
    Comparisson comp;
    if (item.getValue() == value) {
        comp = EQUAL;
    } else if (item.getValue() > value) {
        comp = GREATER;
    } else if (item.getValue() < value) {
        comp = LESS;
    }
    return comp;

} // compareTo

int ItemType::getValue() const {
    return value;
} // getValue

void ItemType::initialize(int num) {
    value = num;
} //
