Holberton Coding School

Interview Preparation - Algorithms

Project 2270

Heap Sort

Requirements
General

    Allowed editors: vi, vim, emacs
    All your files will be compiled on Ubuntu 14.04 LTS
    Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
    All your files should end with a new line
    A README.md file, at the root of the folder of the project, is mandatory
    Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
    You are not allowed to use global variables
    No more than 5 functions per file
    Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts, … is totally forbidden.
    In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
    The prototypes of all your functions should be included in your header file called sort.h
    Don’t forget to push your header file
    All your header files should be include guarded
    A list/array does not need to be sorted if its size is less than 2.

Write a function that sorts an array of integers in ascending order using the Heap sort algorithm

    Prototype: void heap_sort(int *array, size_t size);
    You must implement the sift-down heap sort algorithm
    You’re expected to print the array after each time you swap two elements (See example below)

Write in the file 0-O, the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:

    in the best case
    in the average case
    in the worst case
