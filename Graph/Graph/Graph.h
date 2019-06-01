#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <windows.h>
#define MAX 25
#define NO 65535
//ÁÚ½Ó¾ØÕó
typedef struct{
	char vex[MAX];
	int edge[MAX][MAX];
	int numver, numedge;
}MGraph;
//ÁÚ½Ó±í

typedef struct{
	int begin;
	int end;
	int weight;
}Edge;


void CreatMGraph(MGraph *G);
void DFS(MGraph G, int i);
void DFSTraverse(MGraph G);
void BFSTraverse(MGraph G);
void MiniTree_Kruskal(MGraph G);
int Find(int *parent, int f);

#endif
