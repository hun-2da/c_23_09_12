#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;
int move = 0, comp = 0;
int f;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];//기준 값
	do {
		do {
			low++;	// 비교할 값1
			comp++;
		}while (low <= right && list[low] < pivot);
		do {
			high--;	//비교할 값2
			comp++;
		}while (high >= left && list[high] > pivot);

		if (low < high) { 
			move++;
			SWAP(list[low], list[high], temp); //교환
		}
	} while (low < high);

	SWAP(list[left], list[high], temp);
	move++;
	if (f == 0) {
		for (int i = 0; i < MAX_SIZE; i++)
			printf(" %d ", list[i]);
		printf("\n");
	}
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}
//
int main(void)
{
	int i;
	n = MAX_SIZE;
	double sum[2] = { 0,0 };

	printf("Original List \n\n");
	for (f = 0; f < n; f++) {
		for (i = 0; i < n; i++) {      	// 난수 생성 및 출력 
			list[i] = rand() % 100;
			if (f == 0) {
				printf(" %d ", list[i]);
			}
		}if (f == 0) printf("\n\n\n");

		srand(time(NULL));
		quick_sort(list, 0, n - 1); // 퀵정렬 호출 

		sum[0] += move;
		sum[1] += comp;
		move = comp = 0;

	}
	printf("\Quick 정렬의 이동 평균은 %f \n", sum[0] / n);
	printf("Quick 정렬의 비교 평균은 %f \n", sum[1] / n);

	return 0;
}


// -------------------------------------------------------------------------------------------------
