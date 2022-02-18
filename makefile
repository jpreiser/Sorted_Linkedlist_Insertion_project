#pragma once

CC = g++
FLAGS = -Wall -pedantic-errors

main: main.o SortedLinkedList.o ItemType.o ListNode.o

main.o: main.cpp ListNode.h SortedLinkedList.h ItemType.h
	$(CC) $(FLAGS) -o main main.o ListNode.o SortedLinkedLIst.o ItemType.o

ItemType.o: ItemType.cpp ItemType.h
	$(CC) $(FLAGS) -c ItemType.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h ItemType.h ListNode.h
	$(CC) $(FLAGS) -c SortedLinkedList.cpp

ListNode.o: ListNode.h
	$(CC) $(FLAGS) -c ListNode.h

run: compile
	./main

clean:
	rm -f *.o *.gch main
