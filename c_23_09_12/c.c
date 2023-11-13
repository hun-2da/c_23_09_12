#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	/**정점의 개수*/
	int n;
	/**맵*/
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;


/**추가되면 값이 변경*/
int selected[MAX_VERTICES];

/**거리*/
int distance[MAX_VERTICES];

/**노드의 수만큼 */
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)		//selected가 false인 경우 i값을 저장
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;		// 선택되지 않았으며 v보다 더 적은 크기의 거리가 있을때 v에 저장
	return (v);
}
void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;				// distance를 INF로 초기화
	distance[s] = 0;					//s는 시작점. 본인 위치이기 때문에 0
	for (i = 0; i < g->n; i++) {		
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;	//갈 수 없으면 return
		printf("정점 %d 추가\n", u+1);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF) //해당 행에 갈 수 있는 열이 있다면
				if (!selected[v] && g->weight[u][v] < distance[v]) // 선택되지 않았고 가장 작다면
					distance[v] = g->weight[u][v];
	}
}

int main(void)
{
	GraphType g = { 10/*n을 초기화 하는 부분*/,
	{
	{ 0, 3, INF, INF, INF, 11, 12, INF, INF, INF },
	{ 3,  0, 5, 4, 1, 7, 8 , INF, INF, INF },
	{ INF, 5, 0, 2, INF, INF, 6, 5, INF, INF },
	{ INF, 4, 2, 0, 13, INF, INF, 14, INF, 16 },
	{ INF, 1, INF, 13, 0, 9, INF,INF, 18, 17 },
	{ 11, 7, INF, INF, 9, 0, INF, INF, INF, INF },
	{ 12, 8, 6, INF, INF, INF, 0, 13, INF, INF },
	{ INF, INF, 5, 14, INF, INF, 13, 0, INF, 15 },
	{ INF, INF, INF, INF, 18, INF, INF, INF, 0, 10 },
	{ INF, INF, INF, 16, INF, INF, INF, 15, 10, 0 }
	}};
	prim(&g, 0);
	return 0;

}