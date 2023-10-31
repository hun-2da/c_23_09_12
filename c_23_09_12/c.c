#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GrapType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GrapType;
int visited[MAX_VERTICES];

void init(GrapType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}
void inseret_vertex(GrapType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 정점의 개수 초과");
		return;
	}
	g->n++;
}
void insert_edge(GrapType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;

}



void set_node(GrapType* g) {

	for (int i = 0; i < 10; i++)
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

void print_adj_mat(GrapType* g,int start, int check) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			//printf("%2d ", g->adj_mat[i][j]);
			if (g->adj_mat[i][j] == start) {

			}
		}printf("\n");
	}
}

int main(void) {
	printf("----------------------------\n");
	printf("1   : 깊이 우선 탐색        |\n");
	printf("2   : 너비 우선 탐색        |\n");
	printf("3   : 종료                  |\n");
	printf("----------------------------\n");

	GrapType* g;
	g = (GrapType*)malloc(sizeof(GrapType));
	init(g);
	set_node(g);

	while (1) {
		printf("메뉴 시작 : ");
		int menu_number = 0;
		scanef_s("%d", &menu_number,sizeof(int));
		if (menu_number == 3) break;

		printf("시작 번호와 탐색할 값을 입력 : ");
		int s_num, c_num;
		scanf_s("%d", &s_num ,sizeof(int));
		scanf_s("%d", &c_num, sizeof(int));

		switch (menu_number) {
		case 1: print_adj_mat(g,s_num,c_num); break;
		case 2: break;
		}
	}
}