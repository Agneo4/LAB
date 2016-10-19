#include <iostream>

using namespace std;

class BT{
	int data;
	BT* lchild, rchild;

public:
	BT();
	void tr_inorder(BT*);
	void tr_preorder(BT*);
	void tr_posrder(BT*);
	void dis_parent(BT*);
	void depth(BT*);
	void disp_anc(BT*)
	void count_leaf(BT*);
	~BT();
};

void BT::tr_inorder(BT* root){
	BT *curr, *s[20];
	int top=-1;
	if(root==NULL){
		cout<<"Empty list"<<endl;
		return ;
	}

	curr=root;
	while(1){
		while(curr!=NULL){
			s[++top]=curr;
			curr=curr->lchild;
		}

		if(top!=-1){
			curr=s[top--];
			cout<<curr->data
			curr=curr->rchild;
		}
		else	return;
	}
}

void BT::tr_preorder(BT *root){
	BT *curr, *s[20];
	int top=-1;
	if(root==NULL){
		cout<<"Empty list"<<endl;
		return ;
	}

	curr=root;
	while(1){
		while(curr!=NULL){
			s[++top]=curr;
			curr=curr->lchild;
		}

		if(top!=-1){
			curr=s[top--];
			cout<<curr->data
			curr=curr->rchild;
		}
		else	return;
	}
}