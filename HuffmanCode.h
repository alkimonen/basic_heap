/**
* Title : Heaps and AVL Trees
* Author : Alkým Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : HuffmanCode header file
*/

#ifndef _HuffmanCode
#define _HuffmanCode
#include "HuffmanHeap.h"
#include "HuffmanQueue.h"

class HuffmanCode {
public :
    HuffmanCode( HuffmanQueue &newQueue);
    MinHeapNode *huffman();

private:
    HuffmanQueue minPriQueue;

}; // end HuffmanCode
#endif
