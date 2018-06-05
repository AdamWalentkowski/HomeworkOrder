#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <iostream>
#include "HashTable.h"

void Insert(HashNode *node, int value);
void ResizeHeap(HashNode *node);
void RemoveRoot(int *heap, int elements_quantity);
#endif