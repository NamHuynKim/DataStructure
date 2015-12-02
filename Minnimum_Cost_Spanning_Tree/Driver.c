#include <stdlib.h>

#define ETYPE
typedef char EType;

#define TRUE 1
#define FALSE !TRUE

#include "Graph.h"
#define SIZE_VERTICES 7

static void PrintGraph(const Graph *graph);

int main(int argc, char *argv[])
{
	Vertex *vertex = NULL;
	Graph *graph = NULL;

	graph = CreateGraph(SIZE_VERTICES);

	vertex = GetHead(graph, 0); // VertexA
	vertex->link = CreateVertex(1, 28);
	vertex->link->link = CreateVertex(5, 10);

	vertex = GetHead(graph, 1); // VertexB
	vertex->link = CreateVertex(0, 28);
	vertex->link->link = CreateVertex(2, 16);
	vertex->link->link->link = CreateVertex(6, 14);

	vertex = GetHead(graph, 2); // VertexC
	vertex->link = CreateVertex(1, 16);
	vertex->link->link = CreateVertex(3, 12);

	vertex = GetHead(graph, 3); // VertexD
	vertex->link = CreateVertex(2, 12);
	vertex->link->link = CreateVertex(4, 22);
	vertex->link->link->link = CreateVertex(6, 18);

	vertex = GetHead(graph, 4); // VertexE
	vertex->link = CreateVertex(3, 22);
	vertex->link->link = CreateVertex(5, 25);
	vertex->link->link->link = CreateVertex(6, 24);

	vertex = GetHead(graph, 5); // VertexF
	vertex->link = CreateVertex(0, 10);
	vertex->link->link = CreateVertex(4, 25);

	vertex = GetHead(graph, 6); // VertexG
	vertex->link = CreateVertex(1, 14);
	vertex->link->link = CreateVertex(4, 24);

	PrintGraph(graph);
	PerformPrim(graph);
	return 0;
}

void PrintGraph(const Graph *graph)
{
	int index = 0;
	int size = 0;
	if (!graph) return;
	if ((size = graph->size) <= 0) return;

	for (; index < size; index++)
	{
		Vertex *begin = NULL;
		Vertex head = graph->vertices[index];
		printf("Head[%d]: ", index);

		for (begin = head.link; begin; begin = begin->link)
			printf("(K[%d],%d) ", begin->key, begin->weight);
		printf("\n");
	}
}