#include <stdio.h>

struct node
{
    int data;
    node *next;
};
void XUAT(node *L);
void NHAP1(node *&L, int n);
node *NHAP2(int n);
void NHAP3(node *&L, int n);
void XOA(node *&L, int &k);

int main()
{
    int k;
    node *L = NULL;
    // NHAP1(L,5);
    //  node *L1 = NHAP2(5);
    //  XUAT(L1);
    NHAP3(L, 5);
    XOA(L, k);
}
void XUAT(node *L)
{
    for (node *q = L; q != NULL; q = q->next)
    {
        printf("%5d", q->data);
    }
}
// Nhập danh sách liên kết đơn chèn sau
void NHAP1(node *&L, int n)
{
    node *p, *q;
    for (int i = 1; i <= n; i++)
    {
        p = new node;
        printf("Nhap so %d: ", i);
        scanf("%d", &p->data);
        p->next = NULL;
        if (L == NULL)
            L = p;
        else
            q->next = p;
        q = p;
    }
    XUAT(L);
}
// Nhập danh sách liên kết đơn chèn sau bằng hàm return
node *NHAP2(int n)
{
    node *L1 = NULL, *p, *q = NULL;
    for (int i = 1; i <= n; i++)
    {
        p = new node;
        printf("Nhap so %d: ", i);
        scanf("%d", &p->data);
        p->next = NULL;
        if (L1 == NULL)
            L1 = p;
        else
            q->next = p;
        q = p;
    }
    return L1;
}
// Nhập danh sách liên kết đơn(chèn đầu)
void NHAP3(node *&L, int n)
{
    node *p;
    for (int i = 1; i <= n; i++)
    {
        p = new node;
        printf("Nhap so %d: ", i);
        scanf("%d", &p->data);
        p->next = L;
        L = p;
    }
    XUAT(L);
}
// Xóa phần tử trong danh sách liên kết đơn
void XOA(node *&L, int &k)
{
    printf("\nNhap gia tri can xoa: ");
    scanf("%d", &k);
    if (L == NULL)
    {
        printf("Danh sách rong!");
        return;
    }
    node *p = L;
    node *r = NULL;
    if (L->data == k)
    {
        L = L->next;
        delete p;
        return;
    }
    while (p != NULL && p->data != k)
    {
        r = p;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Khong tim thay gia tri %d trong danh sach!", k);
        return;
    }
    r->next = p->next;
    delete p;
    printf("Danh sau khi xoa la: ");
    XUAT(L);
}
