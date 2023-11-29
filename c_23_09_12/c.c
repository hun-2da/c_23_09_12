#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_SIZE 20

int msum = 0;
int qsum = 0;
int sum[] = { 0,0 };

/**쉘 정렬에서 수행될 insert sort*/
void inc_insertion_sort(int list[], int first, int last, int gap)
// list는 random하게 작성됨,
// first는 0~gap 
// last는 최대치
// gap 은 점프 거리
//
{
	/**key : 비교할 대상*/
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {	
		//띄어 넘어 가면서 비교하기 위한 for문, 
		// first + gap : 비교 대상
		key = list[i];
		
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			// i : 비교할 대상의 위치 즉 j는 구분할 값
			// j가 first보다 크면서 && 비교 대상보다 클때
			// j는 - gap
			list[j + gap] = list[j];
			msum++;
			qsum++;
		}msum++;
		list[j + gap] = key;
	}
}
/**쉘 정렬*/
void shell_sort(int list[], int n) {
	int i, gap;
	if (sum[0] == 0) 
		printf("\n\nShell sort\n\n");
	for (gap = n / 2; gap > 0; gap = gap / 2) {		//gap을 총 개수의 반으로 지정
		if ((gap % 2) == 0) gap++;					//gap이 짝수이면 1증가? 
		for (i = 0; i < gap; i++) {
			inc_insertion_sort(list, i, n - 1, gap);
		}
		if (sum[0] == 0) {
		
			for (int m = 0; m < MAX_SIZE; m++)
				printf(" %d ", list[m]);
			printf("\n");
		}
	}
}


int main() {
	int i;
	int n = MAX_SIZE;
	int list[20];
	for (int j = 0; j < n; j++) {
		srand(time(NULL));
		for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
			list[i] = rand() % 100; // 난수 발생 범위 0~99

		if (j == 0) {
			printf("Original List \n\n");
			for (i = 0; i < n; i++)
				printf(" %d ", list[i]);
			printf("\n");
		}

		shell_sort(list, n);
		sum[0] += msum;
		sum[1] += qsum;
		msum = qsum = 0;
	}

	// 각 정렬들의 출력을 한번씩만 하기 위한 코드
	printf("쉘 정렬의 이동 평균은 %d \n", sum[0]/n);
	printf("쉘 정렬의 비교 평균은 %d \n", sum[1]/n);


	return 0;
}