#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <cstdlib>
#include "ItemType.h"

using namespace std;

class ListNode {
public:
    ItemType item;
    ListNode *next = NULL;
}; // ListNode

#endif
