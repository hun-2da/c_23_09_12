#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/**노드 구조체*/
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;

//const ARRAY_SIZE = 11;
const TRUE = 1;
const FALSE = 0;

/**thread기능 이용*/
TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;	//오른쪽으로 이동

	if (q == NULL || p->is_thread == TRUE)
		return q;

	while (q->left != NULL) q = q->left;		//최대한 왼쪽으로 이동
	return q;
}
/**중위식*/
void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;
	while (q->left) q = q->left;				//최대한 왼쪽으로 이동
	do {
		printf(" %d ", q->data);
		q = find_successor(q);				//오른쪽 확인

	} while (q);

}
/**부모노드를 확인하기 위한 메소드*/
TreeNode* parent(TreeNode* child) {
	TreeNode* n = child;

	n = n->right;
	if (n->left != child && n->right != child) {	//왼쪽이나 오른쪽에 child node가 없을시 왼쪽으로 한번더 이동
		n = n->left;
	}
	printf("NODE %d의 부모노드는 %d \n", child->data, n->data);


	return n;
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

	parent(&n8);	// 예제의 노드4와 동일
	parent(&n9);	// 예제의 노드5와 동일
	parent(&n5);	// 예제의 노드6와 동일


	printf("중위 순회");
	thread_inorder(root);
	printf("\n");


	return 0;
}
