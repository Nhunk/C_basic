#include <stdio.h>

struct node
{
    int info;
    node *link;
};

void XUAT(node *L);
node *TAO(int value, node *next);
void DEM(node *L, int &X);
void XOA(node *&L);

int main()
{
    int X;
    node *L = NULL;
    L = TAO(1, TAO(2, TAO(3, TAO(4, NULL))));
    printf("Danh sach vua tao la: ");
    XUAT(L);
    DEM(L, X);
    XOA(L);
    return 0;
}

// Hàm xuất in ra danh sach liên kết L
void XUAT(node *L)
{
    printf("L-");
    node *q = L;
    while (q != NULL) {
        printf("%d-", q->info);
        q = q->link;
    }
    printf("NULL");
}

// Hàm tạo danh sách liên kết đơn
node *TAO(int value, node *next)
{
    node *newnode = new node;
    newnode->info = value;
    newnode->link = next;
    return newnode;
}

// Hàm đếm số giá trị nhỏ hơn X trong danh sách
void DEM(node *L, int &X)
{
    int count = 0;
    printf("\nNhap gia tri can dem so nho hon: ");
    scanf("%d", &X);
    for (node *q = L; q != NULL; q = q->link)
    {
        if (q->info < X)
        {
            count++;
        }
    }
    printf("Co %d gia tri nho hon %d trong danh sach.", count, X);
}

// Hàm xóa node ở cuối danh sách
void XOA(node *&L)
{
    if (L == NULL)
    {
        printf("Danh sach rong! Khong the xoa.");
        return;
    }
    if (L->link == NULL)
    {
        delete L;
        L = NULL;
        return;
    }
    node *q = L;
    while (q->link->link != NULL)
    {
        q = q->link;
    }
    delete q->link;
    q->link = NULL;
    printf("\nDanh sach sau khi xoa node cuoi la: ");
    XUAT(L);
}