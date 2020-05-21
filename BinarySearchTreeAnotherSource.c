#include <stdio.h>
#include <stdlib.h>

typedef struct _bstNode {
	int value; 
	struct _bstNode* left; 
	struct _bstNode* right; 
}BSTNode;

BSTNode* root = NULL; 

BSTNode* BST_insert(BSTNode* root, int value) {
	if (root == NULL) {
		root = (BSTNode*)malloc(sizeof(BSTNode)); 
		root->left = root->right = NULL; 
		root->value = value;
		return root; 
	}
	else {
		if (root->value > value)
			root->left = BST_insert(root->left, value);
		else
			root->right = BST_insert(root->right, value); 
	}
	return root; 
}

BSTNode* SmallestNode(BSTNode* root) {
	BSTNode* tmp = root; 
	while (tmp->left != NULL)
		tmp = tmp->left; 
	return tmp;
}

BSTNode* BiggestNode(BSTNode* root) {
	BSTNode* tmp = root; 
	while (tmp->right != NULL)
		tmp = tmp->right; 
	return  tmp;
}

BSTNode* BST_delete(BSTNode* root, int value) {
	BSTNode* tNode = NULL; 
	if (root == NULL)
		return NULL; 

	if (root->value > value)
		root->left = BST_delete(root->left, value);
	else if (root->value < value)
		root->right = BST_delete(root->right, value); 
	else {
		// 자식 노드가 둘 다 있을 경우
		if (root->right != NULL && root->left != NULL) {
			tNode = SmallestNode(root->right); 
			root->value = tNode->value; 
			root->right = BST_delete(root->right, tNode->value); 
		}
		else {
			tNode = (root->left == NULL) ? root->right : root->left;
			free(root); 
			return tNode; 
		}
	}
	return root; 
}

BSTNode* BST_search(BSTNode* root, int value) {
	if (root == NULL)
		return NULL; 

	if (root->value == value)
		return root;

	else if (root->value > value)
		return BST_search(root->left, value);
	else
		return BST_search(root->right, value); 
}

void BST_print(BSTNode* root) {
	if (root == NULL)
		return; 

	printf("%d ", root->value); 
	BST_print(root->left); 
	BST_print(root->right); 
}

int main(void) {
	root = BST_insert(root, 5); 
	root = BST_insert(root, 3);
	root = BST_insert(root, 7);
	root = BST_insert(root, 1);
	root = BST_insert(root, 9);
	root = BST_insert(root, 6);

	root = BST_delete(root, 3); 
	// root = SmallestNode(root); 
	BST_print(root); 

}






