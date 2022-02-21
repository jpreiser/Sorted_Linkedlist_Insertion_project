#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <iterator>
#include <string>
#include <cstring>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

//Creates the list from an input file "input.txt"
void createList(SortedLinkedList list) {
	ifstream sFile("input.txt");
	int value;

	if (sFile.is_open()) {
		while (sFile >> value) {
			ItemType item;
			item.initialize(value);
			list.insertItem( item);
		}
	}
} // create

int main(int argc, char *argv[]) {

	// Check that program is started properly with input.txt
	if (argc != 2) {
		cout << "Usage ./main input.txt || ./main empty.txt" << endl;
		return 1;
	} else if (strcmp(argv[1], "input.txt") != 0) {
		cout << "Usage ./main input.txt" << endl;
		return 1;
	}

	// create the linked list
	SortedLinkedList list = SortedLinkedList();
	createList(list);

	char choice;
	int val;
	ItemType toInsert, toDel, toFind;

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
			cout << "Enter a value to search: " << endl;
			cin >> val;
			toFind.initialize(val);
			cout << "Index " << list.searchItem(toFind) << endl;
			break;
		case 'n':
			cout << "n" << endl;
			break;
		case 'r':
			list.resetList();
			cout << "Iterator Reset" << endl;
			break;
		case 'a':
			cout << "a" << endl;
			break;
		case 'm':
			int mergeSize;
			cout << "Length of list to merge: " << endl;
			cin >> mergeSize;
			cout << "List elements separated by spaces in order: " << endl;
			// while loop to take in elements to create new list to merge with current list.
			cout << "List 1: ";
			list.printList();

			break;
		case 't':
			cout << "Length of list to find intersection: " << endl;
			int comListSize;
			cin >> comListSize;
			cout << "List elements separated by spaces in order: ";

			cout << "List 1: ";
			list.printList();
			cout << "List 2: ";

			cout << "Intersection: ";
			//list.findCommon(list2);
			list.printList();
			break;
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
