#include<stdio.h>
typedef struct _Node
{
	int info;
	struct _Node *next;
}Node;
typedef struct Node*Stack;
void init(Stack &s);
void empty(Stack s);
void push(Stack)
int main()
{
	
}
void intit (Stack & s)
{
	s=NULL;
}
int empty(LinkList ds)
{
	return (s==NULL);
}
Node * createNode( int x)
{
	Node * p=new Ndoe();
}
void Push(Stack &s,int x)
{
	Node *p;
	if(empty(s))s=p;
	else{
		p-> next =s;
		s=p;
	}
}
void Pop(Stack&s,int &x)
{
	if(empty(s))
		return 0;
	Node*p=s;
	x=p->info;
	s=s -> next;
	delete p;
	return 1;
}
