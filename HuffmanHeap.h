/**
* Title : Heaps and AVL Trees
* Author : Alkým Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : HuffmanHeap header file
*/

#ifndef _HuffmanHeap
#define _HuffmanHeap

struct MinHeapNode
{
    char character ;                    // An input character
    int freq ;                          // Frequency of the character
    MinHeapNode *left , * right ;       // Left and right child
};

class HuffmanHeap {
public:
    HuffmanHeap();
    ~HuffmanHeap();
    void insert( MinHeapNode* newNode);                // inserts node with given frequency into heap
    MinHeapNode *peek();                    // returns the min element
    MinHeapNode *extractMin();              // retrieves and removes the min element
    int size();                             // returns the number of elements in the heap

protected:
    void heapRebuild( int root);

private:
    MinHeapNode **items;
    int heapSize;
}; // end HuffmanHeap
#endif
