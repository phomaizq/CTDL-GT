#include <stdio.h>
struct Node {
	int info;
	Node *left ,*right;
};
void init(Node *&ptree);
void empty(Node *&ptree);
Node * createNode(int x);
void insertLeft(Ndoe *&ptree,int x);
void insertRight(Node * &ptree,int x);
void insert(Node *&ptree ,int x);


void init (Node *&ptree)
{
	ptree==NULL;
}
void empty(Node *ptree)
{
	return ptree == NULL;
}
Node * createNdoe(int x)
{
	Ndoe *p=new node;
	if (p==NULL)
		return 0;
	p->info =x;
	p->left =NULL;
	p->right =NULL;
	return p;	
}
void insertLeft(Ndoe *&ptree,int x)
{
	if(ptree ==NULL) return ;
	if(ptree -> left  !=NULL) return ;
	ptree -> left =createNode(x);
}
void insertRight(Ndoe *&ptree)
{
	if(ptree ==NULL) return ;
	if(ptree -> right  !=NULL) return ;
	ptree -> right =createNode(x);	
}
void XuatLNR(Ndoe *ptree)
{
	if(ptree ==NULL)  return ;
	XuatLNR(ptree -> left );
	printf("&d",ptree ->info);
	XuatLNR(ptree -> right );
}
void XuatLRN(Node * ptree)





