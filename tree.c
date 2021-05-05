#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;
TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // 추가
TreeNode m4 = { 25, NULL, &m7 }; // 변경
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int get_nonleaf_count(TreeNode* node) {
	int count = 0;

	if (node != NULL) {
		if (node->left != NULL || node->right != NULL) {
			count = get_nonleaf_count(node->left) + get_nonleaf_count(node->right) + 1;
		}
		else return 0;
	}
	return count;
}

int get_oneleaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL)) {
			count = get_oneleaf_count(node->left) + get_oneleaf_count(node->right) + 1;
		}
		else {
			count = get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
		}
	}
	return count;
}

int get_twoleaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if (node->left != NULL && node->right != NULL) {
			count = get_twoleaf_count(node->left) + get_twoleaf_count(node->right) + 1;
		}
		else count = get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
	}
	return count;
}

int get_max(TreeNode* root) {
	int max = INT_MIN;
	if (root != NULL) {
		int left = get_max(root->left);
		int right = get_max(root->right);
		if (left > right) max = left;
		else max = right;

		if (root->data > max) max = root->data;
	}
	return max;
}


int get_min(TreeNode* root) {
	int min = INT_MAX;
	if (root != NULL) {
		int left = get_min(root->left);
		int right = get_min(root->right);
		if (left < right) min = left;
		else min = right;

		if (root->data < min) min = root->data;
	}
	return min;
}

void node_increase(TreeNode* root) {
	if (root != NULL) {
		root->data++;
		node_increase(root->left);
		node_increase(root->right);
	}
}

int equal(TreeNode* root1, TreeNode* root2) {
	if(root1!=NULL){
		if (root1->data != root2->data) return 0;
		if (equal(root1->left, root2->left) && equal(root1->right, root2->right)) return 1;
	}
}

TreeNode* copy(TreeNode* root) {
	TreeNode* new_tree = (TreeNode*)malloc(sizeof(root));
	if (root != NULL) {
		new_tree->left = copy(root->left);
		new_tree->right = copy(root->right);
		new_tree->data = root->data;
		return new_tree;
	}
	return NULL;
}

int main(void) {
	TreeNode* result[MAX_TREE_SIZE];
	TreeNode* clone;
	int i, num;
	printf("가)\n");
	printf("트리 root 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
	printf("트리 root2 중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));
	printf("트리 root 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
	printf("트리 root2 중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));
	printf("트리 root 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2 중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
	printf("트리 root 에서 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2 에서 가장 큰 수는 %d.\n", get_max(root2));
	printf("트리 root 에서 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2 에서 가장 작은 수는 %d.\n", get_min(root2));

	printf("\n 다)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");

	printf("\n 라)\n");
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
}