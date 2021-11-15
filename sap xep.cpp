#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
void nhapn(int n)
{
	printf("nhap vao so phan tu trong mnag :");
	scanf("%d",&n);
}
void nhapmang (int a[],int n)
{
	srand((int)time(0));
	for(int i=0;i<n;i++)
	{
		a[i]=rand()/100;
	}
}
void xuatmang(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%5d",a[i]);
	}
}
void Swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j - 1] < a[j])
                Swap(a[j], a[j - 1]);
}

void InterchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j < n; j++)
            if (a[i] < a[j])
                Swap(a[i], a[j]);
}

void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                Swap(a[min], a[i]);
    }
}

void InsertionSort(int a[], int n)
{
    int pos, x;
    for (int i = 1; i < n; i++)
    {
        x = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos] > x)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}
int main()
{
	int a[100];
	int n;
	printf("nhap vao so phan tu trong mang :");
	scanf("%d",&n);
	nhapmang(a,n);
	xuatmang(a,n);
	BubbleSort(a,n);
	printf("\nmang vua sap xep BubbleSort :\n");
	xuatmang(a,n);
	InterchangeSort(a,n);
	printf("\nmang vua sap xep InterchangeSor :\n");
	xuatmang(a,n);
	SelectionSort(a,n);
	printf("\nmang vua sap xep SelectionSort :\n");
	xuatmang(a,n);
	InsertionSort(a,n);
	printf("\nmang vua sap xep 	InsertionSort :\n");
	xuatmang(a,n);
	return 0;
}
