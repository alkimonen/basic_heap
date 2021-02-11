/**
* Title : Heaps and AVL Trees
* Author : Alkým Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : HuffmanCode source file
*/

#include <iostream>
using namespace std;
#include "HuffmanHeap.h"
#include "HuffmanQueue.h"
#include "HuffmanCode.h"

HuffmanCode::HuffmanCode( HuffmanQueue &newQueue)
{
    minPriQueue = newQueue;
}

MinHeapNode *HuffmanCode::huffman()
{
    for ( int i = 1; i < ( minPriQueue.size() - 1 ); i++ )
    {
        MinHeapNode *z = new MinHeapNode;
        z->left = minPriQueue.extract();
        z->right = minPriQueue.extract();
        z->freq = z->left->freq + z->right->freq;
        z->character = '0';
        minPriQueue.insert( z);
    }
    return minPriQueue.extract();
}
