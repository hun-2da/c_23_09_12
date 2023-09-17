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
/**중위*/
void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {		//최대한 왼쪽까지 이동
			push(root);							//왼쪽 노드를 전부 저장 (왼,중,오 순이기 때문에 왼쪽노드를 전부 저장 후 오른쪽 확인할 예정)
		}
		root = pop();							//왼쪽노드를 불러와 출력하고 오른쪽 노드로 이동
		if (!root) break;						//더이상 팝할 노드가 없다면 종료
		printf("[%d]", root->data);
		root = root->right;
	}
}
/**전위*/
void preorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left) {		//최대한 왼쪽노드 위치까지 이동
			if (root->right) {
				push(root);						//오른쪽 자식 노드가 있는 경우에 스택에 저장
			}
			printf("[%d]", root->data);
		}
		if (!root) {
			root = pop();						// root가 NULL이면 스택에 저장된 노드를 팝한 후 오른쪽으로 이동
			if (!root) break;					// 더이상 pop할 노드가 없다면 종료(마지막)
			root = root->right;
		}
	}
}
/**후위식*/
void postorder_iter(TreeNode* root) {
	while (1) {

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
		root = pop(root);				//1번째 stack에서 하나씩 불러옴
		if (!root)break;
		printf("[%d]", root->data);

	}

}

TreeNode n15 = { 11, NULL, NULL };
TreeNode n14 = { 10, NULL, NULL };
TreeNode n9 = { 5, NULL, NULL };
TreeNode n8 = { 4, NULL, NULL };
TreeNode n7 = { 9, &n14, &n15 };
TreeNode n6 = { 8, NULL, NULL };
TreeNode n5 = { 6, NULL, NULL };
TreeNode n4 = { 3, &n8, &n9 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n2 = { 2, &n4, &n5 };
TreeNode n1 = { 1, &n2, &n3 };
/**이진 트리지요오*/
TreeNode* root = &n1;

int main(void) {
	printf("중위 순회");
	inorder_iter(root);
	printf("\n");
	printf("전위 순회");
	preorder_iter(root);
	printf("\n");
	printf("후위 순회");
	postorder_iter(root);
	printf("\n");

	return 0;
}
