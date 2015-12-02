#ifndef GRAPH_H
#define GRAPH_H

#ifndef ETYPE
#define ETYPE 
typedef int EType;
#endif

#ifndef BOOL
#define BOOL
typedef int Bool;
#endif

typedef struct vetex Vertex;
typedef struct graph Graph;

struct vetex
{
	int key;
	int weight;
	EType item;
	Vertex *link;
};

struct graph
{
	int size;
	Vertex *vertices;
};

Graph *CreateGraph(const int size);
Vertex *CreateVertex(const int key, int weight);
Vertex *GetHead(const Graph *graph, const int key);
void PerformKruskal(Graph *graph);
void PerformPrim(Graph *graph);
void PerformSollin(Graph *graph);
Bool IsCycle(Graph *graph);
#endif