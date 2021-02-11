/**
* Title : Heaps and AVL Trees
* Author : Alkim Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : MaxHeap header file
*/

#ifndef _MaxHeap
#define _MaxHeap

class MaxHeap {
public:
    MaxHeap();
    ~MaxHeap();
    void insert( int value);   // inserts integer into heap
    int peek();                // returns the value of the max element
    int extractMax();          // retrieves and removes the max element
    int size();                // returns the number of elements in the heap

protected:
    void heapRebuild( int root);

private:
    int *items;
    int heapSize;
}; // end MaxHeap
#endif
