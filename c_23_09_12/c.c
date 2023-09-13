#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;


/*link를 이용_ 트리 초기화*/
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
TreeNode* root = &n1;

/*array를 이용_ 트리 초기화*/
int array_Tree[] = {-1,1,2,7,3,6,8,9,4,5,-1,-1,-1,-1,10,11};
const array_size = 16;


/** 링크가 이용된 트리 중위 순회​*/
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // 왼쪽확인
		printf("%d ", root->data); // 출력
		inorder(root->right); // 오른쪽확인
	}
}
/**배열이 이용된 트리 중위 순회*/
array_inorder(int array[], int check) {
	if (check * 2 <= array_size) 
		array_inorder(array, check * 2);		//왼쪽확인
	
	if(check<array_size&&array[check] != -1)
		printf("%d ", array[check]);			//출력

	if (check*2 + 1 <= array_size)
		array_inorder(array, check * 2 + 1);	//오른쪽 확인
}

/** 링크가 이용된 트리  전위 순회​ */ 
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); // 출력
		preorder(root->left); // 왼쪽확인​
		preorder(root->right); // 오른쪽확인​
	}
}
/**배열이 이용된 트리 전위 순회*/
array_preorder(int array[], int check) {

	if (check < array_size && array[check] != -1)		//출력
		printf("%d ", array[check]);

	if (check * 2 <= array_size)
		array_preorder(array, check * 2);				//왼쪽확인

	if (check * 2 + 1 <= array_size)
		array_preorder(array, check * 2 + 1);			//오른쪽확인
}
/** 링크가 이용된 트리 후위 순회​ */
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left); // 왼쪽확인
		postorder(root->right); // 오른쪽 확인​
		printf("%d ", root->data); // 출력​
	}
}
/**배열이 이용된 트리 후위 순회*/
array_postorder(int array[], int check) {

	if (check * 2 <= array_size)
		array_postorder(array, check * 2);			//왼쪽확인

	if (check * 2 + 1 <= array_size)
		array_postorder(array, check * 2 + 1);		//오른쪽 확인

	if (check < array_size && array[check] != -1)
		printf("%d ", array[check]);				//출력
}


int main(void) {
	printf("<Linked Tree>\n");
	printf("1. 전위 순회\n");
	preorder(root);
	printf("\n2.중위 순회\n");
	inorder(root);
	printf("\n3. 후위 순회\n");
	postorder(root);

	printf("\n\n\n<Array Tree>\n");
	printf("1.전위 순회\n");
	array_preorder(array_Tree, 1);
	printf("\n2.중위 순회\n");
	array_inorder(array_Tree,1);
	printf("\n2.후위 순회\n");
	array_postorder(array_Tree, 1);
	return 0;
}