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
	cin >> operations_quantity;
	for (i = 0; i < operations_quantity; i++) {
		cin >> action;
		switch (action)
		{
		case 'a':
			cin >> group_number1;
			cin >> value_new;
			AddElement(HashTable, group_number1, value_new);
			break;
		case 'e':
			cin >> group_number1;
			ExtractElement(HashTable, group_number1);
			break;
		case 'p':
			cin >> group_number1;
			//PrintGroup();
			break;
		case 'm':
			cin >> group_number1;
			cin >> group_number2;
			//MergeGroups();
			break;
		case 'i':
			cin >> group_number1;
			cin >> value_old;
			cin >> value_new;
			//IncreaseValue();
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < MAX_GROUP_QUANTITY; i++) {
		FreeList(HashTable[i]);
	}
	system("pause");
	return 0;
}

