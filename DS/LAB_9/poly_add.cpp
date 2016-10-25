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

CLL* CLL::add(CLL *a, CLL *b){
    CLL *startA, *c, *lastC;
    int done=0;
    startA=a;	a=a->next;	b=b->next;
    c=new CLL();	c->exp=-1;	lastC=b->co;
    do{
    	if(a->exp<b-<exp){
    		c->next=new CLL();		c=c->next;
    		c->co=b->co;	c->exp=b->exp;
    		b=b->next;
    	}
    	else if(a->exp==b->exp){
    		if(startA==a)	done=1;
    		elseif(a->co + b->co !=0 ){
    			c->next=new CLL();	c=c->next;
    			c->co = a->co + b->co;
    			c->exp = a->exp;
    			a = a->next;	b = b->next;
    		}
    	}
    	else{
    		c->next=new CLL();	c=c->next;
    		c->co=a->co;	c->exp=a->exp;
    		a=a->next;
    	}
    }while(!done);
    c->next=lastC;c=c->next;
    return c;
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