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




//------------------------------------------------- stack

typedef int stack_element;
stack_element stack[MAX_VERTICES];
int top = -1;

int is_empty() {
	return (top == -1);
}
int is_full() {
	return (top == (MAX_VERTICES - 1));
}
void push(stack_element item) {
	if (is_full()) {
		fprintf(stderr, " 스택 포화 에러 \n");
		return;
	}
	else stack[++top] = item;
}
stack_element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러 \n");
		return 0;
	}
	else return stack[top--];
}

//------------------------------------------------------


//------------------------------------------------- queue

typedef int queue_element;
queue_element queue[MAX_VERTICES];
int front = -1, rear = -1;

int is_queue_empty() {
	return (front == -1);
}

int is_queue_full() {
	return ((rear + 1) % MAX_VERTICES == front);
}

void enqueue(queue_element item) {
	if (is_queue_full()) {
		fprintf(stderr, " 큐 포화 에러 \n");
		return;
	}else {
		rear = (rear + 1) % MAX_VERTICES;
		queue[rear] = item;
	}
}

queue_element dequeue() {
	if (is_queue_empty()) {
		fprintf(stderr, "큐 공백 에러 \n");
		return 0;
	}
	else {
		int item = queue[front];
		if (front == rear) {
			front = rear = -1;
		}
		else {
			front = (front + 1) % MAX_VERTICES;
		}
		return item;
	}
}

//------------------------------------------------------



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
	int count = 0;

	push(v);  // 초기 정점을 스택에 넣음
	visited[v] = TRUE; // 해당 정점을 방문한 것으로 표시

	while (!is_empty()) {
		int w = pop(); // 스택에서 정점을 꺼냄
		printf("정점 %d -> ", w);
		count++;

		if (w == check) {
			printf("탐색 성공 : %d\n", check);
			printf("방문한 노드의 수는? : %d\n", count);
			return; // 목표 정점을 찾으면 함수를 종료
		}

		// 아직 방문하지 않은 이웃 정점들을 스택에 넣음
		for (int i = 0; i < g->n; i++) {
			if (g->adj_mat[w][i] && !visited[i]) {
				
				push(i);
				visited[i] = TRUE; // 스택에 넣은 정점을 방문한 것으로 표시
			}
		}
	}

	// 스택이 비어도 목표 정점을 찾지 못하면 실패 메시지 출력
	printf("목표 정점을 찾지 못했습니다.\n");
}

void bfs(GraphType* g, int v, int check) {
	int count = 0;

	enqueue(v);  // 초기 정점을 큐에 넣음
	visited[v] = TRUE; // 해당 정점을 방문한 것으로 표시

	while (!is_queue_empty()) {
		int w = dequeue(); // 큐에서 정점을 꺼냄
		printf("정점 %d -> ", w);
		count++;

		if (w == check) {
			printf("탐색 성공 : %d\n", w);
			printf("방문한 노드의 수는? : %d\n", count);
			return; // 목표 정점을 찾으면 함수를 종료
		}

		// 아직 방문하지 않은 이웃 정점들을 큐에 넣음
		
		for (int i = 0; i < g->n; i++) {
			if (g->adj_mat[w][i] && !visited[i]) {
				
				enqueue(i);
				visited[i] = TRUE; // 큐에 넣은 정점을 방문한 것으로 표시
			}
		}
	}

	// 큐가 비어도 목표 정점을 찾지 못하면 실패 메시지 출력
	printf("목표 정점을 찾지 못했습니다.\n");
}

void reset_visited() {
	for (int i = 0; i < MAX_VERTICES; i++) {
		visited[i] = FALSE;
	}
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

		reset_visited();
		

		switch (menu_number) {
		case 1: dfs_mat(g,s_num,c_num);  break;
		case 2: bfs(g, s_num, c_num); break;
		}
	}
}