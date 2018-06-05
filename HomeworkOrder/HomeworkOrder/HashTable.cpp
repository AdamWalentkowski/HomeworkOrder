#include "HashTable.h"

int Hash(int group_number) {
	return (group_number * HASH_FACTOR) % MAX_GROUP_QUANTITY;
}

HashNode *CreateHashNode(int group_number) {
	HashNode *node = new HashNode;
	int *heap = new int[1];
	heap[0] = NULL;
	node->group = group_number;
	node->heap_size = 1;
	node->elements_quantity = 0;
	node->root = heap;
	node->next = nullptr;
	return node;
}

void AddHashNode(HashNode *head, int group_number) {
	HashNode *node = CreateHashNode(group_number);
	HashNode *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = node;
	node->next = NULL;
}

void FreeList(HashNode *head) {
	HashNode *dest;
	while (head != NULL) {
		dest = head->next;
		delete head;
		head = dest;
	}
}