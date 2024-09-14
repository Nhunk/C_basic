#include <stdio.h>

void Xuatmang(int a[], int n);
void HoanVi(int *a, int *b); // Sử dụng con trỏ để hoán vị
void SelectionSort(int a[], int n);
void QuickSort(int a[], int l, int r);

int main()
{
    int a[] = {23, 17, 88, 9, 53, 45, 95, 67, 11, 3, 1};
    int b[] = {23, 17, 88, 9, 53, 45, 95, 67, 11, 3, 1};
    int n = 11;

    // In mảng ban đầu
    printf("Mang ban dau:\n");
    Xuatmang(a, n);

    // Câu 1: Sắp xếp chọn
    printf("\n\nCau 1: Sap xep chon:\n");
    SelectionSort(a, n);
    Xuatmang(a, n);

    // Câu 2: Sắp xếp nhanh
    printf("\n\nCau 2: Sap xep nhanh:\n");
    QuickSort(b, 0, n - 1);
    Xuatmang(b, n);

    return 0;
}
void Xuatmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
}
void HoanVi(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                HoanVi(&a[i], &a[j]); // Hoán vị bằng con trỏ
            }
        }
    }
}
void QuickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int pivot = a[l]; // Chọn phần tử đầu tiên làm pivot
    int i = l + 1;
    int j = r;
    while (i <= j)
    {
        while (i <= r && a[i] < pivot)
            i++;
        while (j >= l && a[j] > pivot)
            j--;

        if (i < j)
        {
            HoanVi(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    HoanVi(&a[l], &a[j]);
    QuickSort(a, l, j - 1); // Đệ quy bên trái
    QuickSort(a, j + 1, r); // Đệ quy bên phải
}