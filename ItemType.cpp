#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ItemType.h"

using namespace std;

ItemType::ItemType() {
	value = 0;
} // ItemType


ItemType::Comparisson ItemType::compareTo(ItemType item) {
    if (item.getValue() == value) {
        return EQUAL;
    } else if (item.getValue() > value) {
        return GREATER;
    } else { //if (item.getValue() < value) {
        return LESS;
    } // compareTo
}

/* Returns the value of the ItemType.*/
int ItemType::getValue() const {
    return value;
} // getValue


/* Assigns a value to the val of the ItemType.*/
void ItemType::initialize(int num) {
    value = num;
} //
