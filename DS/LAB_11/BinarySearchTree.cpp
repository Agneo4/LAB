#include <iostream>

using namespace std;

class BST{
	int data;
	BST *left, *right;
public:
	BST();
	void display(BST*);
	void insert(BST**, int);
	void search(BST*, int);
    void remove(BST**, int);
};

BST::BST(){
	data=0;
	left=right=NULL;
}

void BST::insert(BST **root, int data){
    if(!*root){
        (*root)=new BST();
        (*root)->data=data;
	}
	else if(data < (*root)->data)	insert(&((*root)->left), data);
	else if(data > (*root)->data)	insert(&((*root)->right), data);
}

void BST::display(BST* root){
	if(!root)	return;
	display(root->left);
	cout<<root->data<<'\t';
	display(root->right);
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

void BST::remove(BST **root, int data){
    if(!*root){
		cout<<"List doesn't Exist."<<endl;
        return;
	}
	if(data == (*root)->data){
		cout<<"\nElement found"<<endl;
        if(!((*root)->left) && !((*root)->right)){
            BST *t=*root;
            delete(t);
            *root=NULL;
            return;
        }
        else if((*root)->right){
            BST *node=*root;
            while(node->left->left && node->left)
                node=node->left;
            (*root)->data=node->left->data;
            BST *t=node->left;
            delete(t);
            node->left=NULL;
            return ;
        }
        else if((*root)->left){
            BST *node=*root;
            while(node->right->right && node->right)
                node=node->right;
            (*root)->data=node->right->data;
            BST *t=node->left;
            delete(t);
            node->right=NULL;
        }
    }
	else if(data < (*root)->data)
		remove(&((*root)->left), data);
	else
		remove(&((*root)->right), data);
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
			f->insert(&root, a);
		}
		if(o==2)	f->display(root);

		if(o==3){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			f->remove(&root, a);
		}

		if(o==4){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			f->search(root, a);
		}
	}while(o!=5);

	return 0;
}