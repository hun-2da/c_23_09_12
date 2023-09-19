#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/**노드 구조체*/
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

/**스택의 사이즈_배열 스택*/
#define SIZE 100

/**노드의 수를 구하기 위한 전역 변수*/
int count = 0;


int top = -1;
int top2 = -1;
TreeNode* stack[SIZE];
TreeNode* stack2[SIZE];
/**스택에 노드 저장*/
void push(TreeNode* p) {
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}
/**스택에서 노드를 팝*/
TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}
/**스택2_ 후위순회에 사용_ 좌측 노드*/
void push2(TreeNode* p) {
	if (top2 < SIZE - 1) {
		stack2[++top2] = p;
	}
}
/**스택에서 노드를 팝*/
TreeNode* pop2() {
	TreeNode* p = NULL;
	if (top2 >= 0) {
		p = stack2[top2--];
	}
	return p;
}


/**후위식*/
void postorder_iter(TreeNode* root) {
	count = 0;
	while (1) {
		count++;
		if (!root) {
			root = pop2();				//왼쪽에 갈수 있는길 확인(2번째 stack에서 pop)
			if (!root) { break; }		//2번째 스택이 null이면 break;
			else root = root->left;		//null이 아니면 root를 왼쪽이로 이동
		}
		if (root->left) {				//만약 왼쪽으로 이동할 수 있다면 2번째 stack에 push
			push2(root);
		}
		push(root);						//첫번째 스택에 push
		root = root->right;
	}
	while (1) {
		int num;
		int a =  pop()->data;
		a = check(a);
		if (a != 0) {
			int b = pop2()->data;
			int c = pop2()->data;
			num = (b, c, a);
		}
		else {
			int b = pop(root)->data;
			int c =pop(root)->data;
			c = check(c);
			num = (a, b, c);
		}
		TreeNode tree = {num, NULL,NULL};
		TreeNode* t = &tree;
		push2(t);
		
		if (!root)break;
		printf("[%d]", root->data);

	}
}
int m(int x, int y, int z) {
	int n = 0;
	switch (z) {
	case 1: n = x + y; printf("%d + %d = %d \n", x, y, n); break;
	case 2:n = x - y; printf("%d - %d = %d \n", x, y, n); break;
	case 3:n = x * y; printf("%d * %d = %d \n", x, y, n); break;
	case 4:n = x / y; printf("%d / %d = %d \n", x, y, n); break;
	}
	return n;
}
int check(int a) {
	a = (char)a;
	switch (a) {
	case '+':	return 1;
	case '-':	return 2;
	case '*':	return 3;
	case '/':	return 4;
	}
	return 0;
}

TreeNode n13 = { 7, NULL, NULL };
TreeNode n12 = { 6, NULL, NULL };
TreeNode n11 = { 5, NULL, NULL };
TreeNode n10 = { 4, NULL, NULL };
TreeNode n9 = { 3, NULL, NULL };
TreeNode n8 = { 2, NULL, NULL };
TreeNode n7 = { 9, NULL, NULL };
TreeNode n6 = { (int)('/'), &n12, &n13 };
TreeNode n5 = { (int)('*'), &n10, &n11 };
TreeNode n4 = { (int)('+'), &n8, &n9 };
TreeNode n3 = { (int)('+'), &n6, &n7 };
TreeNode n2 = { (int)('+'), &n4, &n5};
TreeNode n1 = { (int)('-'), &n2, &n3};
/**이진 트리지요오*/
TreeNode* root = &n1;

int main(void) {
	printf("후위 순회");
	postorder_iter(root);
	printf("\n");
	printf("총 노드의 수는 %d 입니다.", count);

	return 0;
}
