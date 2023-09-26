#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/**노드 구조체*/
typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;


//#define SIZE 100
//int top = -1;
//TreeNode* stack[SIZE];
//
///**스택에 노드 저장*/
//void push(TreeNode* p) {
//	if (top < SIZE - 1) {
//		stack[++top] = p;
//	}
//}
///**스택에서 노드를 팝*/
//TreeNode* pop() {
//	TreeNode* p = NULL;
//	if (top >= 0) {
//		p = stack[top--];
//	}
//	return p;
//}

/**몇번의 노드를 탐색했는지 확인하기 위한 변수*/
int count = 0;

/**재귀 중위 순회​*/
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // 왼쪽확인
		printf("%d ", root->key); // 출력
		inorder(root->right); // 오른쪽확인
	}
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp ->right = NULL;
	return temp;

}
/**노드를 삭제하기위한 메소드	(재귀함수)*/
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key) root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode * temp = root -> left
		}
	}
}
/**노드를 추가하기위한 메소드	(재귀함수)*/
TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL)	return new_node(key);
	if (key < node->key)	node->left = insert_nod(node->left, key);
	else if (key > node->key)		node->right = insert_node(node->right, key);

	return node;
}
/**반복이 사용된 노드 서치*/
TreeNode* search(TreeNode* node, int key) {
	
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)node = node->left;
		else node = node->right;

		count++;
	}
	if (node != NULL)	printf("방문성공 : %d \n",node->key);

	return node;
}

void check() {
	printf("방문한 노드의 수는? : %d\n", count);
	count = 0;
	inorder(root);
}

TreeNode n15 = { 11, NULL, NULL ,0 };
TreeNode n14 = { 10, NULL, NULL,1 };
TreeNode n9 = { 5, NULL, NULL,1 };
TreeNode n8 = { 4, NULL, NULL,1 };
TreeNode n7 = { 9, &n14, &n15,0 };
TreeNode n6 = { 8, NULL, NULL,1 };
TreeNode n5 = { 6, NULL, NULL,1 };
TreeNode n4 = { 3, &n8, &n9,0 };
TreeNode n3 = { 7, &n6, &n7,0 };
TreeNode n2 = { 2, &n4, &n5,0 };
TreeNode n1 = { 1, &n2, &n3,0 };
/**이진 트리지요오*/
TreeNode* root = &n1;

int main(void) {

	n8.right = &n4;
	n9.right = &n2;
	n5.right = &n1;
	n6.right = &n3;
	n14.right = &n7;

	printf("------------------------\n");
	printf("|    s : 검색          |\n");
	printf("|    i : 노드추가      |\n");
	printf("|    d : 노드삭제      |\n");
	printf("|    t : 중위순회      |\n");
	printf("|    I : 노드추가(반복)|\n");
	printf("|    D : 노드삭제(반복)|\n");
	printf("|    c : 종료          |\n");
	printf("------------------------\n");

	while (1) {
		printf("\n\n\n메뉴 입력 : ");
		char c = ' ';
		scanf_s("%c", &c);
		int i = 0;
		printf("검색할 값 입력 : ");
		scanf_s("%d", &i);


		switch (c) {
		case 's': search(root, i); check(); break;
		case 'i': insert_node(root, i); check(); break;
		case 'd': break;
		case 't': break;
		case 'I': break;
		case 'D': break;
		case 'c': break;
		}



	}


	printf("중위 순회");
	thread_inorder(root);
	printf("\n");


	return 0;
}
