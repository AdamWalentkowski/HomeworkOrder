#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdio.h>
#include <iostream>
#define MAX_GROUP_QUANTITY 1000
#define HASH_FACTOR 10301

struct HashNode {
	int group;
	int heap_size;
	int elements_quantity;
	int *root;
	HashNode *next;
};

int Hash(int group_number);
HashNode *CreateHashNode(int group_number);
void AddHashNode(HashNode *head, int group_number);
void FreeList(HashNode *head);

#endif

