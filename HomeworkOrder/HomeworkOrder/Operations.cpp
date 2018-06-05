#include "Operations.h"
#include "Heap.h"

void AddElement(HashNode **array, int group_number, int value) {
	if (array[Hash(group_number)] == nullptr) {
		array[Hash(group_number)] = CreateHashNode(group_number);
		Insert(array[Hash(group_number)], value);
	}
	else {
		HashNode *temp = array[Hash(group_number)];
		while (temp != NULL) {
			if (temp->group == group_number) {
				Insert(temp, value);
				return;
			}
			temp = temp->next;
		}
		AddHashNode(array[Hash(group_number)], group_number);
	}
}

void ExtractElement(HashNode **array, int group_number) {
	if (array[Hash(group_number)] == nullptr) {
		cout << "na\n";
	}
	else {
		cout << array[Hash(group_number)]->root[0] << endl;
		RemoveRoot(array[Hash(group_number)]->root, array[Hash(group_number)]->elements_quantity);
	}
}