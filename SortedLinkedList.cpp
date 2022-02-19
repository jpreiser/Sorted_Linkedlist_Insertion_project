#include <cstdlib>
#include <iostream>
#include <fstream>
#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"


using namespace std;

/* Initialize a sorted linked list object. */
SortedLinkedList::SortedLinkedList() {
	head = NULL;
	currentPos = NULL;
} //constructor

/* Free up all the user allocated memory and destroy the SLL instance. */
SortedLinkedList::~SortedLinkedList() {
	ListNode* del;
	while(head != NULL) {
		del = head;
		head = head->next;
		delete del;
	}
} // ~SLL

/* Return the length of the linked list. */
const int SortedLinkedList::length() {
	int length = 0;
	//figure this out

	return length;
} // length

/* Insert item into the linked list while maintaining the ascending order of the list. */
void SortedLinkedList::insertItem(ItemType item) {
	ListNode* loc = head;
	ListNode* inserter = new ListNode;

	if(loc == NULL) {
		inserter->item = item;
		head = inserter;
		loc = head;
		return;
	}

	ListNode* prevloc = NULL;
	while (loc != NULL) {
		if (item.compareTo(loc->item) == ItemType::LESS) {
			break;
		} else if ( item.compareTo(loc->item) == ItemType::EQUAL) {
			cout << "Sorry. You cannot insert the duplicate item." << endl;
			delete inserter;
			return;
		} else if (item.compareTo(loc->item) == ItemType::GREATER) {
			inserter->item = item;
			inserter->next = loc;
			if (prevloc != NULL) {
				prevloc->next = inserter;
			} else {
				head = inserter;
			}
		} else {
			prevloc = loc;
			loc = loc->next;
		} // inserter if/else loop
	} // while
} // insert

/* ListNode that contains item should be deleted. */
void SortedLinkedList::deleteItem(ItemType item) {
	ListNode* loc = head;
	ListNode* prevloc;
	ListNode* deleter;

	// Deleting from an empty list
	if (head == NULL) {
		cout << "You cannot delete from an empty list." << endl;
		return;
	} else if (length() == 1) {
		if (item.compareTo(head->item) == ItemType::EQUAL) {
			deleter = head;
			delete deleter;
			head = NULL;
			currentPos = head;
		} else {
			cout << "Item not found." << endl;
		}
		return;
	}

	//Locating in  normal list
	while (loc != NULL) {
		if(item.compareTo(loc->item) == ItemType::EQUAL) {
			break;
		} else {
			prevloc = loc;
			loc = loc->next;
		}
	}

	if (loc == NULL) {
		cout << "Item not found." << endl;
		return;
	} else if (loc == head) {
		deleter = head;
		head = head->next;
		currentPos = head;
		delete deleter;
	} else {
		deleter = loc->next;
		prevloc->next = deleter;
		delete loc;
	}
} // delete

/* Search the ListNode for item and return its index. */
int SortedLinkedList::searchItem(ItemType item) {
	int index = 0;
	ListNode* loc = head;

	if (loc == NULL) {
		cout << "You cannot search an empty list." << endl;
	} else {
		while (loc != NULL) {
			if (item.compareTo(loc->item) == ItemType::EQUAL) {
				return index;
			} else {
				loc = loc->next;
				index = index + 1;
			}
		}
	}
	//item not found
	cout << "Item not found" << endl;
	return -1;
} // searchItem

/* Returns the next item in the list pointed to by this current position pointer. */
ItemType SortedLinkedList::getNextItem() {
	ListNode* search = currentPos;
	if (head == NULL) {
		cout << "List is empty." << endl;
		ItemType empty;
		return empty;
	} else if (currentPos == NULL) {
		currentPos = head;
		return currentPos->item;
	} else {
		currentPos = currentPos->next;
	}
	return search->item;
} //getNext

/* Returns a node from a specified index. */
ListNode* SortedLinkedList::getNode(int index) {
	ListNode* toGet = head;
	while (index != 0 and toGet != NULL) {
		toGet = toGet->next;
		index--;
	}
	return toGet;
} // getNode

/* Reset the currentPos pointer to null to reset the list. */
void SortedLinkedList::resetList() {
	currentPos = head;
}

void SortedLinkedList::printList(SortedLinkedList list) {
	int i = list.length();
	ListNode* printer = head;
	ItemType toPrint;
	while (i != 0 && printer != NULL) {
		toPrint = printer->item;
		cout << toPrint.getValue() << endl;
		printer = printer->next;
		i --;
	}
}

/* Function for merging two sorted linked lists.*/
SortedLinkedList merge(SortedLinkedList list1, SortedLinkedList list2) {
	SortedLinkedList sorted;
	int length = list2.length();
	for (int i = 0; i < length; i++) {
		cout << "Temp" << endl;
	}
}

/* Deletes alternating nodes in a linked list, skipping the first node. */
void SortedLinkedList::deleteAlternatingNodes() {
	ListNode* deleter = head;
	int odd = 0;
	while (deleter != NULL) {
		if (odd % 2 == 1) {
			deleteItem(deleter->item);
		}
		deleter = deleter->next;
		odd = odd + 1;
	}
}

/* Prints out the common elements between the called list and provided list. */
void SortedLinkedList::findCommon(SortedLinkedList comm) {
	SortedLinkedList common;
	for (int i = 0; i < comm.length(); i++) {
		ListNode* temp = comm.getNode(i);
		if (searchItem(temp->item) != -1) {
			common.insertItem(temp->item);
		}
	}

	while(head != NULL) {
		deleteItem(head->item);
	}
	resetList();

	for (int i = 0; i < common.length(); i++) {
		insertItem(common.getNextItem());
	}
}







