#include <iostream>

using namespace std;

class BST{
	int data;
	BST *left, *right;
public:
	BST();
	void inorder(BST*);
	BST* insert(BST*, int);
	void search(BST*, int);
	void remove(BST*, int);
};

BST::BST(){
	data=0;
	left=right=NULL;
}

BST* BST::insert(BST* root, int data){
	if(!root){
		root=new BST();
		root->data=data;
		return root;
	}
	else if(data < root->data)	insert(root->left, data);
	else if(data > root->data)	insert(root->right, data);
	return root;
}

void BST::inorder(BST* root){
	if(!root)	return;
	inorder(root->left);
	cout<<root->data<<'\t';
	inorder(root->right);
}

void BST::search(BST *root, int data){
	if(!root){
		return;
	}
	if(data == root->data){
		cout<<"\nElement found"<<endl;
		return;
	}
	if(data < root->data)
		search(root->left, data);
	else
		search(root->right, data);
}

void BST::remove(BST *root, int data){
	if(!root){
		return;
	}
	if(data == root->data){
		cout<<"\nElement found"<<endl;
		if(root->left==NULL && root->right==NULL)
			delete root;
		else if(root->left == NULL){
			root->data=root->left->data;
			delete root->left;
			root->left=NULL;
		}
		else if(root->left == NULL && root->right != NULL){
			root->data=root->right->data;
			delete root->right;
			root->right=NULL;
		}
		return;
	}
	if(data < root->data)
		remove(root->left, data);
	else
		remove(root->right, data);
}

int main(){
	BST *root=NULL, *f=new BST();

	int o;
	do{
		cout<<"\n\tChoose.\n1. Insert\n2. Display\n3. Delete\n4. Search\n5. Exit"<<endl;
		cin>>o;
		if(o==1){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			root=f->insert(root, a);
		}
		if(o==2)	f->inorder(root);

		if(o==3){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			f->remove(root, a);
		}

		if(o==4){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			f->search(root, a);
		}
	}while(o!=5);

	return 0;
}