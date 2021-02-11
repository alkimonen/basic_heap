/**
* Title : Heaps and AVL Trees
* Author : Alkim Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : MinHeap header file
*/

#ifndef _MinHeap
#define _MinHeap

class MinHeap{
public:
    MinHeap();
    ~MinHeap();
    void insert( int value);       // inserts integer into heap
    int peek();                    // returns the value of the min element
    int extractMin();              // retrieves and removes the min element
    int size();                    // returns the number of elements in the heap

protected:
    void heapRebuild( int root);

private:
    int *items;
    int heapSize;
}; // end MinHeap
#endif
