#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX_GROUP_QUANTITY 1000
#define HASH_FACTOR 10301

struct HashNode {
	//POINTER TO GROUP
	int group;
	HashNode *next;
};

HashNode *CreateHashNode(int group_number, int priority) {
	HashNode *node = new HashNode;
	//POINTER TO GROUP
	node->group = group_number;
	node->next = NULL;
	//CreateGroup
	return node;
}

void AddHashNode(HashNode *head) {
	HashNode *node = CreateHashNode();
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

int Hash(int group_number) {
	return (group_number * HASH_FACTOR) % MAX_GROUP_QUANTITY;
}

void AddElement(HashNode **array, int group_number, int value) {
	if (array[Hash(group_number)] == nullptr) {
		array[Hash(group_number)] = CreateHashNode(group_number, value);
	}
	else {
		AddHashNode(transaction, amount, HashTable[Hash(transaction)]);
	}
}

void ExtractElement() {

}

void PrintGroup() {

}

void MergeGroups() {

}

void IncreaseValue() {

}

int main() {
	int operations_quantity, i, group_number1, group_number2, value_new, value_old;
	char action;
	HashNode **HashTable = new HashNode*[MAX_GROUP_QUANTITY];
	memset(&HashTable, NULL, sizeof HashTable);
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
			ExtractElement();
			break;
		case 'p':
			cin >> group_number1;
			PrintGroup();
			break;
		case 'm':
			cin >> group_number1;
			cin >> group_number2;
			MergeGroups();
			break;
		case 'i':
			cin >> group_number1;
			cin >> value_old;
			cin >> value_new;
			IncreaseValue();
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < HASH_FACTOR; i++) {
		FreeList(HashTable[i]);
	}
	return 0;
}

