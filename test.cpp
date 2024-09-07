#include <stdio.h>

void Nhap(int a[], int &n);
void In(int a[], int n);
void Nhap_Matrix(int m[], int &d, int &c);
void In_Matrix(int m[], int d, int c);
int main(){
    int a[100], n;
    int m[100], d, c;
    Nhap(a,n);
    In(a,n);
    Nhap_Matrix(m, d, c);
    In_Matrix(m, d, c);
}
void Nhap(int a[], int &n){
    printf("Nhap n: ");
    scanf("%d", &n);
    for(int i = 0; i<n;i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void In(int a[], int n){
    for(int i = 0; i<n;i++){
        printf("%5d", a[i]);
    }
}
void Nhap_Matrix(int m[], int &d, int &c){
    printf("\nNhap so dong cua ma tran: ");
    scanf("%d", &d);
    printf("Nhap so cot cua ma tran: ");
    scanf("%d", &c);
    for(int i = 0; i<d;i++){
        for(int j = 0; j<c; j++){
            printf("M[%d, %d] = ", i, j);
            scanf("%d", &m[j*d+i]);
        }
    }
}
void In_Matrix(int m[], int d, int c){
    printf("Ma tran la: \n");
    for(int i = 0; i<d;i++){
        for(int j = 0; j<c;j++){
            printf("%5d", m[j*d+i]);
        }
        printf("\n");
    }
}
