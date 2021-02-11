all: main.cpp MaxHeap.cpp MaxHeap.h MinHeap.cpp MinHeap.h MedianHeap.cpp MedianHeap.h HuffmanHeap.cpp HuffmanHeap.h HuffmanQueue.cpp HuffmanQueue.h HuffmanCode.cpp HuffmanCode.h
	g++ -o heap main.cpp MaxHeap.cpp MaxHeap.h MinHeap.cpp MinHeap.h MedianHeap.cpp MedianHeap.h HuffmanHeap.cpp HuffmanHeap.h HuffmanQueue.cpp HuffmanQueue.h HuffmanCode.cpp HuffmanCode.h
run:
	./heap
clean:
	rm -fr heap main.o MaxHeap.o MinHeap.o MedianHeap.o HuffmanHeap.o HuffmanQueue.o HuffmanCode.o *~