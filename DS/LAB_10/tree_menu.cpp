#include <iostream>

using namespace std;

class BT{
	int data;
	BT* lchild, rchild;

public:
	BT();
	void tr_inorder(BT*);
	void tr_preorder(BT*);
	void tr_postorder(BT*);
	int dis_parent(BT*, int);
	void depth(BT*);
	int disp_anc(BT*);
	int count_leaf(BT*);
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

void BT::tr_postorder(BT *root){
	BT *curr, *s[20];
	int top=-1;
	if(root==NULL){
		cout<<"Empty list"<<endl;
		return ;
	}

	curr=root;
	while(1){
		if(top!=-1){
			curr=s[top--];
			cout<<curr->data
			curr=curr->rchild;
		}
		while(curr!=NULL){
			s[++top]=curr;
			curr=curr->lchild;
		}
		else	return;
	}
}

int BT::dis_parent(BT* root, int elem){
	BT*curr=root;
	if(curr->data==elem){
		return 1;
	}
	
	if(dis_parent(curr->lchild,elem)==1){
		cout<<curr->data;
		return 0;
	}
	else if (dis_parent(curr->rchild, elem)==1){
		cout<<curr->data;
		return 0;
	}
	return 0;
}

int BT::count_leaf(BT* root){
	static int c=0;
	if(root->lchild==root->rchild && root->rchild==NULL)
		c++;
	count_leaf(root->lchild);
	count_leaf(root->rchild);
	return c;
}

int BT::disp_anc(BT* root, int elem){
	BT*curr=root;
	if(curr->data==elem){
		return 1;
	}
	
	if(disp_anc(curr->lchild,elem)==1){
		cout<<curr->data;
		return 1;
	}
	else if (disp_anc(curr->rchild, elem)==1){
		cout<<curr->data;
		return 1;
	}
	return 0;
}