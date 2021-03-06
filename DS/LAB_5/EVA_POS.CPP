#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAX 100

class postfix
{
	int stack[MAX], value[26];
	int top, res;
	char *s;
	
	public :
		
	postfix()
	{
		top = -1;
	}

	void setexpr (char *str, int *v)
	{
		s = str;
		value=v;
	}

	void push (int item)
	{
		if (top == MAX - 1)
			cout <<"\nStack is full";
		else
			stack[++top] = item;
	}

	int pop()
	{
		if (top == -1)
		{
			cout <<"\nStack is empty";
			return NULL;
		}
		return stack[top--];
	}

	void calculate()
	{
		int n1, n2, n3;
		while (*s)
		{
			if (*s == ' '  ||  *s == '\t')
			{
				s++;
				continue;
			}
			if (isalpha(*s))
				push(value[*s - 97];
				
			else
			{
				n1 = pop();
				n2 = pop();
				switch (*s)
				{
					case '+' :	n3 = n2 + n1;
								break;
					case '-' :	n3 = n2 - n1;
								break;
					case '/' :	n3 = n2 / n1;
								break;
					case '*' :	n3 = n2 * n1;
								break;
					case '%' :	n3 = n2 % n1;
								break;
				}
	 
				push (n3);
			}
			s++;
		}
	}
	void show()
	{
		res = pop ();
		cout <<"\nResult is: "<<res<<'\n';
	}
};
 
void main()
{
	char expr[MAX];
	int val[26]={NULL};
	cout << "\nEnter postfix expression to be evaluated : ";
	gets(expr);
	for(int i=0; i<=strlen(str); i++)
	{
		if(val[str[i]-97]!=NULL)
			cout<<"Enter value of str[i] : ";cin>>val[str[i]-97];
	}
	postfix q;
	q.setexpr (expr, val);
	q.calculate();
	q.show();
}
