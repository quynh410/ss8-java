#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//	tao ra 1 node
Node* createNode(int data){
//	cap phat bo nho
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//	chen 1 nut vao cai cay
Node* insertNode(Node* node, int data){
	if(node == NULL){
		 return createNode(data);
	}
	if(data < node->data ){
		node->left = insertNode(node->left, data);
	} else if(data > node->data){
		node->right = insertNode(node->right,data);
	}
	return node;
}

// Ham tim kiem
int searchNode(Node* root, int x){
    if (root == NULL) {
    	
        printf("%d khong ton tai trong cay\n");
        return 0;
    }
    if (root->data == x) {
        printf("%d ton tai trong cay\n");
        return 1;
    }
    if (x < root->data) {
        return searchNode(root->left, x);
    } else {
        return searchNode(root->right, x);
    }
}

// duyet cay inorder trung thu tu
void inOrderNode(Node* node){
	if( node!= NULL){
		inOrderNode(node->left);
		printf("%d\t", node->data);
		inOrderNode(node->right);
	}
} 

int main(){
	Node* tree = NULL;
	tree = insertNode(tree,4);
	tree = insertNode(tree,3);
	tree = insertNode(tree,6);
	tree = insertNode(tree,2);
	tree = insertNode(tree,5);
	
	printf("truong hop 1\n");
	printf("trung thu tu - duyet cay theo inorder: ");
	inOrderNode(tree);
	
	printf("\ntruong hop 2\n");
	int x;
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &x);
    searchNode(tree, x);
	return 0;	
}

