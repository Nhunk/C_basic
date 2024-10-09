#include <stdio.h>

struct node
{
    int data;
    node *left, *right;
};

node *TaoNode(int a);
void Chen(node *p, node *&T);
void TaoBST(int a[], int n, node *&T);
void LNR(node *T);
node *TimMin(node *T);
node *XoaNode(node *T, int x);

int main()
{
    int n = 11, a[n] = {44, 18, 88, 13, 37, 59, 108, 15, 23, 55, 71};
    node *T = NULL;

    // Tạo cây nhị phân từ dãy số
    TaoBST(a, n, T);
    // Duyệt cây nhị phân trung tự LNR(Left-Node-Right)
    LNR(T);

    // Xóa node có giá trị 37
    T = XoaNode(T, 37);
    printf("\nCay sau khi xoa: \n");
    LNR(T);
    return 0;
}
node *TaoNode(int a)
{
    node *p = new node;
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void Chen(node *p, node *&T)
{
    if (T == NULL)
        T = p;
    else if (p->data < T->data)
        Chen(p, T->left);
    else
        Chen(p, T->right);
}
void TaoBST(int a[], int n, node *&T)
{
    for (int i = 0; i < n; i++)
        Chen(TaoNode(a[i]), T);
}
void LNR(node *T)
{
    if (T != NULL)
    {
        LNR(T->left);
        printf("%5d", T->data);
        LNR(T->right);
    }
}
node *TimMin(node *T)
{
    while (T->left != NULL)
    {
        T = T->left;
    }
    return T;
}
node *XoaNode(node *T, int x)
{
    if (T == NULL)
        return T;
    if (x < T->data)
        T->left = XoaNode(T->left, x);
    else if (x > T->data)
        T->right = XoaNode(T->right, x);
    else // Đã tìm thấy: x=T->data
    { 
        // Trường hợp node cần xóa là node lá hoặc node có 1 con
        node *p = new node;
        if (T->left == NULL)
        {
            p = T->right;
            delete T;
            return p;
        }
        else if (T->right == NULL)
        {
            p = T->left;
            delete T;
            return p;
        }
        // Trường hợp node có 2 con
        p = TimMin(T->right);
        T->data = p->data;
        T->right = XoaNode(T->right, p->data);
    }
    return T;
}