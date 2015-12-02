#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct element Element;
typedef struct node Node;
typedef struct singlyLinkedList SinglyLinkedList;

struct element
{
	int key;
};

struct node
{
	Element item;
	Node *link;
};

struct singlyLinkedList
{
	Node *head;
};

static SinglyLinkedList *CreateSinglyLinkedList();
static void DestroySinglyLinkedList(SinglyLinkedList *list);
static void AddFirstSinglyLinkedList(const SinglyLinkedList *list, const Element item);
static void AddLastSinglyLinkedList(const SinglyLinkedList *list, const Element item);
static void InsertAfterSinglyLinkedList(const SinglyLinkedList *list, const int key, const Element item);
static void InsertSinglyLinkedList(Node *node, const Element item);
static void DeleteSinglyLinkedList(const SinglyLinkedList *list, const int key);
static void PrintSinglyLinkedList(const SinglyLinkedList *list);


int main(int argc, char *argv[])
{
	SinglyLinkedList *list = CreateSinglyLinkedList();
	Element item;

	item.key = 3;
	AddFirstSinglyLinkedList(list, item);
	PrintSinglyLinkedList(list);

	item.key = 2;
	AddFirstSinglyLinkedList(list, item);
	PrintSinglyLinkedList(list);

	item.key = 1;
	AddFirstSinglyLinkedList(list, item);
	PrintSinglyLinkedList(list);
	
	item.key = 5;
	AddLastSinglyLinkedList(list, item);
	PrintSinglyLinkedList(list);

	item.key = 4;
	InsertAfterSinglyLinkedList(list, 3, item);
	PrintSinglyLinkedList(list);

	item.key = 6;
	InsertSinglyLinkedList(list->head, item);
	PrintSinglyLinkedList(list);

	DestroySinglyLinkedList(list);
	PrintSinglyLinkedList(list);

	return 0;
}

static SinglyLinkedList *CreateSinglyLinkedList()
{
	SinglyLinkedList *s = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
	memset(s, NULL, sizeof(SinglyLinkedList));
	return s;
}

static void AddFirstSinglyLinkedList(SinglyLinkedList *list, const Element item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	if (!list->head){
		list->head = newNode;
		return;
	}
	newNode->link = list->head;
	list->head = newNode;
}

static void AddLastSinglyLinkedList(SinglyLinkedList *list, const Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *begin = list->head;

	memset(newNode, 0x00, sizeof(Node));
	newNode->item = item;

	if (!list->head)
		list->head = newNode;

	while (begin)
	{
		if (!begin->link){
			begin->link = newNode;
			break;
		}
		begin = begin->link;
	}
}

static void InsertAfterSinglyLinkedList(const SinglyLinkedList *list, const int key, const Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *begin = list->head;

	begin = list->head;
	memset(newNode, 0x00, sizeof(Node));
	newNode->item = item;

	while (begin)
	{
		if (begin->item.key == key)
		{
			newNode->link = begin->link;
			begin->link = newNode;
			break;
		}
		begin = begin->link;
	}
}

static void InsertSinglyLinkedList(Node *node, const Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0x00, sizeof(Node));
	newNode->item = item;

	newNode->link = node->link;
	node->link = newNode;
}

//첫번째 노드를 지우는경우 문제
static void DeleteSinglyLinkedList(const SinglyLinkedList *list, const int key)
{
	Node *deleteNode;
	Node *begin = list->head;

	while (begin)
	{
		if (begin == list->head && begin->item.key == key)
		{
			deleteNode = begin;
			begin = begin->link;
			list->head = begin;
			free(deleteNode);
			break;
		} else if ()
		begin = begin->link;
	}
}

static void DestroySinglyLinkedList(SinglyLinkedList *list)
{
	Node *deleteNode;
	Node *begin = list->head;
	while (begin)
	{
		deleteNode = begin;
		begin = begin->link;
		free(deleteNode);
	}
	free(list);
	list->head = NULL;
}

static void PrintSinglyLinkedList(const SinglyLinkedList *list)
{
	Node *begin = list->head;
	begin = list->head;

	while (begin)
	{
		printf("%d ", begin->item.key);
		begin = begin->link;
	}
	printf("\n");
}