

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "SortedLinkedList.h"
#include "NodeType.h"
#include "ListNode.h"


using namespace std;

/* Initialize a sorted linked list object. */
SortedLinkedList() {
	head = null;
	currentPos = null;
}

/* Free up all the user allocated memory and destroy the SLL instance. */
~SortedLinkedList() {
	head =
}

/* Return the length of the linked list. */
int length() const {

}

/* Insert item into the linked list while maintaining the ascending order of the list. */
void insertItem(ItemType item) {

}

/* ListNode that contains item should be deleted. */
void deleteItem(ItemType item) {

}

/* Search the ListNode for item and return its index. */
int searchItem(ItemType item) {

}

/* Returns the next item in the list pointed to by this current position pointer. */
ItemType GetNextItem() {

}

/* Reset the currentPos pointer to null to reset the list. */
void ResetList() {

}

SortedLinkedList merge(SortedLinkedList list1, SortedLinkedList list2) {

}

/* Deletes alternating nodes in a linked list, skipping the first node. */
SortedLinkedList deleteAlternatingNodes(SortedLinkedList list){

}


SortedLinkedList findCommon(SortedLinkedList list1, SortedLinkedList list2) {

}
