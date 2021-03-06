﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "HashTable.h"
#include "Heap.h"
#include "Operations.h"
int main() {
	int operations_quantity, i, group_number1, group_number2, value_new, value_old;
	char action;
	HashNode **HashTable = new HashNode*[MAX_GROUP_QUANTITY];
	memset(&*HashTable, NULL, sizeof HashTable * MAX_GROUP_QUANTITY);
	scanf("%i", &operations_quantity);
	for (i = 0; i < operations_quantity; i++) {
		scanf(" %c", &action);
		switch (action)
		{
		case 'a':
			scanf("%i", &group_number1);
			scanf("%i", &value_new);
			AddValue(HashTable, group_number1, value_new);
			break;
		case 'e':
			scanf("%i", &group_number1);
			ExtractElement(HashTable, group_number1);
			break;
		case 'p':
			scanf("%i", &group_number1);
			PrintGroup(HashTable, group_number1);
			break;
		case 'm':
			scanf("%i", &group_number1);
			scanf("%i", &group_number2);
			MergeGroups(HashTable, group_number1, group_number2);
			break;
		case 'i':
			scanf("%i", &group_number1);
			scanf("%i", &value_old);
			scanf("%i", &value_new);
			IncreaseValue(HashTable, group_number1, value_old, value_new);
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < MAX_GROUP_QUANTITY; i++) {
		FreeList(HashTable[i]);
	}
	return 0;
}

