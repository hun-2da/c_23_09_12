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
				least = j; msum++;
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
	int sum[] = {0,0,0,0,0,0};

	for (int j = 0; j < n; j++) {
		srand(time(NULL));
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99


		selection_sort(list, n); // 선택정렬 호출 
		sum[0] += msum / n;
		sum[1] += qsum / n;
		msum = qsum = 0;

		insertion_sort(list, n);
		sum[2] += msum / n;
		sum[3] += qsum / n;
		msum = qsum = 0;

		bubble_sort(list, n);
		sum[4] += msum / n;
		sum[5] += qsum / n;
		msum = qsum = 0;

	}
	for (int s = 0; s < 5; s++) {
		sum[s] /= n;
	}
	 printf("선택 정렬의 이동 평균은 %d \n", sum[0]); 
	 printf("선택 정렬의 비교 평균은 %d \n", sum[1]); 
	 printf("삽입 정렬의 이동 평균은 %d \n", sum[2]); 
	 printf("삽입 정렬의 비교 평균은 %d \n", sum[3]); 
	 printf("버블 정렬의 이동 평균은 %d \n", sum[4]); 
	 printf("버블 정렬의 비교 평균은 %d \n", sum[5]); 

	

	printf("\n");
	return 0;


	return;
}