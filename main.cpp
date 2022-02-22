#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <iterator>
#include <string>
#include <cstring>
#include <ctype.h>
#include <vector>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

//Creates the list from an input file "input.txt"
SortedLinkedList createList() {
	ifstream sFile("input.txt");
	vector<int> vals;
	int num;
	ItemType item;
	SortedLinkedList created = SortedLinkedList();

	if (!sFile.is_open()) {
		cout << "File not found" << endl;
	}
	while (sFile >> num) {
		vals.push_back(num);
	}
	for(const auto &i: vals) {
		item.initialize(i);
		created.insertItem(item);
	}
	sFile.close();
	return created;
} // create

int main(int argc, char *argv[]) {

	// Check that program is started properly with input.txt
	if (argc != 2) {
		cout << "Usage ./main input.txt || ./main empty.txt" << endl;
		return 1;
	} else if (strcmp(argv[1], "input.txt") != 0) {
		if (strcmp(argv[1], "empty.txt") != 0) {
			cout << "Usage ./main input.txt || ./main empty.txt" << endl;
			return 1;
		}
	}

	// create the linked list
	SortedLinkedList list = SortedLinkedList();
	if (strcmp(argv[1], "input.txt") == 0) {
		list = createList();
	}

	char choice;
	int val;
	string input, temp;
	ItemType toInsert, toDel, toFind, next, mergeNode;

	cout << "Commands:" << endl;
	cout << "(i) - Insert value" << endl;
	cout << "(d) - Delete value" << endl;
	cout << "(s) - Search value" << endl;
	cout << "(n) - Print next iterator value" << endl;
	cout << "(r) - Reset iterator" << endl;
	cout << "(a) - Delete alternate nodes" << endl;
	cout << "(m) - Merge two lists" << endl;
	cout << "(t) - Intersection" << endl;
	cout << "(p) - Print list" << endl;
	cout << "(l) - Print length" << endl;
	cout << "(q) - Quit program" << endl;

	while(1) {
		cout << "Enter a command: ";
		cin >> (choice);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch(choice) {
		case 'i':
			if (list.length() != 0) {
				list.printList();
			}
			cout << "Enter number: ";
			while(true) {
				cin >> val;
				if(!cin) {
					cout << "Please enter an integer" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				} else break;
			}
			toInsert.initialize(val);
			list.insertItem(toInsert);
			break;
		case 'd':
			cout << "Enter value to delete: " << endl;
			cin >> val;
			toDel.initialize(val);
			list.deleteItem(toDel);
			break;
		case 's':
			cout << "Enter a value to search: ";
			cin >> val;
			toFind.initialize(val);
			if (list.searchItem(toFind) > -1) {
				cout << "Index " << list.searchItem(toFind) << endl;
			} else {
				cout << "Item not found." << endl;
			}
			break;
		case 'n':
			next = list.getNextItem();
			cout << next.getValue() << endl;
			break;
		case 'r':
			list.resetList();
			cout << "Iterator Reset" << endl;
			break;
		case 'a':
			cout << "List before alternate delete: ";
			list.printList();
			list.deleteAlternatingNodes();
			cout << "List after alternate delete: ";
			list.printList();
			break;
		case 'm': {
			SortedLinkedList toMerge, merged;
			int mergeSize;
			int num;
			cout << "Length of list to merge: " << endl;
			cin >> mergeSize;
			cout << "List elements separated by spaces in order: " << endl;
			while (mergeSize-- > 0) {
				cin >> num;
				mergeNode.initialize(num);
				toMerge.insertItem(mergeNode);
			}
			cout << "List 1: ";
			list.printList();
			cout << "List 2: ";
			toMerge.printList();
			merged = list.merge(list, toMerge);
			merged.printList();
			list = merged;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		case 't': {
			SortedLinkedList intersection, intersector;
			ItemType intersectionNode;
			cout << "Length of list to find intersection: ";
			int comListSize;
			int num;
			cin >> comListSize;
			cout << "List elements separated by spaces in order: ";
			while (comListSize-- > 0) {
				cin>>num;
				intersectionNode.initialize(num);
				intersector.insertItem(intersectionNode);
			}
			cout << "List 1: ";
			list.printList();
			cout << "List 2: ";
			intersector.printList();
			cout << "Intersection:";
			list.findCommon(intersector);
			cout << endl;
			//list.printList();
			break;
		}
		case 'p':
			list.printList();
			break;
		case 'l':
			cout << "List length is " << list.length() << endl;
			break;
		case 'q':
			cout << "Quitting program..." << endl;
			return 0;
		default:
			cout << "Invalid command, try again!" << endl;
			break;
		}
	}
	return 0;
} //main
