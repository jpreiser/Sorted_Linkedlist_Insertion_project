#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <iterator>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

int main() {

	char choice;
	while(choice != 'q') {
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
		cin.get(choice);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch(choice) {
		case 'i':
			cout << "i" << endl;
			break;
		case 'd':
			cout << "d" << endl;
			break;
		case 's':
			cout << "s" << endl;
			break;
		case 'n':
			cout << "n" << endl;
			break;
		case 'r':
			cout << "r" << endl;
			break;
		case 'a':
			cout << "a" << endl;
			break;
		case 'm':
			cout << "m" << endl;
			break;
		case 't':
			cout << "t" << endl;
			break;
		case 'p':
			cout << "p" << endl;
			break;
		case 'l':
			cout << "l" << endl;
			break;
		case 'q':
			return 0;
		default:
			cout << "Invalid command, try again!" << endl;
			break;
		}
	}
	return 0;
} //main
