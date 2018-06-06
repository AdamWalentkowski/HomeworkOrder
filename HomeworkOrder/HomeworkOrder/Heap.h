#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <iostream>
#include "HashTable.h"

void Insert(HashNode *node, int value);
void ResizeHeap(HashNode *node);
void Heapify(int *heap, int elements_quantity, int parent_index);
void BubbleUp(int *heap, int child_index);
void Swap(int &a, int &b);
#endif