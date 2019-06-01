#define _CRT_SECURE_NO_WARNINGS 1
#include "Graph.h"
//创建邻接矩阵
void CreatMGraph(MGraph *G){
	int i, j, k, m,w;
	char s;
	printf("请输入顶点数和边数\n");
	scanf("%d %d", &G->numver, &G->numedge);

	
	for (i = 0; i < G->numver; i++){
		G->vex[i] = 'A'+i;
	}
	for (i = 0; i < G->numver; i++){
		for (j = 0; j < G->numver; j++){
			if (i == j){
				G->edge[i][j] = 0;
			}
			else
			{
				G->edge[i][j] = NO;
			}
		}
	}
	for (k = 0; k < G->numedge; k++){
		printf("请输入边（vi,vj）上的下标i,j及权值w:\n");
		scanf("%d %d %d", &i, &j,&w);
		G->edge[i][j] = w;
	}

	for (i = 0; i < G->numver; i++){
		for (j = 0; j < G->numver; j++){
			printf("%5d   ", G->edge[i][j]);
		}
		printf("\n");
	}
}
//深度优先遍历
int visited[MAX];
void DFS(MGraph G, int i){
	int j;
	visited[i] = 1;
	printf("%c", G.vex[i]);
	for (j = 0; j < G.numver; j++){
		if (G.edge[i][j] != 0 && G.edge[i][j] != NO && !visited[j]){
			DFS(G, j);
		}
	}
}
void DFSTraverse(MGraph G){
	int i;
	for (i = 0; i < G.numver; i++){
		visited[i] = 0;
	}
	for (i = 0; i < G.numver; i++){
		if (!visited[i]){
			DFS(G, i);
		}
	}
}
//广度优先遍历
void BFSTraverse(MGraph G){
	int i, j;
	char temp;
	int front, rear;
	front = rear = -1;
	char Queue[MAX];
	for (i = 0; i < G.numver; i++){
		visited[i] = 0;
	}
	for (i = 0; i < G.numver; i++){
		if (!visited[i]){
			visited[i] = 1;
			printf("%c", G.vex[i]);
			rear=(rear+1)%MAX;
			Queue[rear] = G.vex[i];
			while (front != rear){
				front = (front + 1) % MAX;
				temp = Queue[front];
				for (j = 0; j < G.numver; j++){
					if (G.edge[i][j] != 0 && G.edge[i][j] != NO  && !visited[j]){
						visited[j] = 1;
						printf("%c", G.vex[j]);
						rear = (rear + 1) % MAX;
						Queue[rear] = G.vex[i];
					}
				}
			}
		}
	}

}
//Kruskal算法求最小生成树。
void MiniTree_Kruskal(MGraph G){
	int i, n,j;
	int m = 0;
	Edge edges[MAX];
	for (i = 0; i < G.numver; i++){
		for (j = 0; j < G.numver; j++){
			if (G.edge[i][j] != 0 && G.edge[i][j] != NO){
				edges[m].begin = i;
				edges[m].end = j;
				edges[m].weight = G.edge[i][j];
				m++;
			}
		}
	}
	for (i = 0; i < G.numedge; i++){
		for (j = 0; j < G.numedge-1-i; j++){
			if (edges[j].weight>edges[j + 1].weight){
				Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
	int parent[MAX];
	for (i = 0; i < G.numver; i++){
		parent[i] = 0;
	}
	for (i = 0; i < G.numedge; i++){
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m){
			parent[n] = m;
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
int Find(int *parent, int f){
	while (parent[f]>0){
		f = parent[f];
	}
	return f;
}
