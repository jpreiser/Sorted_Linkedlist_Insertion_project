Jacob Reiser
810 687 011
Data Structures Assignment 2

To compile the code, type 'make' into the command line.

To run, type './make input.txt' into the command line.

To clean the directory, type 'make clean' into the command line.

The file currently runs using 'input.txt' from the working directory.
To change the initial list, alter the input.txt file in the directory.

Sorted list merge(sorted list1, sorted list2)
       if list1 is empty return list 2
       if list 2 is empty return list 1
       Compare the head of list1 to head of list2
               if head1 > head2, mergehead = head1
               else mergehead = head2
       Read through lists 1 and 2
            if list1.item > list2.item
               mergehead->next = list1.item
            else
                mergehead->next = list2.item
       Create a new linkedlist by reading in the chain of nodes using the insertitem function
       return the new linkedlist

I'm pretty sure my merge function is O(n) since ht input file is read all the way through once into
a linked chain, then the k number of ints to be added by the user, and then read into the merged linked list
before that merged linked list is returned. I think that would be O(2n) which = O(n).

void intersection(list)
     if the caller or list's head is null
        return "No common"
     While caller != null
           while list != null
                 if caller.item == list.item
                    print item value
                 list->next
           current->next
           reset list

I believe this implementation is O(n^2) since list needs to be read through for every element in the caller.
O(n) for the caller, O(n) for the list to merge = O(n^2)
