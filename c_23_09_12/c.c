﻿#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
    int n;                         // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[]) {
    int i, min, minpos;
    min = INF;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

void print_status(GraphType* g) {
    static int step = 1;
    printf("step %d \n", step++);
    printf("distance: ");
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF)
            printf("* ");
        else
            printf("%2d ", distance[i]);
    }
    printf("\n");
    printf("found:   ");
    for (int i = 0; i < g->n; i++)
        printf("%2d ", found[i]);
    printf("\n\n");
}

void shortest_path(GraphType* g, int start) {
    int i, u, w;
    for (i = 0; i < g->n; i++) {
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }
    found[start] = TRUE;
    distance[start] = 0;
    for (i = 0; i < g->n - 1; i++) {
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (w = 0; w < g->n; w++)
            if (!found[w])
                if (distance[u] + g->weight[u][w] < distance[w])
                    distance[w] = distance[u] + g->weight[u][w];
    }
}

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct GraphType2 {
    int n;                      // 정점의 개수
    Node* adj_list[MAX_VERTICES];
} GraphType2;

Node* create_node(int vertex, int weight) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->weight = weight;
    new_node->next = NULL;
    return new_node;
}

void add_edge(GraphType2* g, int start, int end, int weight) {
    Node* new_node = create_node(end, weight);
    new_node->next = g->adj_list[start];
    g->adj_list[start] = new_node;
}

void shortest_path2(GraphType2* g, int start) {
    int i, u;
    Node* temp;
    for (i = 0; i < g->n; i++) {
        distance[i] = INF;
        found[i] = FALSE;
    }
    distance[start] = 0;
    for (i = 0; i < g->n - 1; i++) {
        print_status(g);
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        for (temp = g->adj_list[u]; temp; temp = temp->next) {
            if (temp->vertex < 0 || temp->vertex >= g->n) {
                // Handle invalid vertex value
                printf("Invalid vertex value: %d\n", temp->vertex);
                continue;
            }
            if (!found[temp->vertex]) {
                if (distance[u] + temp->weight < distance[temp->vertex])
                    distance[temp->vertex] = distance[u] + temp->weight;
            }
        }
    }
}

int main(void)
{
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
	}};

	shortest_path(&g, 0);	// 인접행렬 구현
	//shortest_path2(&g, 0);
	return;
}