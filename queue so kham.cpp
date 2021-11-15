#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
struct SoKham
{
	int stt;
	char ten[30];
	int tuoi;
};
template <class T>
struct Node
{
	T info;
	Node<T> *next;
};
template <class T>
struct Queue
{
	Node <T> *phead,*ptail;
};
template <class T>
Node <T> *createNode( T x);

template <class T>
void init ( Queue <T> &q);

template <class T>
int empty ( Queue<T> &q);

template <class T>
void Insert(Queue <T> &q,T &x);

template <class T>
void remove(Queue<T> &q,T&x);

template <class T>
void QueueFirst(Queue <T> q, T&x);

template <class T>
void QueueLats(Queue<T> q,T & x);

template <class T>
int QueueSize(Queue<T> q);

void nhap (SoKham &x);
void xuat (SoKham y);
int main()
{
	Queue<SoKham> q;
	init (q);
	int d=0;
	do {
		printf("\n 0: thoat ");
		printf("\n 1: Dang ki de kham ");
		printf("\n 2: xem nguoi kham tiep theo ");
		printf("\n 3: xem nguoi chua kham ");
		printf("\n 4: xem nguoi da duoc kham ");
		int chon;
		printf("\n vui long chon (0-->4)");
		scanf("%d",&chon);
		if(chon==0) return 0;
		if(chon==1)
		{
			SoKham x;
			nhap(x);
			//Insert (q,x);
			printf("\n Dang khi kham xong ");
		}else
		if (chon==2)
		{
			SoKham y;
			remove(q,y);
			printf("\n thong tin nguoi kham tiep theo ");
			xuat (y);
			d++;
		}else
		if(chon==3 )
		{
			printf("\n so nguoi da kham %d : ",QueueSize(q));
		}else
		{
			printf("\n so nguoi da kham la %d ",d);
		}
	}while(1);
	return 0;
}
void nhap(SoKham &x)
{
	printf("\n nhap stt ");
	scanf("%d",&x.stt);
	printf("\n nhap tên ");
	fflush(stdin);
	gets(x.ten);
	printf("\n nhap tuoi ");
	scanf("%d",&x.tuoi);
}

void xuat (SoKham y)
{
	printf("\n %d	\t %s	\t %d ",y.stt,y.ten,y.tuoi);
}

template <class T>

Node <T>*createNode(T x)
{
Node <T> *p=new Node <T> ();
p-> info =x;
p-> next =NULL;
return p;
}
template <class T>
void init (Queue <T> &q)
{
	q.phead=q.ptail=NULL;
}
template <class T>
int empty(Queue<T> q)
{
	return q.phead==NULL;
} 
template <class T>
/*void Insert ( Queue <T> &q, T x)
{
	Node <T> *p=createNode (x);
	if(empty (q)) 
	{
		q.phead=q.ptail=p;
		return ;
	}
	q.ptail->next=p;
	q.ptail=p;
}*/
//template <class T >
void remove (Queue <T> &q,T&x)
{
	
	x=q.phead->info;
	Node<T> *p;
	p=q.phead;
	q.phead=q.phead->next;
	delete p;
}
template <class T>
void QueueFirst(Queue <T> q,T&x)
{
	if(empty(q)) return ;
	x=q.phead ->info;
}
template <class T>
void QueueLast (Queue <T> q,T&x)
{
	if(empty (q)) return ;
	x=q.ptail ->info;
}
template <class T>
int QueueSize (Queue <T> q)
{
int n=0;
for (Node <T> *i=q.phead;i!=NULL;i=i->next)
	n++;
return n;	
}







