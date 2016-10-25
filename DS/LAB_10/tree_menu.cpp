#include <iostream>

using namespace std;

class BT{
	int data;
	BT* lchild, *rchild;

public:
	BT();
	void insert(BT**, int);
	void tr_inorder(BT*);
	void tr_preorder(BT*);
	void tr_postorder(BT*);
	int dis_parent(BT*, int);
	void depth(BT*);
	int disp_anc(BT*);
	int count_leaf(BT*);
	~BT();
};

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
			cout<<curr->data;
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
			cout<<curr->data;
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
			cout<<curr->data;
			curr=curr->rchild;
		}
		else while(curr!=NULL){
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

int BT::depth(BT *root) {
  if (!root) return 0;
  int left_height = depth(root->lchild);
  int right_height = depth(root->rchild);
  return (left_height > right_height) ? ++left_height : ++right_height;
}

BT::~BT(){
}

int main(){
	BT* root=NULL;

	int opt;
	do{
		cin>>o;
		if(o==1)if(o==1){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			root->insert(&root, a);
		}
		if(o==2)	root->tr_inorder(root);
		if(o==3)	root->tr_postorder(root);
		if(o==4)	root->tr_preorder(root);
		if(o==5){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			int x=root->dis_parent(root, a);
			if(!a)	cout<<"\nElement not found"<<endl;
		}
		if(o==6)	cout<<"Depth is : "<<root->depth(root)<<endl;
		if(o==7){
			int a;
			cout<<"\nEnter the Element : ";cin>>a;
			int x=root->disp_anc(root, a);
			if(!a)	cout<<"\nElement not found"<<endl;
		}
		if(o==8)	cout<<"\nNo of Leaf Nodes are : "<<root->count_leaf(root)<<endl;
	}while(o!=9);

	return 0;
}