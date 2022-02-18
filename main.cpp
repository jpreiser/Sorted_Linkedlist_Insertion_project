#include <iostream>
#include <cstdlib>
#include <fstream>
#include "ItemType.h"
#include "ListNode.h"
#include "SortedLinkedList.h"

using namespace std;

int main() {

	char choice = '';
	while(1) {
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
		cin >> choice;
		switch(choice) {
		case 'i':
			cout << "i" << endl;
		case 'd':
			cout << "d" << endl;
		case 's':
			cout << "s" << endl;
		case 'n':
			cout << "n" << endl;
		case 'r':
			cout << "r" << endl;
		case 'a':
			cout << "a" << endl;
		case 'm':
			cout << "m" << endl;
		case 't':
			cout << "t" << endl;
		case 'p':
			cout << "p" << endl;
		case 'l':
			cout << "l" << endl;
		case 'q':
			break;
		default:
			cout << "Invalid command, try again!" << endl;
		}
	}

	return 0;
} //main
