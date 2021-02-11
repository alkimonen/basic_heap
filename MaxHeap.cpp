/**
* Title : Heaps and AVL Trees
* Author : Alkim Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : MaxHeap source file
*/

#include "iostream"
#include "MaxHeap.h"

MaxHeap::MaxHeap()
        :heapSize(0)
{
    items = new int[10000000];
}

MaxHeap::~MaxHeap()
{
    delete items;
}

void MaxHeap::insert( int value)
{
    if ( heapSize < 10000000 )
    {
        items[heapSize] = value;

        int place = heapSize;
        int parent = ( place - 1 ) / 2;

        while ( ( place > 0 ) && ( items[place] > items[parent] ) )
        {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = ( place - 1 ) / 2;
        }
        heapSize++;
    }
}

int MaxHeap::peek()
{
    if ( heapSize > 0 )
        return items[0];
    return -1;
}

int MaxHeap::extractMax()
{
    if ( heapSize > 0 )
    {
        int rootItem = items[0];
        items[0] = items[heapSize-1];
        heapRebuild( 0);
        heapSize--;
        return rootItem;
    }
    return -1;
}

int MaxHeap::size()
{
    return heapSize;
}

void MaxHeap::heapRebuild( int root)
{
    int child = 2 * root + 1;
    if ( child < heapSize )
    {
        // root is not a leaf so it has a left child
        int rightChild = child + 1;

        if ( ( rightChild < heapSize ) && ( items[rightChild] > items[child] ) )
        {
            child = rightChild;
        }

        if ( items[root] < items[child] )
        {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild( child);
        }
    }
}
