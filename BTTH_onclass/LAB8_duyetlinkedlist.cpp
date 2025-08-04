#include <stdio.h>

struct node
{
    int data;
    node *next;
};

void Nhap1L(node *&L, int n);
void Nhap2L(node *&L, int n);
void InL(node *L);

int main()
{
    node *L = NULL;
    node *L1 = NULL;
    Nhap1L(L, 5);
    Nhap2L(L1, 5);
}

//Hàm xuất linkedlist ra màn hình
void InL(node *L)
{
    for (node *q = L; q != NULL; q = q->next)
        printf("%5d", q->data);
}

//Hàm nhập vào linkedlist theo chiều xuôi (Chèn sau)
void Nhap1L(node *&L, int n)
{
    printf("Nhap LINKEDLIST theo nhap xuoi: \n");
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
    InL(L);
}

//Hàm nhập vào Linkedlist theo chiều ngược (Chèn đầu)
void Nhap2L(node *&L, int n)
{
    printf("\nNhap LINKEDLIST theo nhap nguoc: \n");
    node *p;
    for (int i = 1; i <= n; i++)
    {
        p = new node;
        printf("Nhap so %d: ", i);
        scanf("%d", &p->data);
        p->next = L;
        L = p;
    }
    InL(L);
}