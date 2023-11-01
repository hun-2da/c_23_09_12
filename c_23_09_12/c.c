#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

/**해당 값은 따로 저장되어 있지 않음. 간선으로만 지정*/
typedef struct GraphType {
	/**값이 아님. 정점의 개수*/
	int n;
	/**선*/
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;
int visited[MAX_VERTICES];

void init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
void inseret_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 정점의 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;

}



void set_node(GraphType* g) {

	for (int i = 0; i <= 11; i++)
		inseret_vertex(g, i);

	insert_edge(g, 0, 2);
	insert_edge(g, 0, 4);
	insert_edge(g, 0, 5);
	insert_edge(g, 0, 6);
	insert_edge(g, 0, 9);
	insert_edge(g, 1, 10);
	insert_edge(g, 1, 7);
	insert_edge(g, 1, 4);
	insert_edge(g, 1, 5);
	insert_edge(g, 2, 4);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 4, 5);
	insert_edge(g, 4, 6);
	insert_edge(g, 4, 7);
	insert_edge(g, 4, 5);
	insert_edge(g, 6, 7);
	insert_edge(g, 6, 8);
	insert_edge(g, 6, 8);
	insert_edge(g, 7, 10);
	insert_edge(g, 8, 9);
	insert_edge(g, 8, 10);
	insert_edge(g, 8, 10);
}

void dfs_mat(GraphType* g, int v, int check) {
	// v는 시작위치
	int count = 0;
	//printf("%d\t", v);
	//while (1) {
		/**발견한 위치(현재 위치) */
		int w;
		for (w = v; w < g->n; w++) {//시작하는 위치
			visited[w] = TRUE;	// true로 표기하여 이미 간곳임을 체크
			
			for (int i = 0; i < g->n; i++) {
				if (g->adj_mat[v][i] && !visited[v]) {
					// 간곳이 아니며 간선이 있는 곳 일때 
					w = i; 
					printf("정점 %d -> ", v);	count++;
					if (w == check) {
						printf("탐색 성공 : %d \n", w);
						printf("방문한 노드의 수는? : %d \n", count);
						return;
					}

				}
			}
		}
	//}
}

int main(void) {
	printf("----------------------------\n");
	printf("1   : 깊이 우선 탐색        |\n");
	printf("2   : 너비 우선 탐색        |\n");
	printf("3   : 종료                  |\n");
	printf("----------------------------\n");

	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	set_node(g);

	while (1) {
		printf("메뉴 시작 : ");
		int menu_number = 0;
		scanf_s("%d", &menu_number,sizeof(int));
		if (menu_number == 3) break;

		printf("시작 번호와 탐색할 값을 입력 : ");
		int s_num=0, c_num=0;
		scanf_s("%d", &s_num, sizeof(int));
		scanf_s("%d", &c_num, sizeof(int));

		switch (menu_number) {
		case 1: dfs_mat(g,s_num,c_num);  break;
		case 2: break;
		}
	}
}