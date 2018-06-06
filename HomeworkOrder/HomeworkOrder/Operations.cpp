#include "Operations.h"
#include "Heap.h"

void AddValue(HashNode **array, int group_number, int value) {
	if (array[Hash(group_number)] == nullptr) {
		array[Hash(group_number)] = CreateHashNode(group_number);
		Insert(array[Hash(group_number)], value);
		(array[Hash(group_number)]->elements_quantity)++;
		//BubbleUp(array[Hash(group_number)]->root, array[Hash(group_number)]->elements_quantity);
	}
	else {
		HashNode *temp = array[Hash(group_number)];
		HashNode *prev_temp = new HashNode;
		while (temp != nullptr) {
			if (temp->group == group_number) {
				Insert(temp, value);
				(temp->elements_quantity)++;
				BubbleUp(temp->root, temp->elements_quantity - 1);
				return;
			}
			prev_temp = temp;
			temp = temp->next;
		}
		temp = prev_temp;
		AddHashNode(prev_temp, group_number);
		temp = temp->next;
		Insert(temp, value);
		(temp->elements_quantity)++;
		BubbleUp(temp->root, temp->elements_quantity - 1);
		delete prev_temp;
	}
}

void ExtractElement(HashNode **array, int group_number) {
	HashNode *temp = array[Hash(group_number)];
	if (temp == nullptr) {
		printf("na\n");
		return;
	}
	while (temp != nullptr) {
		if (temp->group == group_number) {
			if (temp->root[0] == NULL) {
				printf("na\n");
				return;
			}
			printf("%i\n", temp->root[0]);
			temp->root[0] = NULL;
			Swap(temp->root[0], temp->root[temp->elements_quantity - 1]);
			(temp->elements_quantity)--;
			Heapify(temp->root, temp->elements_quantity, 0);
			return;
		}
		temp = temp->next;
	}
}

void PrintGroup(HashNode **array, int group_number) {
	HashNode *temp = array[Hash(group_number)];
	if (temp == nullptr) {
		return;
	}
	while (temp != nullptr) {
		if (temp->group == group_number) {
			if (temp->root[0] == NULL) {
				return;
			}
			int temp_heap_size = temp->elements_quantity;
			int* temp_heap = new int[temp_heap_size];
			for (int i = 0; i < temp_heap_size; i++) {
				temp_heap[i] = temp->root[i];
			}

			for (int i = 0; i < temp->elements_quantity; i++) {
				printf("%i\n", temp_heap[0]);
				temp_heap[0] = NULL;
				Swap(temp_heap[0], temp_heap[temp_heap_size - 1]);
				(temp_heap_size)--;
				Heapify(temp_heap, temp_heap_size, 0);
			}
			delete[] temp_heap;
			printf("\n");
			return;
		}
		temp = temp->next;
	}
}

void IncreaseValue(HashNode **array, int group_number, int value_old, int value_new) {
	HashNode *temp = array[Hash(group_number)];
	if (temp == nullptr) {
		printf("na\n");
		return;
	}
	while (temp != nullptr) {
		if (temp->group == group_number) {
			for (int i = 0; i < temp->elements_quantity; i++) {
				if (temp->root[i] == value_old) {
					temp->root[i] = value_new;
					BubbleUp(temp->root, i);
					return;
				}
			}
		}
		temp = temp->next;
	}
	printf("na\n");
	return;
}

void MergeGroups(HashNode **array, int group_number1, int group_number2) {
	HashNode *temp1 = array[Hash(group_number1)];
	HashNode *temp2 = array[Hash(group_number2)];
	if (temp2 == nullptr) {
		return;
	}
	else if (temp2->root[0] == NULL) {
		return;
	}
	else if (temp1 == nullptr) {
		temp1 = CreateHashNode(group_number1);
		temp1->root = temp2->root;
		temp2->root = nullptr;
	}
	else if (temp1->root[0] == NULL) {
		temp1->root = temp2->root;
		temp2->root = nullptr;
	}
	else {
		int *new_heap = new int[temp1->elements_quantity + temp2->elements_quantity];
		for (int i = 0; i < temp1->elements_quantity; i++) {
			new_heap[i] = temp1->root[i];
		}
		for (int i = 0; i < temp2->elements_quantity; i++) {
			new_heap[temp1->elements_quantity + i] = temp2->root[i];
			BubbleUp(new_heap, temp1->elements_quantity + i);
		}
		temp1->root = new_heap;
		temp1->elements_quantity = temp1->elements_quantity + temp2->elements_quantity;
		temp2->elements_quantity = 0;
		temp1->heap_size = temp1->elements_quantity;
		temp2->heap_size = temp2->elements_quantity;
		new_heap = nullptr;

	}
}