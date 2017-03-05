#Personnel Management System

This directory contains:

code that implements a binary search tree of strings,
a btree program that uses it
The btree program executes a simple UI that allows the user to 
select 1 of 6 option
1: insert employee 
2: delete employee 
3: list employees 
4: read file
5: write to file
6: quit


This demo contains the following files: tree.h: header file of tnode structure & "public" interface functions 
tree.c: implementation of Personnel Management System btree.c: a demonstration program that uses the UI to demonstrate 
the binary search tree implementation of the system.

To compile:

$ make

To run program:

$ make demo

To delete binaries:

$ make clean

#RESOURCES:

for printing tree in tree structure: https://www.daniweb.com/programming/software-development/threads/146112/printing-a-binary-tree
reference for deletion: http://www.thelearningpoint.net/computer-science/trees/binary-search-trees---c-program-source-code-and-documentation
printing twice bug on read file: http://stackoverflow.com/questions/26668892/data-being-printed-out-twice-when-using-fread
reviewing structure of bst: https://www.tutorialspoint.com/data_structures_algorithms/binary_search_tree.htm
Kerningham, Brian W & Ritchie, Dennis M. "The C Programming Language, Second edition," Prentice Hall, ISBN: 0-13-115817-1.
sorting: http://www.sanfoundry.com/c-program-sort-names-alphabetical-order/