#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct _Node{
	int info;
	struct _Node * next;
}Node;
typedef struct _LinkList
{
	Node * phead,*ptail;
	
}LinkList;
void init( LinkList &ds);
int empty(LinkList ds);
void nhapDs( LinkList &ds);
void xuatDs(LinkList ds);
void insertFirst( LinkList &ds,int x);
void insertLast( LinkList &ds,int x);
void insertAfter( LinkList &ds,Node*p, int x);
Node*createNode(int x);
Node*search(LinkList ds,int y);
void selectionsort(LinkList ds);
void Swap(int &a,int &b);
void deleteX(LinkList ds);
void deleteFirst(LinkList &ds);
void deleteAfter(LinkList &ds ,Node *p);
void deleteAll(LinkList &ds);

void init(LinkList &ds)
{
	ds.phead=NULL;
}
int empty(LinkList ds)
{
	return ds.phead==NULL;
}
Node* creatNode(int x)
{
	Node* p=new Node();
	p->info=x;
	p->next=NULL;
	return p;
}

/*void deleteAll(LinkList ds)
{
	while(!empty(ds))
		deleteFirst(ds);
}*/
void deleteAfter(LinkList &ds,Node*p)
{
	if(p==NULL && p->next ==NULL) return ;
	Node *q;
	q=p->next;
	if(q==ds.ptail) ds.ptail=p;
	p->next =q ->next;
	delete q;
}
void deleteFirst(LinkList &ds)
{
	if(empty(ds)) return ;
	Node *p;
	p=ds.phead;
	ds.phead=ds.phead->next;
	delete p;
	if(empty(ds)) ds.ptail=NULL;
}
void deleteX(LinkList ds)
{
	printf ("\nnhap vi tri X muon xoa: ");
	int x;
	scanf("%d",&x);
	Node* p=ds.phead;
	Node* q=p;
	while(q!=NULL && q->info!=x)
	{
		p=q;
		q=p->next;
	}
	if(q==NULL) return ;
	if(q==ds.phead) deleteFirst(ds);
 
}
void Swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
void selectionsort(LinkList ds)
{
	for(Node *i=ds.phead;i!=NULL;i=i->next)
	{
		Node*min =i;
		for(Node*j=i->next;j!=NULL;j=j->next)
			if(j->info<min->info)
			min =j;
		Swap(i->info,min->info);
	}
}

void insertFirst(LinkList &ds,int x)
{
	Node *p=creatNode(x);
	if(empty(ds))
	{
		ds.phead=ds.phead=p;
		return ;
	}
	p->next=ds.phead;
	ds.phead=p;
}

void insertLast(LinkList &ds,int x)
{
	Node *p=creatNode(x);
	if(empty(ds))
	{
		ds.phead=ds.ptail=p;
		return ;
	}
	ds.ptail->next=p;
	ds.ptail=p;
}
void insertAfter(LinkList &ds,Node *p,int x)
{
	if(p==NULL) return ;
	Node*q=creatNode(x);
	if(ds.ptail==p)
		ds.ptail=q;
	q-> next=p ->next;
	p->next=q;
	
}
Node*search(LinkList ds,int y)
{
	for(Node *i=ds.phead;i!=NULL;i=i->next)
		if(i->info==y) return i;
	return NULL;
}
void nhapDs(LinkList &ds)
{
	printf ("nhap vao so phan tu :");
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf(" nhap phan tu thu %d : ",i);
		int x;
		scanf("%d",&x);
		printf("\n ban thch chen dau hay cuoi mot day so: 0 /1 /2 :");
		int dc;
		scanf("%d",&dc);
		if(dc==0)
			insertFirst(ds,x);
		else
		if(dc==1)
			insertLast(ds,x);
		else
		if(dc==2)
		{
			printf(" \n bann muon chen so nào :");
			int y;
			scanf("%d",&y);
			Node *p=search(ds ,y);
			insertAfter(ds,p,x);
		}
	}
}
void xuatDs(LinkList ds)
{
	printf("\n day so la :");
	for (Node *i=ds.phead;i!=NULL;i=i->next)
		printf("%d",i->info);
}
int main ()
{
	LinkList ds;
	init(ds);
	nhapDs(ds);
	xuatDs(ds);
	selectionsort(ds);
	xuatDs(ds);
	deleteX(ds);
	xuatDs(ds);
//	deleteAll(ds);
	xuatDs(ds);
	deleteX(ds);
	xuatDs(ds);
	return 0;
}



















