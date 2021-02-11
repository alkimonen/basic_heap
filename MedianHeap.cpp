/**
* Title : Heaps and AVL Trees
* Author : Alkým Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : MedianHead source file
*/

#include "iostream"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"

MedianHeap::MedianHeap()
            :rootFull(false), leftChild( MaxHeap()), rightChild( MinHeap())
{

}

void MedianHeap::insert( int value)
{
    if ( !rootFull )
    {
        rootItem = value;
        rootFull = true;
    }
    else
    {
        // if size is even left child has 1 more item than right child
        if ( leftChild.size() > rightChild.size() )
        {
            // if root is less than value insert new value to right child
            if ( rootItem < value )
                rightChild.insert( value);
            else
            {
                // move root to right child
                rightChild.insert( rootItem);
                // if max of left child is bigger than value move max to root
                // then insert new value to left child
                if ( leftChild.peek() > value )
                {
                    rootItem = leftChild.extractMax();
                    leftChild.insert( value);
                }
                // if max is less of equal to new value make root the new value
                else
                    rootItem = value;
            }
        }
        // if size is odd both children has same size
        else if ( rightChild.size() == leftChild.size() )
        {
            // if root is less than value
            if ( rootItem < value )
            {
                // insert root to left child
                leftChild.insert( rootItem);
                // if min of right child is less than value move min to root
                // then insert new value to right child
                if ( ( rightChild.size() > 0 ) && ( rightChild.peek() < value ) )
                {
                    rootItem = rightChild.extractMin();
                    rightChild.insert( value);
                }
                // if min is more or equal to new value mate root the new value
                else
                    rootItem = value;
            }
            else
                leftChild.insert( value);
        }

    }
}

int MedianHeap::findMedian()
{
    if ( rootFull )
        return rootItem;
    return 0;
}
