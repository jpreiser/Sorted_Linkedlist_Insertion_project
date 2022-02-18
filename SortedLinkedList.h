


#include <cstdlib>
#include <iostream>
#include "ItemType.h"
#include "ListNode.h"

using namespace std;

class SortedLinkedList {
public:
    /* Initialize a sorted linked list object. */
    SortedLinkedList();

    /* Free up all the user allocated memory and destruct the SLL instance. */
    ~SortedLinkedList();

    /* Return the length of the linked list. */
    int length() const;

    /* Insert item into the linked list while maintaining the ascending order of the list. */
    void insertItem(ItemType item);

    /* ListNode that contains item should be deleted. */
    void deleteItem(ItemType item);

    /* Search the ListNode for item and return its index. */
    int searchItem(ItemType item);

    /* Returns the next item in the list pointed to by this current position pointer. */
    ItemType GetNextItem();

    /* Reset the currentPos pointer to null to reset the list. */
    void ResetList();

    /* Takes two lists and merges them, sorting them into a new sorted list. */
    SortedLinkedList merge(SortedLinkedList list1, SortedLinkedList list2);

    /* Deletes alternating nodes in a linked list, skipping the first node. */
    SortedLinkedList deleteAlternatingNodes(SortedLinkedList list);

    /* Findes the common elements in two sorted linked lists and retrurns a sorted list of those common elements. */
    SortedLinkedList findCommon(SortedLinkedList list1, SortedLinkedList list2);

private:
    ListNode *head;
    ListNode *currentPos;

} // SortedLinkedList
