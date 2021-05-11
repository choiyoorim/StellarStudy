#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key) return search(node->left, key);
	else return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);
	return node;
}

TreeNode* get_minimum(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

TreeNode* get_maximum(TreeNode* node) {
	TreeNode* current = node;
	while (current->right != NULL) {
		current = current->right;
	}
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (key < root->key) root->left = delete_node(root->left, key);
	else if (key > root->key) root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		
		TreeNode* temp = get_minimum(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void print_node(TreeNode* root) {
	if (root) {
		printf("%d ", root->key);
		print_node(root->left);
		print_node(root->right);
	}
}

int get_count_node(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		count = 1 + get_count_node(node->left) + get_count_node(node->right);
	}
	return count;
}

int get_height_node(TreeNode* node) {
	int height = 0;
	if (node != NULL) {
		height = 1 + max(get_height_node(node->left), get_height_node(node->right));
	}
	return height;
}

int main() {
	char order;
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	int num = 0;
	int height,count;

	printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,h<eight>,c<ount>,m<ax>,n<min>,q<uit>: ");
	scanf("%c", &order);
	while (order != 'q') {
		fflush(stdin);
		switch (order) {
		case 'i': 
			printf("삽입할 key값 입력:"); 
			scanf("%d",&num);
			root = insert_node(root, num);
			break;
		case 'd': 
			printf("삭제할 key값 입력:"); 
			scanf("%d",&num);
			root = delete_node(root, num);
			break;
		case 's':
			printf("탐색할 key값 입력:");
			scanf("%d",&num);
			tmp = search(root, num);
			if (tmp != NULL) printf("있음\n");
			else printf("없음\n");
			break;
		case 'p': 
			print_node(root);
			printf("\n");
			break;
		case 'h': 
			height = get_height_node(root);
			printf("트리의 높이는 %d\n", height);
			break;
		case 'c': 
			count = get_count_node(root);
			printf("노드의 개수는 %d\n", count);
			break;
		case 'm':
			tmp = get_maximum(root);
			printf("가장 큰 값은 %d\n", tmp->key);
			break;
		case 'n':
			tmp = get_minimum(root);
			printf("가장 작은 값은 %d\n", tmp->key);
			break;
		}
		fflush(stdin);
		printf("Enter i<nsert>,d<elete>,s<earch>,p<rint>,h<eight>,c<ount>,m<ax>,n<min>,q<uit>: ");
		scanf(" %c", &order);
	}
	return 0;
}