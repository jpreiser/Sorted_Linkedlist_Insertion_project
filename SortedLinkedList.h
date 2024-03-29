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

    /* A method for retrieving a specified node from the list. */
    ListNode* getNode(int index);

    /* Reset the currentPos pointer to null to reset the list. */
    void resetList();

    /* A function for printing out the current list. */
    void printList();

    /* Takes two lists and merges them, sorting them into a new sorted list. */
    SortedLinkedList merge(SortedLinkedList list, SortedLinkedList toMerge);

    /* Deletes alternating nodes in a linked list, skipping the first node. */
    void deleteAlternatingNodes();

    /* Finds the common elements in two sorted linked lists and returns a sorted list of those common elements. */
    void findCommon(SortedLinkedList comm);

    /* Returns the head of a given list. */
    ListNode* getHead();

private:
    ListNode *head;
    ListNode *currentPos;

}; // SortedLinkedList

#endif
