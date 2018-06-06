#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <stdio.h>
#include <iostream>
#include "HashTable.h"
using namespace std;

void AddValue(HashNode **array, int group_number, int value);
void ExtractElement(HashNode **array, int group_number);
void PrintGroup(HashNode **array, int group_number);
void MergeGroups(HashNode **array, int group_number1, int group_number2);
void IncreaseValue(HashNode **array, int group_number, int value_old, int value_new);
#endif