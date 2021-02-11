/**
* Title : Heaps and AVL Trees
* Author : Alkim Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : HuffmanQueue source file
*/

#include <iostream>
#include "HuffmanHeap.h"
#include "HuffmanQueue.h"

HuffmanQueue::HuffmanQueue()
             :minQueue( HuffmanHeap())
{

}

HuffmanQueue::~HuffmanQueue()
{

}

void HuffmanQueue::insert( MinHeapNode* newNode)
{
    minQueue.insert( newNode);
}

MinHeapNode *HuffmanQueue::extract()
{
    return minQueue.extractMin();
}

int HuffmanQueue::size()
{
    return minQueue.size();
}
