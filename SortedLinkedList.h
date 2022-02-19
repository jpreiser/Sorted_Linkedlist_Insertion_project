#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include "ItemType.h"
#include "ListNode.h"

using namespace std;

class SortedLinkedList {
public:
    /* Initialize a sorted linked list object. */
    SortedLinkedList();

    /* Free up all the user allocated memory and destroy the SLL instance. */
    ~SortedLinkedList();

    /* Return the length of the linked list. */
    const int length();

    /* Insert item into the linked list while maintaining the ascending order of the list. */
    void insertItem(ItemType item);

    /* ListNode that contains item should be deleted. */
    void deleteItem(ItemType item);

    /* Search the ListNode for item and return its index. */
    int searchItem(ItemType item);

    /* Returns the next item in the list pointed to by this current position pointer. */
    ItemType getNextItem();

    /* Reset the currentPos pointer to null to reset the list. */
    void resetList();

    /* A function for printing out the current list. */
    void printList(SortedLinkedList toPrint);

    /* Takes two lists and merges them, sorting them into a new sorted list. */
    SortedLinkedList merge(SortedLinkedList list1, SortedLinkedList list2);

    /* Deletes alternating nodes in a linked list, skipping the first node. */
    SortedLinkedList deleteAlternatingNodes(SortedLinkedList list);

    /* Finds the common elements in two sorted linked lists and returns a sorted list of those common elements. */
    SortedLinkedList findCommon(SortedLinkedList list1, SortedLinkedList list2);

private:
    ListNode *head;
    ListNode *currentPos;

}; // SortedLinkedList

#endif
