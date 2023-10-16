#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include<math.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

/**생성 함수*/
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
/**초기화 함수*/
void init(HeapType* h) {
	h->heap_size = 0;
}
/**노드의 이동 횟수를 구하기 위한 변수*/
int count = 0;
/**기본 노드들을 지정해 두기위한 메소드 출력을 하지 않게 하기 위함*/
void insert_defalut_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
/**현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.*/
/**삽입 함수*/
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	h->heap[i] = item;
	print_t(h); printf("\n");
	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		
		h->heap[i] = h->heap[i / 2];
		i /= 2;
		h->heap[i] = item;
		print_t(h);	count++;	printf("\n");

	}
	printf("노드가 이동된 횟수는 : %d \n", count); count = 0;

	//h->heap[i] = item;     // 새로운 노드를 삽입
}
/**프린트하여 트리 순회*/
print_t(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++)
		printf("%d ", h->heap[i].key);
}
// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	
	while (child <= h->heap_size) {
		print_t(h);	count++;	printf("\n");
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
		
	}
	h->heap[parent] = temp;
	printf("노드가 이동된 횟수는 : %d \n", count); count = 0;
	return item;
}
void node_print(HeapType* h) {
	int height = 1, number = 1;
	int t_log = log2(h->heap_size);

	for (int i = 0; i <= t_log; i++) {
		printf("\n[%d]", i+1);
		do {
			printf(" %d\t", h->heap[number++].key);
		} while (number <= h->heap_size && number <= height);
		
		height = height * 2 + 1;
	}
	printf("\n");
}
int main(void)
{

	HeapType* heap;
	heap = create(); 	// 히프 생성
	init(heap);	// 초기화
	element e_array[10] = { { 90 },{ 89 },{ 70 }, { 36 }, { 75 }, { 63 }, { 65 },  { 21 }, { 18 }, {15} }; //기본 값

	for (int i = 0; i < 10; i++)
		insert_defalut_heap(heap, e_array[i]);
	
	

	while(1){
		printf("------------------------\n");
		printf("|    i : 노드추가      |\n");
		printf("|    d : 노드삭제      |\n");
		printf("|    p : 레벨별 출력   |\n");
		printf("|    e : 종료          |\n");
		printf("------------------------\n");

		printf("메뉴 입력 : ");
		
		char c = ' ';
		scanf_s("%c", &c , sizeof(c));

		switch (c) {
		case 'i': printf("추가할 값을 입력하십시오 : "); break;
		case 'd': 
			delete_max_heap(heap);
			while (getchar() != '\n');
			continue;
			break;
		case 'p': printf("트리 레벨별 출력"); 
			node_print(heap);
			while (getchar() != '\n');
			continue;
		case 'e': printf("종료합니다. "); exit(1);
		default: printf("입력한 값은 없는 값입니다.\n"); continue;
		}

		int n = 0;
		scanf_s("%d", &n);
		element e = { n };

		switch (c) {
		case 'i': insert_max_heap(heap,e); break;
		case 'p': node_print(heap); break;
		}
		while (getchar() != '\n');
	}
	free(heap);
	return 0;
}



