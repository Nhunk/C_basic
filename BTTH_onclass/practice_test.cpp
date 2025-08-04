#include <stdio.h>

struct node
{
    int data;
    node *left, *right;
};

node *TaoNode(int ai);
void Chen(node *p, node *&T);
void TaoBST(int a[], int n, node *&T);
void LRN(node *T);
int DEM(node *T);
node *XoaLa(node *&T);
int ChieuCao(node *T);
int main()
{
    int n = 9, a[n] = {6, 2, 4, 9, 8, 1, 3, 7, 10};
    node *T = NULL;
    TaoBST(a, n, T);
    LRN(T);
    printf("\nChieu cao cua BST la : %d", ChieuCao(T));
    // printf("\nDem so node con: %5d\n", DEM(T));
    
    // T = XoaLa(T);
    // printf("Cay sau khi xoa node la: ");
    // LRN(T);
    // return 0;
}

node *TaoNode(int ai)
{
    node *p = new node;
    p->data = ai;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void Chen(node *p, node *&T)
{
    if (T == NULL)
        T = p;
    else if (p->data < T->data)
    {
        Chen(p, T->left);
    }
    else
    {
        Chen(p, T->right);
    }
}

void TaoBST(int a[], int n, node *&T)
{
    for (int i = 0; i < n; i++)
        Chen(TaoNode(a[i]), T);
}

void LRN(node *T)
{
    if (T != NULL)
    {
        LRN(T->left);
        LRN(T->right);
        printf("%5d", T->data);
    }
}

int DEM(node *T)
{
    if (T == NULL)
        return 0;
    if ((T->left == NULL && T->right != NULL) || (T->left != NULL && T->right == NULL))
    {
        return 1 + DEM(T->left) + DEM(T->right);
    }
    else
    {
        return DEM(T->left) + DEM(T->right);
    }
}

node *XoaLa(node *&T)
{
    if (T == NULL)
        return NULL;
    T->left = XoaLa(T->left);
    T->right = XoaLa(T->right);
    if (T->left == NULL && T->right == NULL)
    {
        delete T;
        return NULL;
    }
    return T;
}
int ChieuCao(node *T) {
    if (T == NULL) {
        return 0; 
    } else {
        int chieuCaoTrai = ChieuCao(T->left);
        int chieuCaoPhai = ChieuCao(T->right);

        return (chieuCaoTrai > chieuCaoPhai) ? (chieuCaoTrai + 1) : (chieuCaoPhai + 1);
    }
}