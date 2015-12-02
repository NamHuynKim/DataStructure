#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct element Element;
typedef struct node Node;
typedef struct doublyLinkedList DoublyLinkedList;

struct element
{
	int key;
};

struct node
{
	Element item;
	Node *llink;
	Node *rlink;
};

struct doublyLinkedList
{
	Node *head;
};

static DoublyLinkedList *CreateDoublyLinkedList();
static void AddFirstDoublyLinkedList(DoublyLinkedList *list, Element item);
static void AddLastDoublyLinkedList(DoublyLinkedList *list, Element item);
static void InsertDoublyLinkedList(Node *node, Element item);
static void DeleteDoublyLinkedList(DoublyLinkedList *list, const int key);
static void PrintDoublyLinkedList(DoublyLinkedList *list);
static void PrintReverseDoublyLinkedList(DoublyLinkedList *list);
static void DestroyDoublyLinkedList(DoublyLinkedList *list);

int main(int argc, char *argv[])
{
	DoublyLinkedList *list = CreateDoublyLinkedList();
	Element item;
	
	item.key = 2;
	AddFirstDoublyLinkedList(list, item);
	PrintDoublyLinkedList(list);

	item.key = 1;
	AddFirstDoublyLinkedList(list, item);
	PrintDoublyLinkedList(list);

	item.key = 3;
	AddLastDoublyLinkedList(list, item);
	PrintDoublyLinkedList(list);
	PrintReverseDoublyLinkedList(list);

	item.key = 4;
	InsertDoublyLinkedList(list->head, item);
	PrintDoublyLinkedList(list);

	DeleteDoublyLinkedList(list, 2);
	PrintDoublyLinkedList(list);

	DestroyDoublyLinkedList(list);
	PrintReverseDoublyLinkedList(list);
	return 0;
}


static DoublyLinkedList *CreateDoublyLinkedList()
{
	DoublyLinkedList *d = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	memset(d, NULL, sizeof(DoublyLinkedList));
	return d;
}

static void AddFirstDoublyLinkedList(DoublyLinkedList *list, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	if (!list->head)
	{
		list->head = newNode;
		return;
	}
	list->head->llink = newNode;
	newNode->rlink = list->head;
	list->head = newNode;
}

static void AddLastDoublyLinkedList(DoublyLinkedList *list, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *begin = list->head;
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	if (!list->head)
	{
		list->head = newNode;
		return;
	}

	while (begin)
	{
		if (begin->rlink == NULL)
		{
			newNode->llink = begin;
			begin->rlink = newNode;
			break;
		}
		begin = begin->rlink;
	}
}

static void InsertDoublyLinkedList(Node *node, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	newNode->llink = node;
	newNode->rlink = node->rlink;
	node->rlink->llink = newNode;
	node->rlink = newNode;
}
static void DeleteDoublyLinkedList(DoublyLinkedList *list, const int key)
{
	Node *deleteNode;
	Node *begin = list->head;

	while (begin)
	{
		if (begin->item.key == key)
		{
			deleteNode = begin;
			begin->rlink->llink = begin->llink;
			begin->llink->rlink = begin->rlink;
			return;
		}
		begin = begin->rlink;
	}
}
static void PrintDoublyLinkedList(DoublyLinkedList *list)
{
	Node *begin = list->head;

	while (begin)
	{
		printf("%d ", begin->item.key);
		begin = begin->rlink;
	}
	printf("\n");
}
static void PrintReverseDoublyLinkedList(DoublyLinkedList *list)
{
	Node *begin = list->head;
	while (begin)
	{
		if (begin->rlink == NULL)
			break;
		begin = begin->rlink;
	}
	

	while (begin)
	{
		printf("%d ", begin->item.key);
		begin = begin->llink;
	}
	printf("\n");
}

static void DestroyDoublyLinkedList(DoublyLinkedList *list)
{
	Node *begin = list->head;
	Node *deleteNode;
	while (begin)
	{
		if (!begin->rlink)
			break;
		deleteNode = begin;
		begin = begin->rlink;
		free(deleteNode);
	}
	free(list);
	list->head = NULL;
}