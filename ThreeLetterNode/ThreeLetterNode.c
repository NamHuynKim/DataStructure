#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory.h>

typedef char EType;
typedef struct ThreeLetterNode ThreeLetterNode;
typedef struct ThreeLetterList ThreeLetterList;

struct ThreeLetterNode
{
	EType data[4];
	ThreeLetterNode *link;
};

struct ThreeLetterList
{
	ThreeLetterNode *first;
};

static void CreateNode2(ThreeLetterList *list)
{
	ThreeLetterNode *first, *second;
	first = (ThreeLetterNode*)malloc(sizeof(ThreeLetterNode));
	strcpy(first->data, "AAA");
	list->first = first;

	second = (ThreeLetterNode*)malloc(sizeof(ThreeLetterNode));
	memset(second, 0, sizeof(ThreeLetterNode));
	list->first->link = second;
}

static void Insert(ThreeLetterList *list, ThreeLetterNode* node, char *data)
{
	ThreeLetterNode* newNode = NULL;
	newNode = (ThreeLetterNode*)malloc(sizeof(ThreeLetterNode));
	
	memset(newNode, 0, sizeof(ThreeLetterNode));
	strcpy(newNode->data, data);
	
	if (!(list->first))
	{
		list->first = newNode;
		return;
	}

	newNode->link = node->link;
	node->link = newNode;
}

static ThreeLetterNode* CreateNode(char *data)
{
	ThreeLetterNode *newNode = NULL;
	newNode = (ThreeLetterNode*)malloc(sizeof(ThreeLetterNode));
	strcpy(newNode->data, data);
	return newNode;
}

static void DeleteNode(ThreeLetterList *list, ThreeLetterNode *trail, ThreeLetterNode *node)
{
	if (!list->first)
		return;
	node->link = trail->link;
	free(trail);
}

static void Delete(ThreeLetterList *list, ThreeLetterNode *trail)
{
	if (!list->first)
		return;

}

static void PrintList(ThreeLetterList *list)
{
	ThreeLetterNode *begin = list->first;
	while (begin->link != NULL)
	{
		printf("%s \n", begin->data);
		begin = begin->link;
	}
}

static void DestroyList(ThreeLetterList *list)
{
	ThreeLetterNode *begin = list->first;
	while (begin->link != NULL)
	{
		ThreeLetterNode *deleteNode = begin;
		begin = begin->link;
		printf("Delete node: %s \n", deleteNode->data);
		free(deleteNode);
	}
	free(list);
}

static void DestroyList2(ThreeLetterList *list)
{
	
}

static void DestroyNode(ThreeLetterNode *node)
{
	if (node)
	{
		ThreeLetterNode *deleteNode = node;
		node = node->link;
		DestroyNode(deleteNode);
		free(deleteNode);
	}
	else
	{
		free(node);
	}
}

int main(int argc, char *argv[])
{
	ThreeLetterList* list = (ThreeLetterList*)malloc(sizeof(ThreeLetterList));
	CreateNode2(list);
	Insert(list, list->first, "BBB");
	PrintList(list);
	DestroyList(list);
	return 0;
}