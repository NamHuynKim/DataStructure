#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

#define IsFull(ptr) (!(ptr))

Vertex *CreateVertex(const int key, int weight)
{
	Vertex *vertexNew = (Vertex *)malloc(sizeof(Vertex));
	if (IsFull(vertexNew))
	{
		fprintf(stderr, "Insufficient memory\n");
		exit(1);
	}
	memset(vertexNew, 0x00, sizeof(Vertex));
	vertexNew->key = key;
	vertexNew->weight = weight;

	return vertexNew;
}

Graph *CreateGraph(const int size)
{
	int sizeVertices = 0;
	Graph *graphNew = (Graph *)malloc(sizeof(Graph));
	if (IsFull(graphNew))
	{
		fprintf(stderr, "Insufficient memory\n");
		exit(1);
	}
	memset(graphNew, 0x00, sizeof(Graph));
	graphNew->size = size;

	sizeVertices = sizeof(Vertex)* size;
	if (IsFull(graphNew->vertices = (Vertex *)malloc(sizeVertices)))
	{
		fprintf(stderr, "Insufficient memory\n");
		exit(1);
	}

	memset(graphNew->vertices, 0x00, sizeVertices);
	return graphNew;
}

Vertex *GetHead(const Graph *graph, const int key)
{
	if (!graph) return NULL;
	if (key >= graph->size) return NULL;

	return &graph->vertices[key];
}

void PerformKruskal(Graph *graph)
{
	
}

void PerformPrim(Graph *graph)
{
	
}

void PerformSollin(Graph *graph)
{

}