#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Sach
{
	int masach;
	char tensach[40];
	float gia;
}book;
void Nhapn (int &n)
{
	do
	{
		printf("nhap vao  so luong sach:");
		scanf("%d",&n);
		if(n<0||n>100)
			printf("nhap vao so luong sach sai \n");
	}while(n<0||n>100);
}
void Nhap1sach (book &a)
{
	printf("\nnhap ten cuon sach :");
	fflush(stdin);
	gets(a.tensach);
	printf("\nnhap ma cuon sach :");
	scanf("%d",&a.masach);
	printf("\nnhap gia cuon sach :");
	scanf("%f",&a.gia);
}
void Xuat1sach (book a)
{	
		printf("\nten sach: %s",a.tensach);
		printf("\nma sach :%d ",a.masach);
		printf("\ngia sach :%f ",a.gia); 
	
}
void Nhapdanhsach (book a[],int n)
{	
	
	for( int i=0;i<n;i++)
		{
			printf("\nsach thu %d:",i+1);
			Nhap1sach(a[i]);
		}
		
}
void Xuatdanhsach (book a[],int n)
{
		for(int i=0;i<n;i++)
		{
			printf("\nsach thu %d:",i+1);
			Xuat1sach(a[i]);
		}
}
void Timkiemtuyentinh(book a[], int n, int x)
{
	for (int i = 0; i < n;i++)
		if (a[i].masach == x)
			Xuat1sach(a[i]);
	
} 
void sapxepmasach(book a[], int n) 
{	book temp;
   for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
		{
            if(a[i].masach > a[j].masach)
			{
				temp = a[i];
                a[i] = a[j];
                a[j] = temp;    
			}
		}
}
int BinarySearch(book a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid].masach == x)
            return mid; 
        if (a[mid].masach > x)
            right = mid - 1; 
        else if (a[mid].masach < x)
            left = mid + 1; 
            
    }
    return -1; 
}
void TimsachY (book a[],int n,book Y)
{	
	for(int i=0;i<n;i++)
	
	{
		if(strcmp(a[i].tensach,Y.tensach )==0)
			{
				Xuat1sach(a[i]);
			}
		
	}
}
void Sachgiacaonhat(book a[],int n)
{
	float max=a[0].gia;
	for(int i=1;i<n;i++)
		if(a[i].gia>max)
			max=a[i].gia;
	printf("\nNhung cuon sach co gia cao nhat:\n");
	for(int i=0;i<n;i++)
		if(a[i].gia==max)
			Xuat1sach(a[i]);	
}
void themsach(book a[], int &n, int k)
{
    n++;int H;
    int i;
    for (i = n; i > k; i--)
    {
        a[i] = a[i - 1];
        H=i;
    }
    Nhap1sach(a[H]);
}

void SLsachtrengia (book a[] ,int n,float G)
{	int d=0;
	for(int i=0;i<n;i++)
		if( a[i].gia > G)	
			d++;
	printf("SL sach co gia lon hon Y:%d",d);		
	
}
int main ()
{
	book a[100];
	int n,x;book Y;int k;float G;
	Nhapn(n);
	Nhapdanhsach(a,n);
	Xuatdanhsach(a,n);

	printf("_____________________________________________________");
	printf("\nnhap ma sach can tim : ");
	scanf("%d",&x);
	printf("tim kiem ma sach tuyen tinh: \n");
	Timkiemtuyentinh(a,n,x);
	printf("\nma sach sau khi sap xep:");
	sapxepmasach(a,n);
	Xuatdanhsach(a,n);	
	printf("tim kiem ma sach binary: \n");
	int B=BinarySearch(a,n,x);
	if (B == -1)
		printf("\nkhong co sach");
	else
		Xuat1sach(a[B]);
	printf("_____________________________________________________");	
	printf("\nnhap ten sach can tim : ");
	scanf("%s",&Y.tensach);	
	TimsachY(a,n,Y);
	printf("_____________________________________________________");
	Sachgiacaonhat(a,n);
	printf("_____________________________________________________");
	printf("nhap vi tri can chen:");
	scanf("%d",&k);
	themsach	(a,n,k);
	Xuatdanhsach(a,n);
	printf("_____________________________________________________");
	printf("\nnhap giá  can tim sach co gia lon hon: ");
	scanf("%f",&G);
	SLsachtrengia(a,n,G);
	
	
	return 0;
}