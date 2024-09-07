#include <stdio.h>

void NhapA(int a[], int &n);
void InA(int a[], int n);
void NhapM(int m[], int &d, int &c);
void InM(int m[], int d, int c);

int main()
{
    int a[100], n;
    int m[100], d, c;
    printf("Cau 1: \n");
    NhapA(a, n); 
    InA(a, n);
    printf("\nCau 2:\n");
    NhapM(m, d, c);
    InM(m, d, c);
}
void NhapA(int a[], int &n)
{
    printf("Nhap n phan tu array: ");
    scanf("%d", &n);              
    for (int i = 0; i < n; i++) 
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
}
void InA(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%5d", a[i]);
}
void NhapM(int m[], int &d, int &c)
{
    printf("Nhap so dong cua ma tran: ");
    scanf("%d", &d);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &c);
    for (int i = 0; i < d; i++)
        for (int j = 0; j < c; j++)
        {
            printf("M[%d, %d]=", i, j);
            scanf("%d", &m[j * d + i]);
        }
}
void InM(int m[], int d, int c)
{
    printf("Ma tran la: \n");
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%5d", m[j * d + i]);
        printf("\n");
    }
}
