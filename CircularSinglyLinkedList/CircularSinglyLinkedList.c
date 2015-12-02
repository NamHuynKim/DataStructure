#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct element Element;
typedef struct node Node;
typedef struct CircularLinkedList CircularLinkedList;

struct element
{
	int key;
};

struct node
{
	Element item;
	Node *link;
};

struct CircularLinkedList
{
	Node *head;
};

static CircularLinkedList *CreateCircularLinkedList();
static void AddFirstCircularLinkedList(CircularLinkedList *list, Element item);
static void AddLastCircularLinkedList(CircularLinkedList *list, Element item);
static void InsertCircularLinkedList(const CircularLinkedList *list, const int key, Element item);
static void InsertAfterSinglyLinkedList(Node *node, Element item);
static void DeleteCircularLinkedList(CircularLinkedList *list, const int key);
static void PrintCircularLinkedList(CircularLinkedList *list);
static void DestroyCircularLinkedList(CircularLinkedList *list);
static Node* FindLastNode(CircularLinkedList *list);

int main(int argc, char *argv[])
{
	CircularLinkedList *list = CreateCircularLinkedList();
	Element item;

	item.key = 2;
	AddFirstCircularLinkedList(list, item);
	PrintCircularLinkedList(list);

	item.key = 1;
	AddFirstCircularLinkedList(list, item);
	PrintCircularLinkedList(list);

	item.key = 3;
	AddLastCircularLinkedList(list, item);
	PrintCircularLinkedList(list);

	item.key = 4;
	InsertAfterSinglyLinkedList(list->head, item);
	PrintCircularLinkedList(list);

	item.key = 5;
	InsertCircularLinkedList(list, 3, item);
	PrintCircularLinkedList(list);

	DeleteCircularLinkedList(list, 2);
	PrintCircularLinkedList(list);

	DestroyCircularLinkedList(list);
	

	return 0;
}


static CircularLinkedList *CreateCircularLinkedList()
{
	CircularLinkedList *d = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
	memset(d, NULL, sizeof(CircularLinkedList));
	return d;
}

static void AddFirstCircularLinkedList(CircularLinkedList *list, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *lastNode;
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	if (!list->head)
	{
		newNode->link = newNode;
		list->head = newNode;
		return;
	}

	lastNode = FindLastNode(list);
	lastNode->link = newNode;
	newNode->link = list->head;
	list->head = newNode;
}

static void AddLastCircularLinkedList(CircularLinkedList *list, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *lastNode;
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	if (!list->head)
	{
		newNode->link = newNode;
		list->head = newNode;
		return;
	}
	lastNode = FindLastNode(list);
	lastNode->link = newNode;
	newNode->link = list->head;
}

static void InsertAfterSinglyLinkedList(Node *node, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	newNode->link = node->link;
	node->link = newNode;
}

static void InsertCircularLinkedList(const CircularLinkedList *list, const int key, Element item)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	while (begin)
	{
		if (begin->item.key == key)
		{
			newNode->link = begin->link;
			begin->link = newNode;
		}
		else if (begin->link == list->head)
			break;
		begin = begin->link;
	}
}

static void DeleteCircularLinkedList(CircularLinkedList *list, const int key)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);
	Node *prev = NULL;

	while (begin)
	{
		if (begin->item.key == key)
		{
			if (begin == list->head)
			{
				list->head = begin->link;
				end->link = list->head;
				free(begin);
				break;
			}
			else
			{
				prev->link = begin->link;
				free(begin);
				break;
			}
		}
		else if (begin->link == list->head)
			break;
		prev = begin;
		begin = begin->link;
	}
}

static void PrintCircularLinkedList(CircularLinkedList *list)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);
	while (begin)
	{
		printf("%d ", begin->item.key);
		if (begin == end)
			break;
		begin = begin->link;
	}
	printf("\n");
}

static void DestroyCircularLinkedList(CircularLinkedList *list)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);
	Node *deleteNode;
	while (begin)
	{
		deleteNode = begin;
		begin = begin->link;
		free(deleteNode);
		if (begin == end)
			break;
	}
	free(list);
	list->head = NULL;
}

static Node* FindLastNode(CircularLinkedList *list)
{
	Node *begin = list->head;

	while (begin)
	{
		if (begin->link == list->head)
			break;
		begin = begin->link;
	}
	return begin;
}