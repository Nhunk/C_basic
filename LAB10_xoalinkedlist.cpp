#include <stdio.h>

struct node
{
    int data;
    node *next;
};
void Xuat(node *L);
void Nhap(node *&L, int n);
void Xoa1L(node *&L, int x);
void Xoa2L(node *&L, int x);
int main()
{
    node *L = NULL;
    int x;
    Nhap(L, 1);
    printf("\nNhap gia tri can xoa: ");
    scanf("%d", &x);
    Xoa1L(L, x);
    Xoa2L(L, x);
}
void Xuat(node *L)
{
    if (L == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }
    for (node *q = L; q != NULL; q = q->next)
        printf("%5d", q->data);
}
void Nhap(node *&L, int n)
{
    printf("Nhap Linkedlist: \n");
    node *p, *q;
    for (int i = 1; i <= n; i++)
    {
        p = new node;
        printf("Nhap so %d: ", i);
        scanf("%d", &p->data);
        p->next = NULL;
        if (L == NULL)
        {
            L = p;
            q = L;
        }
        else
            q->next = p;
        q = p;
    }
    printf("Danh sach ban dau : \n");
    Xuat(L);
}
void Xoa1L(node *&L, int x)
{
    node *p, *q;
    // Phần tử cần xóa ở đầu danh sách
    if (L->data == x)
    {
        p = L;
        L = L->next;
        delete p;
        printf("Danh sach sau khi xoa %d dau tien: ", x);
        Xuat(L);
        return;
    }
    else
    {
        q = L;
        p = L->next;
        while (p != NULL && p->data != x)
        {
            q = p;
            p = p->next;
        }
        // Nếu tìm thấy phần tử có giá trị x
        if (p != NULL)
        {
            q->next = p->next;
            delete p;
            printf("Danh sach sau khi xoa %d dau tien: ", x);
            Xuat(L);
        }
        else
            printf("Khong tim thay %d trong danh sach!", x);
            return;
    }

}
void Xoa2L(node *&L, int x)
{
    node *p = L, *q;
    while (L != NULL && L->data == x)
    {
        node *t =L;
        L = L->next;
        delete t;
    }
    p = L;//Đặt lại con trỏ về đầu danh sách sau khi thực hiện xóa phần tử tìm được ở đầu
    bool found = 0;
    while (p != NULL && p->next != NULL)
    {
        if (p->next->data == x)
        {
            found = 1;
            q = p->next;
            p->next = p->next->next;
            delete q;
        }
        else
            p = p->next;
    }
    if(found){
        printf("\nDanh sach sau khi xoa ta ca %d: ", x);
        Xuat(L);
    }
}
