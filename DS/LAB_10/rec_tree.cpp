#include <iostream>

using namespace std;

class BT{
	int data;
	BT* lchild, *rchild;

public:
	BT();
	void insert(BT**, int);
	void tr_inorder(BT*);
	~BT();
};

BT::BT(){
	data=0;
	lchild=rchild=NULL;
}

void BT::insert(BT* *root, int v){
    BT* curr = *root;
    if(curr == NULL){
        curr =new BT();
        curr->lchild = curr->rchild = NULL;
        curr->data = v;
        *root = curr;
    }
    else{
        if(v < curr->data)   insert(&curr->lchild, v);
        else  insert(&curr->rchild, v);
    }
}


void BT::tr_inorder(BT* root){
	if(!root)	return;
	tr_inorder(root->lchild);
	cout<<root->data<<'\t';
	tr_inorder(root->rchild);
}

BT::~BT(){
}

int main(){
	BT* root=NULL;

	int o;
	do{
		cin>>o;
		if(o==1){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			root->insert(&root, a);
		}
		if(o==2)	root->tr_inorder(root);
	}while(o!=3);

	return 0;
}