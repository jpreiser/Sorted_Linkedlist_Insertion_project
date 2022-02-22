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
	ListNode* del = NULL;
	while(del != NULL) {
		del = head;
		head = head->next;
		delete del;
	}
} // ~SLL

/* Return the length of the linked list. */
const int SortedLinkedList::length() {
	int length = 0;
	ListNode* counter = head;
	if (head == NULL) {
		return length;
	}
	while (counter != NULL) {
		counter = counter->next;
		length = length + 1;
	}
	return length;
} // length

/* Insert item into the linked list while maintaining the ascending order of the list. */
void SortedLinkedList::insertItem(ItemType toInsert) {
	ListNode* temp = new ListNode();
	ListNode* prev = new ListNode();
	ListNode* loc = head;


	if(head == NULL) {
		temp->item = toInsert;
		head = temp;
		currentPos = head;
		return;
	}

	if (toInsert.compareTo(loc->item) == ItemType::GREATER) {
		temp->item = toInsert;
		temp->next = head;
		head = temp;
		return;
	}

	while (loc != NULL) {
		if(toInsert.compareTo(loc->item) == ItemType::GREATER) {
			break;
		} else if (toInsert.compareTo(loc->item) == ItemType::EQUAL) {
			cout << "Sorry. You cannot insert the duplicate item." << endl;
			return;
		}
		prev = loc;
		loc = loc->next;
	}

	temp->item = toInsert;
	temp->next = loc;
	if (prev != NULL) {
		prev->next = temp;
	} else {
		head = temp;
	}
} // insert

/* ListNode that contains item should be deleted. */
void SortedLinkedList::deleteItem(ItemType item) {
	ListNode* loc = head;
	ListNode* prevloc;
	ListNode* deleter;

	// Deleting from an empty list
	if (head == NULL) {
		cout << "You cannot delete from an empty list." << endl;
	} else if (length() == 1) {
		if (item.compareTo(head->item) == ItemType::EQUAL) {
			deleter = head;
			head = NULL;
			currentPos = head;
		} else {
			cout << "Item not found." << endl;
		}
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
	} else if (loc == head) {
		deleter = head;
		head = head->next;
		currentPos = head;
	} else {
		deleter = loc->next;
		prevloc->next = deleter;
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

void SortedLinkedList::printList() {
	ListNode* printer = head;
	ItemType toPrint;
	while (printer != NULL) {
		toPrint = printer->item;
		cout << toPrint.getValue() << " ";
		printer = printer->next;
	}
	cout << '\n';
}

/* Function for merging two sorted linked lists.*/
SortedLinkedList SortedLinkedList::merge(SortedLinkedList toMerge) {
	SortedLinkedList sorted;
	int length = toMerge.length();
	for (int i = 0; i < length; i++) {
		if(toMerge.searchItem(toMerge.getNode(i)->item) != -1) {
			cout << "Sorry. You cannot insert the duplicate item." << endl;
			continue;
		}
	}
	for (int i = 0; i < toMerge.length(); i++) {
		sorted.insertItem(toMerge.getNode(i)->item);
	}
	return sorted;
} // merge

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







