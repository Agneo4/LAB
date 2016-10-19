#include <iostream>
#include <stdio.h>

using namespace std;

class CLL{
    int co, exp;
    CLL *next;

public:
    CLL(){
        co=exp=0;
        next=NULL;
    }
    CLL* enter(CLL*);
    CLL* add(CLL*, CLL*);
    void show(CLL*);
};

CLL* CLL::enter(CLL* p){
    cout<<"\nEnter the value in decreasing exponents. give -999 to stop;\n";
    do{
        CLL *node=new CLL();
        cout<<"\nEnter exponent : ";cin>>node->exp;
        if(node->exp == -999)	break;
        cout<<"\nEnter coefficient : ";cin>>node->co;
        if(node->co == 0)	continue;
        if(p==NULL){
            p=node;
            p->next=p;
        }
        else{
            CLL *n=p;
            cout<<p->co<<p->exp<<endl;
            while(n->next!=p)
                n=n->next;
            
            n->next=node;
            n->next->next=p;
        }
    }while(1);
    return p;
}

CLL* CLL::add(CLL *p1, CLL *p2){
    if(p1==NULL)	return p2;
    else if(p2==NULL)	return p1;

    CLL *total=NULL, *x=p1, *y=p2;
    int f1, f2; f1=f2=0;
    while(x!=p1 || y!=p2 && f1==0 && f2==0)
    {
        CLL *n=new CLL;

        if(x->exp == y->exp){
            n->co = x->co + y->co;
            n->exp = x->exp;
            x=x->next;	y=y->next;
        }
        else if(x->exp > y->exp){
            n->co = x->co;
            n->exp = x->exp;
            x=x->next;
        }
        else if(x->exp < y->exp){
            n->co = y->co;
            n->exp = y->exp;
            y=y->next;
        }
        if(x==p1)   f1=1;
        if(y==p2)   f2=1;
        if(total==NULL){
            total=n;
            total->next=total;
        }
        else{
            CLL *node=total;
            while(node->next!=total)
                node=node->next;
            node->next=n;
            node->next->next=total;
        }
    }
    if(f1==1 && f2==0){
        total->next=x;
        CLL *node=total;
        while(node->next!=total)
            node=node->next;
        node->next=total;        
    }
    if(f1==0 && f2==1){
        total->next=y;
        CLL *node=total;
        while(node->next!=total)
            node=node->next;
        node->next=total;        
    }
    return total;    
}

void CLL::show(CLL *p)
{
    CLL *node=p;
    cout<<node->co<<"x^"<<node->exp;
    node=node->next;
    while(node!=p){
        cout<<" + "<<node->co<<"x^"<<node->exp;
        node=node->next;
    }
}

int main(){
        
    CLL *f=new CLL(), *p1=NULL, *p2=NULL;
    p1=f->enter(p1);
    f->show(p1);

    p2=f->enter(p2);
    f->show(p2);

    CLL *tot=f->add(p1, p2);
    f->show(tot);

    return 0;
}