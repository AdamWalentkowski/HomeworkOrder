#include "Heap.h"

void Insert(HashNode *node, int value) {
	int old_heap_size = node->heap_size;
	(node->elements_quantity)++;
	for (int i = 0; i < old_heap_size; i++) {
		if (node->root[i] == NULL) {
			node->root[i] = value;
			return;
		}
	}
	ResizeHeap(node);
	node->root[old_heap_size] = value;
}

void ResizeHeap(HashNode *node) {
	int* new_heap = new int[node->heap_size * 2];
	memset(new_heap, NULL, sizeof(int) * node->heap_size * 2);
	for (int i = 0; i < node->heap_size; i++) {
		new_heap[i] = node->root[i];
	}
	node->heap_size = node->heap_size * 2;
	delete[] node->root;
	node->root = new_heap;
}

void RemoveRoot(int *heap, int elements_quantity) {
	heap[0] = NULL;
	//Heapify(heap, elements_quantity);
}