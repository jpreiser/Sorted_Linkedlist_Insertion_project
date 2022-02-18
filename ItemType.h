#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <cstdlib>

using namespace std;

/* A class for constructing ItemTypes. */
class ItemType {
public:
	/* An enumerator for the ItemType class. */
	enum Comparisson {GREATER, LESS, EQUAL};

    // Default Constructor
    ItemType();

    /* Compare the value of item with the current object's value and return
       GREATER, LESS, or EQUAL. */
    Comparisson compareTo(ItemType item);

    /* Return the value instance variable. */
    int getValue() const;

    /* Initializes the data member by variable num. */
    void initialize(int num);

private:
    int value;
}; //

#endif
