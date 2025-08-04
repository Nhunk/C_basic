#include <stdio.h>
struct node
{
    int data;
    node *next;
};
struct myStack
{
    node *L;
};
void create(myStack &S);      // Khởi tạo danh sách liên kết đơn
int empty(myStack S);         // Check danh sách liên kết đơn có đang rỗng hay không
void push(myStack &S, int x); // Đưa vào
void top(myStack S, int &x);  // Lấy mà không xóa
void pop(myStack &S);         // Lấy và xóa

int main()
{
    myStack S;
    int x;
    create(S);
    push(S, 1);
    push(S, 2);
    push(S, 3);
    top(S, x);
    printf("\n x = %d", x);
    pop(S);
    top(S,x);
    printf("\n x = %d", x);
}
void create(myStack &S)
{
    S.L = NULL;
}
int empty(myStack S)
{
    return S.L == NULL;
}
void push(myStack &S, int x)
{
    node *p = new node;
    p->data = x;
    p->next = NULL;
    if (empty(S))
        S.L = p;
    else
    {
        node *q = S.L;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
void top(myStack S, int &x)
{
    if (!empty(S))
    {
        node *q = S.L;
        while (q->next != NULL)
        {
            q = q->next;
        }
        x = q->data;
    }
}
void pop(myStack &S)
{
    node *p;
    if (!empty(S))
    {
        if (S.L->next == NULL)
        {
            p = S.L;
            S.L = NULL;
        }
        else
        {
            node *q = S.L;
            while (q->next->next != NULL)
            {
                q = q->next;
            }
            p = q->next;
            q->next = NULL;
        }
        delete p;
    }
}