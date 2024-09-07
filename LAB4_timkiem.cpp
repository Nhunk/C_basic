#include <stdio.h>
void InMang(int a[], int n);
int TimTuanTu(int a[], int n, int x);
int TimNhiPhan(int a[], int n, int x);

int main()
{
    int a[] = {1, 4, 5, 6, 8, 12, 19, 48, 63, 77};
    int n=10, x;
    InMang(a, 10);
    printf("\nNhap x can tim: ");
    scanf("%d", &x);

    //Tìm kiếm tuần tự
    int tim_kiem1 = TimTuanTu(a, n, x);
    printf("Tim kiem tuan tu:  ");
    if (tim_kiem1 >= 0)
        printf("Vi tri cua %d la %d", x, tim_kiem1);
    else
        printf("Khong tim thay %d trong array", x);
    //Tìm kiếm nhị phân
    int tim_kiem2 = TimNhiPhan(a, n, x);
    printf("\nTim kiem nhi phan:  ");
    if (tim_kiem2 >= 0)
        printf("Vi tri cua %d la %d", x, tim_kiem2);
    else
        printf("Khong tim thay %d trong array", x);
}
void InMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%5d", a[i]);
}
int TimTuanTu(int a[], int n, int x)
{
    int vt = -1;
    for (int i = 0; i < n && vt == -1; i++)
        if (a[i] == x)
            vt = i;
    return vt;
}
int TimNhiPhan(int a[], int n, int x)
{
    int vt = -1, d = 0, c = n - 1, g;
    while (d <= c && vt == -1)
    {
        g = (d + c) / 2;
        if (x == a[g])
            vt = g;
        else if (x < a[g])
            c = g - 1;
        else
            d = g + 1;
    }
    return vt;
}