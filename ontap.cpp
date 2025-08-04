#include <stdio.h>
struct node{
    int data;
    node *next;
};
void Nhap(node *&L, int n);
void Xuat(node *L);
int timMax(node *L);
void sapXep(node *L);
int demNutLe(node *L);
int main(){
    node *L=NULL;
    Nhap(L, 3);
    Xuat(L);
    int max = timMax(L);
    printf("\nSo lon nhat trong danh sach la: %d", max);
    sapXep(L);
    printf("\nDanh sach sau sap xep la: \n");
    Xuat(L);
}
void Nhap(node *&L, int n){
    node *p, *q;
    for(int i = 0; i<n;i++){
        p=new node;
        printf("Nhap so %d: ", i);
        scanf("%d", &p->data);
        p->next = NULL;
        if(L==NULL) L=p;
        else q->next = p;
        q = p;
    }
}
void Xuat(node *L){
    for(node *p =L; p!=NULL; p=p->next)
        printf("%5d", p->data);
}
// int timMax(node *L){
//     if(L==NULL)return -1;
//     int max = L->data;
//     for(node *p=L; p!=NULL;p=p->next){
//         if(p->data >max)
//             max=p->data;
//     }
//     return max;
// }
int timMax(node *L){
    if(L==NULL)return -1;
    int max=timMax(L->next);
    if(L->next==NULL|| L->data>max)
        return L->data;
    return max;
}
void sapXep(node *L){
    if(L==NULL)return;
    for(node *p=L;p!=NULL;p=p->next){
        for(node*q=L;q->next!=NULL;q=q->next){
            if(q->data > q->next->data){
                int temp = q->data;
                q->data = q->next->data;
                q->next->data = temp;
            }
        }
    }
}