/**
* Title : Heaps and AVL Trees
* Author : Alkým Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : HuffmanQueue header file
*/

#ifndef _HuffmanQueue
#define _HuffmanQueue
#include "HuffmanHeap.h"

class HuffmanQueue {
public:
    HuffmanQueue();
    ~HuffmanQueue();
    void insert( MinHeapNode* newNode);
    MinHeapNode *extract();
    int size();

private:
    HuffmanHeap minQueue;
}; // end HuffmanHeap
#endif
