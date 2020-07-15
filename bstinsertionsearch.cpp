#include <iostream>
using namespace std;

struct bstNode{
	int data;
	bstNode *left;
	bstNode *right;
};
bstNode* newNode(int data){
	bstNode* node= new bstNode();
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
bstNode* insert(bstNode* root,int data){
	if(root==NULL){
		root= newNode(data);
		return root;
	}
	else if(data<=root->data){
		root->left=insert(root->left,data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;
}
bool Search(bstNode* root,int data){
	if(root==NULL)
		return false;
	else if(root->data==data)
		return true;
	else if(root->data>data)
		return search(root->left,data);
	else 
		return search(root->right,data);
}

int main() {
	// your code goes here
	bstNode* root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,23);
	root=insert(root,89);
	root=insert(root,98);
	//cout<<root->right->right->right->right->data<<endl;
	if(Search(root,20)== true)
		cout<<"YESSS"<<endl;
	else 
		cout<<"NOOOO"<<endl;
	return 0;
}
