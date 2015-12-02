# include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct element Element;
typedef struct node Node;
typedef struct doublylinkedlist DoublyLinkedList;

struct element
{
	int key;
};
struct node
{
	Node *llink;
	Element item;
	Node *rlink;
};
struct doublylinkedlist
{
	Node *head;
	Node *tail;
};

static DoublyLinkedList *CreateDoublyLinkedList();
static void AddFirstDoublyLinkedList(DoublyLinkedList *list, Element item);
static void AddLastDoublyLinkedList(DoublyLinkedList *list, Element item);
static void InsertDoublyLinkedList(Node *node, Element item);
static void DeleteDoublyLinkedList(DoublyLinkedList *list, const int key);
static void PrintDoublyLinkedList(DoublyLinkedList *list);
static void PrintReverseDoublyLinkedList(DoublyLinkedList *list);

int main(int argc, char *argv[])
{
	DoublyLinkedList *doubleList = CreateDoublyLinkedList();
	Element item;

	item.key = 5;
	AddFirstDoublyLinkedList(doubleList, item);
	PrintDoublyLinkedList(doubleList);

	item.key = 10;
	AddFirstDoublyLinkedList(doubleList, item);
	PrintDoublyLinkedList(doubleList);

	item.key = 11;
	AddFirstDoublyLinkedList(doubleList, item);
	PrintDoublyLinkedList(doubleList);

	item.key = 12;
	AddFirstDoublyLinkedList(doubleList, item);
	PrintDoublyLinkedList(doubleList);

	item.key = 15;
	AddLastDoublyLinkedList(doubleList, item);
	PrintDoublyLinkedList(doubleList);

	item.key = 35;
	InsertDoublyLinkedList(doubleList->head->rlink, item);
	PrintDoublyLinkedList(doubleList);

	DeleteDoublyLinkedList(doubleList, 11);
	PrintDoublyLinkedList(doubleList);

	item.key = 45;
	InsertDoublyLinkedList(doubleList->head->rlink, item);
	PrintDoublyLinkedList(doubleList);

	DeleteDoublyLinkedList(doubleList, 35);
	PrintDoublyLinkedList(doubleList);

	PrintReverseDoublyLinkedList(doubleList);
	return 0;
}

static DoublyLinkedList *CreateDoublyLinkedList()
{
	DoublyLinkedList *d = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	d->head = NULL;
	d->tail = NULL;
	//memset ÇØÁà¾ßÇÔ
	return d;
}

static void AddFirstDoublyLinkedList(DoublyLinkedList *list, Element item)
{
	Node* node = (Node*)malloc(sizeof(Node));
	Node* temp;
	node->item = item;
	node->llink = NULL;
	printf("AddFirst list = %d\n", item.key);
	if (list->head == NULL)
	{
		node->rlink = NULL;
		list->head = node;
		list->tail = node;
		return;
	}
	temp = list->head;
	list->head->llink = node;
	node->rlink = temp;
	list->head = node;
}

static void AddLastDoublyLinkedList(DoublyLinkedList *list, Element item)
{
	Node* node = (Node*)malloc(sizeof(Node));
	Node* temp;
	node->item = item;
	node->rlink = NULL;
	printf("AddLast list = %d\n", item.key);
	if (list->head == NULL)
	{
		node->llink = NULL;
		list->head = node;
		list->tail = node;
		return;
	}
	temp = list->tail;
	list->tail->rlink = node;
	node->llink = temp;
	list->tail = node;
}

static void InsertDoublyLinkedList(Node *node, Element item)
{
	printf("Insert list = %d after %d \n", item.key, node->item.key);
	Node* temp = (Node*)malloc(sizeof(Node));
	memset(temp, 0x00, sizeof(Node));
	temp->item = item;
	temp->rlink = node->rlink;
	temp->llink = node;
	node->rlink->llink = temp;
	node->rlink = temp;
}

static void DeleteDoublyLinkedList(DoublyLinkedList *list, const int key)
{
	Node *Begin = (Node*)malloc(sizeof(Node));
	Node *deleteNode = (Node*)malloc(sizeof(Node));
	Begin = list->head;
	while (Begin)
	{
		if (Begin->item.key == key)
		{
			printf("Delete list = %d", key);
			deleteNode = Begin;
			Begin->llink->rlink = Begin->rlink;
			Begin->rlink->llink = Begin->llink;
			free(deleteNode);
			break;
		}
		Begin = Begin->rlink;
	}
	printf("\n");
}

static void PrintDoublyLinkedList(DoublyLinkedList *list)
{
	Node *Begin = (Node*)malloc(sizeof(Node));
	Begin = list->head;
	while (Begin)
	{
		printf("%d ", Begin->item.key);
		Begin = Begin->rlink;
	}
	printf("\n");
}

static void PrintReverseDoublyLinkedList(DoublyLinkedList *list)
{
	printf("Reverse list \n");
	Node *Begin = (Node*)malloc(sizeof(Node));
	Begin = list->tail;
	while (Begin)
	{
		printf("%d ", Begin->item.key);
		Begin = Begin->llink;
	}
	printf("\n");
}