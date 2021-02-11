/**
* Title : Heaps and AVL Trees
* Author : Alkim Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : MedianHeap header file
*/

#include "MaxHeap.h"
#include "MinHeap.h"

#ifndef _MedianHeap
#define _MedianHeap

class MedianHeap {
public:
    MedianHeap();
    void insert( int value);           // inserts an element into MedianHeap
    int findMedian();                  // returns the value of the median

private:
    int rootItem;
    bool rootFull;              // heap is empty or not
    MaxHeap leftChild;          // max of left child will be at top
    MinHeap rightChild;         // min of right child will be at bottom
}; // end MedianHeap
#endif
