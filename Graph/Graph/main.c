#define _CRT_SECURE_NO_WARNINGS 1
#include "Graph.h"
int main(){
	MGraph G;
	CreatMGraph(&G);
	/*DFSTraverse(G);
	BFSTraverse(G);*/
	MiniTree_Kruskal(G);


	system("pause");
	return 0;
}