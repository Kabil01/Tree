#include <stdio.h>
#include <stdlib.h>

struct k_node{
	int data;
	struct k_node *left;
	struct k_node *right;
};
typedef struct k_node node;
node *root=NULL;

node *getnode(node *root,int d){
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node *insert(node *root,int d){
	if(root==NULL){
		return getnode(root,d);
	}
	else if(root->data<d){
		root->right=insert(root->right,d);
	}
	else{
		root->left=insert(root->left,d);
	}
	return root;
}

node *leaf(node *root){
	node *temp;
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}

node *delete(node *root,int data){
	node *del;
	if(root==NULL){
		return root;
	}
	else if(data<root->data){
		root->left=delete(root->left,data);
	}
	else if(data>root->data){
		root->right=delete(root->right,data);
	}
	else{
		
		if(root->right==NULL && root->left==NULL){
			root=NULL;
			printf("\nhi\n");
		}
		else if(root->right==NULL){
			del=root;
			root=root->left;
			free(del);
		}
		else if(root->left==NULL){
			del=root;
			root=root->right;
			free(del);
		}
		else{
			node *temp=leaf(root->right);
			root->data=temp->data;
			root->right=delete(root->right,temp->data);
		}
	}
	return root;
}
/*
node* delete(node* root,int data){
node* del;
if (root==NULL){
return root;
}
else if(data<root->data){
root->left=delete(root->left,data);
}
else if(data>root->data){
root->right=delete(root->right,data);
}
else{
if(root->right==NULL && root->left==NULL){
free(root);
}
else if(root->right==NULL){
del=root;
root=root->left;
free(del);
}
else if(root->left==NULL){
del=root;
root=root->right;
free(del);
}
else{
node* temp=leaf(root->right);
root->data=temp->data;
root->right=delete(root->right,temp->data);
}
}
return root;
}*/

void preorder(node *root){
	if(root!=NULL){
		printf("-%d-",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void main(){
		int n,a;
		printf("Enter the number of inputs:");
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			printf("Enter the data1:");
			scanf("%d",&a);
			root=insert(root,a);
		}
		preorder(root);
		printf("Enter the element to delete:");
		scanf("%d",&a);
		delete(root,a);
		/*root=insert(root,5);
		root=insert(root,8);
		root=insert(root,1);
		root=insert(root,25);
		root=insert(root,15);
		printf("\n%d",root->data);*/
		preorder(root);
		}