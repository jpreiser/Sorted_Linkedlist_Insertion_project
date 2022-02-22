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
		delete(del);
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
	if (loc == NULL) {
		cout << "You cannot delete from an empty list." << endl;
		return;
	} else if (length() == 1) {
		if (item.compareTo(head->item) == ItemType::EQUAL) {
			deleter = head;
			delete deleter;
			head = NULL;
			currentPos = head;
			return;
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
		empty.initialize(-1);
		return empty;
	} else if (currentPos == NULL) {
		currentPos = head;
		search = currentPos;
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
SortedLinkedList SortedLinkedList::merge(SortedLinkedList list, SortedLinkedList toMerge) {
	SortedLinkedList sorted;
	ListNode* head1 = head;
	ListNode* head2 = toMerge.getHead();
	if(head1 == NULL) {
		return toMerge;
	}
	if (head2 == NULL) {
		return list;
	}

	ListNode* mergeHead = NULL;
	if(head1->item.getValue() <= head2->item.getValue()) {
		mergeHead = head1;
		sorted.insertItem(mergeHead->item);
		head1 = head1->next;
	} else {
		mergeHead = head2;
		sorted.insertItem(mergeHead->item);
		head2 = head2->next;
	}

	ListNode* mergeTail = mergeHead;
	ListNode* temp = NULL;
	while (head1 != NULL && head2 != NULL) {
		if (head1->item.getValue() < head2->item.getValue()) {
			temp = head1;
			head1 = head1->next;
		} else {
			temp = head2;
			head2 = head2->next;
		}
		mergeTail->next = temp;
		mergeTail = temp;
	}

	if(head1 != NULL) {
		mergeTail->next = head1;
	} else if (head2 != NULL) {
		mergeTail->next = head2;
	}
	while (mergeHead != NULL) {
		sorted.insertItem(mergeHead->item);
		mergeHead = mergeHead->next;
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
} // deleteAlt

/* Prints out the common elements between the called list and provided list. */
void SortedLinkedList::findCommon(SortedLinkedList comm) {
	SortedLinkedList common;
	ListNode* head1 = head;
	ListNode* head2 = comm.getHead();
	ListNode* current1 = head1;
	ListNode* current2 = head2;
	if (head1 == NULL || head2 == NULL) {
		cout << "No Elements in common." << endl;
	}
	while (current1 != NULL) {
		while (current2 != NULL) {
			if (current1->item.getValue() == current2->item.getValue()) {
				cout << " " << current1->item.getValue();
			}
			current2 = current2->next;
		}
		current1 = current1->next;
		current2 = head2;
	}
} // common

ListNode* SortedLinkedList::getHead() {
	return head;

} // getHead
