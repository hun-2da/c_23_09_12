#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/**노드 구조체*/
typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

/**몇번의 노드를 탐색했는지 확인하기 위한 변수*/
int count = 0;

/**재귀 중위 순회​*/
int inorder(TreeNode* root) {
	if (root) {
		count++;
		inorder(root->left); // 왼쪽확인
		printf("%d ", root->key); // 출력
		inorder(root->right); // 오른쪽확인
	}
	return count;
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp ->right = NULL;
	return temp;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;

	return current;
}

/**노드를 삭제하기위한 메소드	(재귀함수)*/
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	count++;

	//입력한 값보다 해당 노드의 키값이 클때
	if (key < root->key)
		root->left = delete_node(root->left, key);//왼쪽으로 이동

	//입력한 키값이 해당 노드의 키값보다 클때
	else if (key > root->key) root->right = delete_node(root->right, key);//오른쪽으로 이동
	
	//키값과 해당 노드의 키값이 같을때
	else {
		if (root->left == NULL) {	//left가 null일때 
			TreeNode* temp = root->right;
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
	
}
/**노드를 삭제하기위한 메소드	(반복 함수)*/
TreeNode* delete_node_while(TreeNode* root, int key) {
	if (root == NULL) {
		return NULL;
	}

	// 삭제할 노드를 찾습니다.
	TreeNode* current = root;
	TreeNode* parent = NULL;
	while (current != NULL && current->key != key) {
		count++;
		parent = current;
		if (key < current->key) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	// 삭제할 노드가 없으면 루트 노드를 반환합니다.
	if (current == NULL) {
		return root;
	}

	// 삭제할 노드가 자식 노드가 없으면 삭제합니다.
	if (current->left == NULL && current->right == NULL) {
		if (parent == NULL) {
			return NULL;
		}
		else if (parent->left == current) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
		return root;
	}

	// 삭제할 노드가 한 명의 자식 노드를 가지고 있으면 자식 노드를 대신
	if (current->left == NULL) {
		if (parent == NULL) {
			root = current->right;
		}
		else if (parent->left == current) {
			parent->left = current->right;
		}
		else {
			parent->right = current->right;
		}
		return root;
	}
	else if (current->right == NULL) {
		if (parent == NULL) {
			root = current->left;
		}
		else if (parent->left == current) {
			parent->left = current->left;
		}
		else {
			parent->right = current->left;
		}
		return root;
	}

	// 삭제할 노드가 두 명의 자식 노드를 가지고 있으면 대신
	TreeNode* successor = min_value_node(current->right);
	current->key = successor->key;
	delete_node(current->right, successor->key);

	return root;
}

/**노드를 추가하기위한 메소드	(재귀함수)*/
TreeNode* insert_node(TreeNode* node, int key) {
	count++;
	if (node == NULL)	return new_node(key);
	if (key < node->key)	node->left = insert_node(node->left, key);
	else if (key > node->key)		node->right = insert_node(node->right, key);

	return node;
}

/**노드 추가 (반복문)*/
TreeNode* insert_node_while(TreeNode* node, int key) {
	TreeNode* current = node;
	while (current != NULL) {
		count++;
		if (key < current->key) {
			if (current->left == NULL) {
				current->left = new_node(key);
				return node;
			}
			current = current->left;
		}
		else {
			if (current->right == NULL) {
				current->right = new_node(key);
				return node;
			}
			current = current->right;
		}
	}
	return new_node(key);
}

/**반복이 사용된 노드 서치*/
TreeNode* search(TreeNode* node, int key) {
	
	while (node != NULL) {
		if (key == node->key) break;
		else if (key < node->key)node = node->left;
		else node = node->right;

		count++;
	}
	if (node != NULL)	printf("방문성공 : %d \n",node->key);

	return node;
}

void check(TreeNode* root) {
	int count_c = 0;
	if (count != 0) {
		count_c = count;
		inorder(root);
	}else count_c = inorder(root);
	printf("\n방문한 노드의 수는? : %d\n", count_c);
	count = 0;
	
}

TreeNode n23 = { 64, NULL, NULL  };
TreeNode n22 = { 62, NULL, NULL  };
TreeNode n18 = { 42, NULL, NULL  };
TreeNode n13 = { 70, NULL, NULL };
TreeNode n12 = { 63, &n22, &n23 };
TreeNode n11 = { 55, NULL, NULL };
TreeNode n10 = { 46, &n18, NULL };
TreeNode n9 = { 25, NULL, NULL };
TreeNode n6 = { 65, &n12, &n13 };
TreeNode n5 = { 53, &n10, &n11 };
TreeNode n4 = { 16, NULL, &n9};
TreeNode n3 = { 74, &n6, NULL };
TreeNode n2 = { 41, &n4, &n5 };
TreeNode n1 = { 60, &n2, &n3 };
/**이진 트리지요오*/
TreeNode* root = &n1;

int main(void) {
	
	while (1) {
	printf("------------------------\n");
	printf("|    s : 검색          |\n");
	printf("|    i : 노드추가      |\n");
	printf("|    d : 노드삭제      |\n");
	printf("|    t : 중위순회      |\n");
	printf("|    I : 노드추가(반복)|\n");
	printf("|    D : 노드삭제(반복)|\n");
	printf("|    c : 종료          |\n");
	printf("------------------------\n");


		printf("\n\n\n메뉴 입력 : ");
		char c=' ';
		scanf_s("%c", &c, sizeof(c));
		if (c == 'c') {
			printf("종료합니다. ");
			exit(0);
		}
		else if (c == 't') 
			check(root);
		
		else {
			int i = 0;
			
			
			switch (c) {
			case 's': 
				printf("검색할 값 입력 : ");
				scanf_s("%d", &i);
				search(root, i); check(root); 
				break;
			case 'i': 
				printf("삽입할 값 입력 : ");
				scanf_s("%d", &i); 
				insert_node(root, i); check(root); 
				break;
			case 'd':
				printf("삭제할 값 입력 : ");
				scanf_s("%d", &i); 
				delete_node(root, i); check(root); 
				break;
			case 'I': 
				printf("삽입할 값 입력 : ");
				scanf_s("%d", &i); 
				insert_node_while(root, i); check(root); 
				break;
			case 'D': 
				printf("검색할 값 입력 : ");
				scanf_s("%d", &i); 
				delete_node_while(root, i); check(root); 
				break;
			default: printf("값이 잘못되었습니다. ");
			}

			
		}
		printf("\n");
		while (getchar() != '\n');
	}
	return 0;
}
