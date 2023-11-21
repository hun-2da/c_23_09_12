#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 20

int select_msum = 0;
int select_qsum = 0;

int insert_msum = 0;
int insert_qsum = 0;

int bubble_msum = 0;
int bubble_qsum = 0;


#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
/** 선택 정렬 */
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 			// 최솟값 탐색
		{
			if (list[j] < list[least]) { 
				least = j; select_msum++; 
			}
			select_qsum++;
		}
		SWAP(list[i], list[least], temp);


	}
}
/**삽입정렬*/
void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
		list[j + 1] = key;
	}
}
/**버블정렬*/
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) 	// 앞뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}



int main() {
	int i;
	int n = MAX_SIZE;
	int list[] = malloc(sizeof(int) * MAX_SIZE);


	for (int j = 0; j < n; j++) {
		srand(time(NULL));
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99


		selection_sort(list, n); // 선택정렬 호출 
		insertion_sort(list, n);
		bubble_sort(list, n);
	}
	

	printf("\n");
	return 0;


	return;
}