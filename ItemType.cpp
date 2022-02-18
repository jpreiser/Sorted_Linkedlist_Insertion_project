#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ItemType.h"

using namespace std;

ItemType::ItemType() {
} // ItemType

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

/* Returns the value of the ItemType.*/
int ItemType::getValue() const {
    return value;
} // getValue

/* Assigns a value to the val of the ItemType.*/
void ItemType::initialize(int num) {
    value = num;
} //
