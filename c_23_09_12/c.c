#include <stdio.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
    int n;  // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int path[MAX_VERTICES][MAX_VERTICES];

void print_status(GraphType* g) {
    printf("Distance:\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (g->weight[i][j] == INF) printf("INF ");
            else printf("%d ", g->weight[i][j]);
        }
        printf("\n");
    }
}

void floyd(GraphType* g) {
    for (int k = 0; k < g->n; k++) {
        for (int i = 0; i < g->n; i++) {
            for (int j = 0; j < g->n; j++) {
                if (g->weight[i][k] + g->weight[k][j] < g->weight[i][j]) {
                    g->weight[i][j] = g->weight[i][k] + g->weight[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

void print_path(int start, int end) {
    if (path[start][end] != INF) {
        print_path(start, path[start][end]);
        printf("-> %d ", path[start][end]);
        print_path(path[start][end], end);
    }
    else {
        printf("-> %d ", end);
    }
}

int main(void) {
    GraphType g = { 10,
    {{ 0, 3, INF, INF, INF, 11, 12, INF, INF, INF },
    { 3,  0, 5, 4, 1, 7, 8 , INF, INF, INF },
    { INF, 5, 0, 2, INF, INF, 6, 5, INF, INF },
    { INF, 4, 2, 0, 13, INF, INF, 14, INF, 16 },
    { INF, 1, INF, 13, 0, 9, INF,INF, 18, 17 },
    { 11, 7, INF, INF, 9, 0, INF, INF, INF, INF },
    { 12, 8, 6, INF, INF, INF, 0, 13, INF, INF },
    { INF, INF, 5, 14, INF, INF, 13, 0, INF, 15 },
    { INF, INF, INF, INF, 18, INF, INF, INF, 0, 10 },
    { INF, INF, INF, 16, INF, INF, INF, 15, 10, 0 }
    } };

    floyd(&g);
    print_status(&g);

    printf("Shortest Path: ");
    print_path(0, 4);

    return 0;
}