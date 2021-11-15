#include<stdio.h>
#include<string.h>
template<class T>
struct Node
{
	T info;
	struct Node* next;
};
template <class T>
void init(Node <T> *&s);
template <class T>
void empty(Node <T> *s);
template <class T>
void push(Node<T> * &s,T x);
template <class T>
void pop (Node <T> *&s,T &x);
template <class T>
void top(Node <T> *s,T&x);
template <class T>
Node <T> * crateNode(T x);
char *hauto(char *s);
int laToantu(char c);
int doUutien(char c);
int laToanHang(char c);
float tinhHauTo(char *s);
float doiso(char c);
float thuHienPhepToan(float a,float b,float c);

