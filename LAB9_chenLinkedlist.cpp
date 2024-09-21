#include <stdio.h>

struct node
{
    int data;
    node *next;
};

void Xuat(node *L);
void Nhap(node *&L, int n);
void Chen1L(node *&L, int &x, int &k);
void Chen2L(node *&L, int x);

int main()
{
    node *L = NULL;
    int x, k;
    Nhap(L, 5);
    // Câu 1: Chèn một số x vào vị trí k trong LINKEDLIST
    Chen1L(L, x, k);
    // Câu 2: Chèn số x vào LINKEDLIST theo thứ tự tăng dần
    printf("\nNhap so can chen vao danh sach theo thu tu tang dan: ");
    scanf("%d", &x);
    Chen2L(L, x);
}
void Xuat(node *L)
{
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
            L = p;
        else
            q->next = p;
        q = p;
    }
    printf("Danh sach ban dau: \n");
    Xuat(L);
}
void Chen1L(node *&L, int &x, int &k)
{
    printf("\nNhap so can chen: ");
    scanf("%d", &x);
    printf("Nhap vi tri muon chen: ");
    scanf("%d", &k);
    node *p = new node;
    p->data = x;
    // Kiểm tra vị trí hợp lệ
    int length = 0;
    node *temp = L;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    if (k < 0 || k > length)
    {
        printf("\nVi tri khong hop le!\n");
        delete p;
        return;
    }

    // Chèn vào đầu danh sách
    if (k == 0)
    {
        p->next = L;
        L = p;
    }
    else
    {
        node *q = L;
        int count = 0;
        while (q != NULL && count < k - 1)
        {
            q = q->next;
            count++;
        }
        // Chèn vào vị trí k
        p->next = q->next;
        q->next = p;
    }
    printf("Danh sach sau chen: \n");
    Xuat(L);
}
void Chen2L(node *&L, int x)
{
    node *p = new node;
    p->data = x;
    p->next = NULL;
    if (L == NULL || L->data >= x)
    {
        p->next = L;
        L = p;
        return;
    }
    node *q = L;
    while (q->next != NULL && q->next->data < x)
        q = q->next;
    p->next = q->next;
    q->next = p;
    printf("SDanh sach sau chen 2: ");
    Xuat(L);
}