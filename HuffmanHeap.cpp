/**
* Title : Heaps and AVL Trees
* Author : Alkým Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : HuffmanHeap source file
*/

#include "iostream"
#include "HuffmanHeap.h"

HuffmanHeap::HuffmanHeap()
            :heapSize(0)
{
    *items = new MinHeapNode[10000000];
}

HuffmanHeap::~HuffmanHeap()
{
    MinHeapNode *current = new MinHeapNode;
    for ( int i = heapSize - 1; i >= 0; i++ )
    {
        current = items[i];
        current->left = NULL;
        current->right = NULL;
        delete current;
    }
    delete items;
}

void HuffmanHeap::insert( MinHeapNode* newNode)
{
    if ( heapSize < 10000000 )
    {
        items[heapSize] = newNode;

        int place = heapSize;
        int parent = ( place - 1 ) / 2;

        while ( ( place > 0 ) && ( items[place]->freq < items[parent]->freq ) )
        {
            MinHeapNode *temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = ( place - 1 ) / 2;
        }
        heapSize++;
    }
}

MinHeapNode *HuffmanHeap::peek()
{
    if ( heapSize > 0 )
        return items[0];
    return NULL;
}

MinHeapNode *HuffmanHeap::extractMin()
{
    if ( heapSize > 0 )
    {
        MinHeapNode *rootItem = items[0];
        items[0] = items[heapSize-1];
        heapRebuild( 0);
        heapSize--;
        return rootItem;
    }
    return NULL;
}

int HuffmanHeap::size()
{
    return heapSize;
}

void HuffmanHeap::heapRebuild( int root)
{
    int child = 2 * root + 1;
    if ( child < heapSize )
    {
        // root is not a leaf so it has a left child
        int rightChild = child + 1;

        if ( ( rightChild < heapSize ) && ( items[rightChild]->freq < items[child]->freq ) )
        {
            child = rightChild;
        }

        if ( items[root]->freq > items[child]->freq )
        {
            MinHeapNode *temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild( child);
        }
    }
}
