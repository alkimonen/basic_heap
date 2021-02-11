/**
* Title : Heaps and AVL Trees
* Author : Alkim Önen
* ID: 21703549
* Section : 01
* Assignment : 3
* Description : Main program
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "HuffmanCode.h"
#include "HuffmanHeap.h"
#include "HuffmanQueue.h"


void traverseAndPrint( MinHeapNode *&treeNode, string &pre, ofstream &outputFile)
{
    if ( treeNode != NULL )
    {
        string newPre;
        newPre = pre;
        newPre.push_back( '0');
        traverseAndPrint( treeNode->left, pre, outputFile);
        if ( treeNode->character != '0' )
        {
            outputFile << treeNode->character << " " << pre << "\n";
        }
        newPre = pre;
        newPre.push_back( '1');
        traverseAndPrint( treeNode->right, pre, outputFile);
    }
}

int main(){
    HuffmanQueue huffmanList;
    MinHeapNode *node;

    char inputFileName[256], outputFileName[256];
    char *data;
    string output;
    char currentChar;
    int frequency = 0;
    int digit;
    int inputLength = 0;

    cout << "Please enter input file name: ";
    cin >> inputFileName;

    cout << "Please enter output file name: ";
    cin >> outputFileName;

    ifstream inputFile( inputFileName);
    if ( inputFile.is_open() )
    {
        inputLength = inputFile.gcount();
        data = new char[inputLength];
        inputFile.read( data, inputLength);

        for ( int i = 0; i < inputLength; i++)
        {
            currentChar = data[i];
            if ( ( currentChar > 47 ) || ( currentChar < 58 ) )
            {
                digit = (int) currentChar - 48;
                if ( frequency > 0 )
                {
                    frequency *= 10;
                    frequency += digit;
                }
                else
                    frequency = digit;

                if ( ( ( i + 1 < inputLength) && ( ( data[i+1] < 47) || ( data[i+1] > 58 ) ) ) || ( i + 1 == inputLength ) )
                {
                    node->freq = frequency;
                    huffmanList.insert( node);
                }
            }
            else
            {
                node = new MinHeapNode;
                node->character = currentChar;
                node->left = NULL;
                node->right = NULL;
                frequency = 0;
            }
        }
        delete data;
    }

    HuffmanCode huffman( huffmanList);
    node = huffman.huffman();

    string pre = "";
    ofstream outputFile( inputFileName);
    if ( outputFile.is_open() )
    {
        traverseAndPrint( node, pre, outputFile);
    }


    return 0;
}


/*
    MaxHeap heapMax;
    MinHeap heapMin;
    MedianHeap heapMed;

    cout << "Min heap" << endl;
    cout << "Size: " << heapMin.size() << endl;
    heapMin.insert(1);
    heapMin.insert(3);
    heapMin.insert(8);
    heapMin.insert(10);
    heapMin.insert(16);
    heapMin.insert(9);
    heapMin.insert(4);
    heapMin.insert(2);
    heapMin.insert(14);
    heapMin.insert(7);

    cout << "Size: " << heapMin.size() << endl;
    cout << "Extract min: " << heapMin.extractMin() << endl;
    cout << "Extract min: " << heapMin.extractMin() << endl;
    cout << "Peek: " << heapMin.peek() << endl;
    cout << "Size: " << heapMin.size() << endl;

    cout << "\nMax heap" << endl;
    cout << "Size: " << heapMax.size() << endl;
    heapMax.insert(8);
    heapMax.insert(14);
    heapMax.insert(9);
    heapMax.insert(2);
    heapMax.insert(7);
    heapMax.insert(10);
    heapMax.insert(3);
    heapMax.insert(16);
    heapMax.insert(4);
    heapMax.insert(1);

    cout << "Size: " << heapMax.size() << endl;
    cout << "Extract max: " << heapMax.extractMax() << endl;
    cout << "Extract max: " << heapMax.extractMax() << endl;
    cout << "Peek: " << heapMax.peek() << endl;
    cout << "Size: " << heapMax.size() << endl;

    cout << "\nMedian heap" << endl;

    heapMed.insert(1);
    heapMed.insert(2);
    heapMed.insert(3);
    heapMed.insert(4);
    heapMed.insert(5);
    heapMed.insert(6);
    heapMed.insert(7);
    cout << "Median: " << heapMed.findMedian() << endl;

    heapMed.insert(8);
    heapMed.insert(9);
    heapMed.insert(10);
    heapMed.insert(11);
    heapMed.insert(12);
    heapMed.insert(13);
    heapMed.insert(14);
    cout << "Median: " << heapMed.findMedian() << endl;

    heapMed.insert(15);
    cout << "Median: " << heapMed.findMedian() << endl;

    heapMed.insert(16);
    cout << "Median: " << heapMed.findMedian() << endl;*/
