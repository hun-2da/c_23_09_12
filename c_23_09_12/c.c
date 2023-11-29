#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 20
int sorted[MAX_SIZE]; // 추가 공간이 필요
// i는 정렬된 왼쪽리스트에 대한 인덱스
// j는 정렬된 오른쪽리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스
int m = 0, c = 0;
int ss = 0;


void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		
		if (list[i] <= list[j])  sorted[k++] = list[i++]; 
		else sorted[k++] = list[j++];

		m++;
		c++;
		
	}
	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
			m++;
		}
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
			m++;
		}
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
		
	}
	if (ss == 0) {
		
		for (int i = 0; i < MAX_SIZE; i++)
			printf(" %d ", list[i]);
		printf("\n");
	}

}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;            // 리스트의 균등분할
		merge_sort(list, left, mid);     // 부분리스트 정렬
		merge_sort(list, mid + 1, right);//부분리스트 정렬
		merge(list, left, mid, right);    // 합병
	}
}

int main() {
	int i;
	int n = MAX_SIZE;
	int list[20];
	int sum[2] = {0,0};
	int big=0, small=0;
		printf("Original List \n\n");
	for (ss = 0; ss < n; ss++) {
		srand(time(NULL));
		for (i = 0; i < n; i++) {      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99
			if (ss == 0) {
				printf(" %d ", list[i]);
			}
		}if(ss==0) printf("\n\n\n");
		

		merge_sort(list, 0, n - 1);
		sum[0] += m;
		sum[1] += c;
		big = small = m = c = 0;
	}

	// 각 정렬들의 출력을 한번씩만 하기 위한 코드
	printf("\nmerge 정렬의 이동 평균은 %d \n", sum[0]/n);
	printf("merge 정렬의 비교 평균은 %d \n", sum[1]/n);


	return 0;
}