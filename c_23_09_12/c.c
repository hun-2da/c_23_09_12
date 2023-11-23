#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 20

int msum = 0;
int qsum = 0;


#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
/** 선택 정렬 */
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 			// 최솟값 탐색
		{
			qsum++;
			if (list[j] < list[least]) {
				least = j;
				msum++;
			}
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
		qsum++;
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			list[j + 1] = list[j];
			msum++;
		} 		// 레코드의 오른쪽 이동
		list[j + 1] = key;
	}
}
/**버블정렬*/
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) { 	// 앞뒤의 레코드를 비교한 후 교체
			qsum++;
			if (list[j] > list[j + 1]) {
				msum++;
				SWAP(list[j], list[j + 1], temp);
			}
		}
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


		selection_sort(list, n);
		msum = qsum = 0;

		insertion_sort(list, n);
		msum = qsum = 0;

		bubble_sort(list, n);
		msum = qsum = 0;
	}

	// 각 정렬들의 출력을 한번씩만 하기 위한 코드
	printf("선택 정렬의 이동 평균은 %d \n", sum[0] / n);
	printf("선택 정렬의 비교 평균은 %d \n", sum[1] / n);
	sum[0] = 0;
	sum[1] = 0;

	printf("삽입 정렬의 이동 평균은 %d \n", sum[2] / n);
	printf("삽입 정렬의 비교 평균은 %d \n", sum[3] / n);
	sum[2] = 0;
	sum[3] = 0;

	printf("버블 정렬의 이동 평균은 %d \n", sum[4] / n);
	printf("버블 정렬의 비교 평균은 %d \n", sum[5] / n);
	sum[4] = 0;
	sum[5] = 0;

	return 0;
}