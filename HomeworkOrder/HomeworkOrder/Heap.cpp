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

void Heapify(int *heap, int elements_quantity, int parent_index) {
	int left_child_index, right_child_index, chosen_child_index;
	left_child_index = parent_index * 2 + 1;
	right_child_index = parent_index * 2 + 2;

	if (left_child_index >= elements_quantity) return;
	else if (right_child_index >= elements_quantity) {
		chosen_child_index = left_child_index;
	}
	else if (left_child_index >= right_child_index) {
		chosen_child_index = left_child_index;
	}
	else chosen_child_index = right_child_index;

	if (heap[chosen_child_index] > heap[parent_index]) {
		Swap(heap[chosen_child_index], heap[parent_index]);
		Heapify(heap, elements_quantity, chosen_child_index);
		return;
	}
}

void RemoveRoot(int *heap, int elements_quantity) {
	heap[0] = NULL;
	Heapify(heap, elements_quantity, 0);
}

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}