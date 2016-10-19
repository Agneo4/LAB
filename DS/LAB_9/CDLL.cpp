#include <iostream>

using namespace std;

class CDLL{
    int data;
    CDLL *llink, *rlink;
    
public:
    CDLL();
    static CDLL* create();
    CDLL* insert(CDLL*);
    CDLL* remove(CDLL*);
    void show(CDLL*);
    ~CDLL();
};

CDLL::CDLL(){
    data=0;
    llink=rlink=NULL;
}

CDLL* CDLL::create(){
    CDLL *head=new CDLL();
    cout<<"\nEnter the value : ";cin>>head->data;
    head->llink=head;
    head->rlink=head;
    
    return head;
}


CDLL* CDLL::insert(CDLL *head){
    CDLL *node=new CDLL();
    cout<<"\nEnter the value : ";cin>>node->data;
    CDLL *n=head->llink;
    n->rlink=node;
    n->rlink->rlink=head;
    n->rlink->llink=n;
    head->llink=n->rlink;

    return head;
}

CDLL* CDLL::remove(CDLL *head){
    int c;
    cout<<"\nEnter the value you want to remove : ";cin>>c;
    CDLL *node=head;    int f=0;
    while(node!=head || f==0){
        if(node->data==c){
            CDLL *temp=node;
            node=node->rlink;
            node->llink=temp->llink;
            node->llink->rlink=node;
            cout<<"\nDeleted data : "<<temp->data<<endl;
            delete temp;
            return head;
        }
        node=node->rlink;
        if(node==head)  f=1;
    }
    cout<<"\nElement not found."<<endl;
    return head;
}

void CDLL::show(CDLL *head){
    CDLL *node=head;    int f=0;
    while(node!=head || f==0){
        cout<<node->data<<'\t';
        node=node->rlink;
        if(node==head)  f=1;
    }
}

CDLL::~CDLL(){
}

int main()
{
    CDLL *head=CDLL::create();
    head->show(head);
    head->insert(head);
    head->insert(head);
    head->insert(head);
    head->insert(head);
    int o=0;
    do{
        cout<<"\nChoose\n\n1. Insert\n2. Delete\n3. Show\n4. Exit"<<endl;
        cin>>o;
        if(o==1)    head->insert(head);
        else if(o==2)   head->remove(head);
        else if(o==3)   head->show(head);
    }while(o!=4);
        
    return 0;
}