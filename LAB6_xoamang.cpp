#include <stdio.h>
void Xuatmang(int a[], int n);
void Xoa1A(int a[], int &n, int x);// Truyền n theo tham chiếu để khi n thay đổi trong hàm thì cũng không làm ảnh hưởng đến giá trị của n ban đầu
void Xoa2A(int a[], int &n, int x);
int main()
{
	int a[] = {4, 3, 9, 12, 91, 5, 64, 78, 3, 9, 12, 12, 11, 25};
	int n = 14, x;
	Xuatmang(a, n);
	printf("\nNhap x muon xoa: ");
	scanf("%d", &x);
	Xoa1A(a, n, x);
	Xoa2A(a, n, x);
}
void Xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%5d", a[i]);
	}
}
void Xoa1A(int a[], int &n, int x)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			for (int j = i; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
			k = 1;
			printf("Da xoa x dau tien trong mang!\n");
			Xuatmang(a, n);
			break;
		}
	}
	if (k == 0)
	{
		printf("Khong tim thay x!");
	}
}
void Xoa2A(int a[], int &n, int x)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			for (int j = i; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
			i--;
			k = 1;
		}
	}
	if (k == 1)
	{
		printf("\nDa xoa tat ca x trong mang!\n");
		Xuatmang(a, n);
	}
	else
		printf("\nKhong tim thay x!");
}