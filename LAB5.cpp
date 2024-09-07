#include <stdio.h>

void Xuatmang(int a[], int n);
void Chen1A(int a[], int &n, int &x, int &vt);
void Chen2A(int a[], int &n, int &y);
int main(){
    int a[100]={1, 4, 9, 13, 22, 53, 77, 82, 86, 95};
    int n = 10, x, y, vt;
    Xuatmang(a, n);
    Chen1A(a, n, x, vt);
    Chen2A(a, n, y);
}
void Xuatmang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%5d", a[i]);
    }
}
void Chen1A(int a[], int &n, int &x, int &vt){
    printf("\nCau 1:");
    printf("\nNhap vi tri chen: ");
    scanf("%d", &vt);
    printf("Nhap gia tri muon chen: ");
    scanf("%d", &x);
    if (vt < 0 || vt > n) {
        printf("Vi tri chen khong hop le!\n");
        return;
    }
    for(int i = n; i>vt; i--){
        a[i]=a[i-1];
    }
    a[vt] = x;
    n++;
    printf("Mang sau khi chen la: ");
    Xuatmang(a, n);
}
void Chen2A(int a[], int &n, int &y){
	printf("\nCau 2:");
    printf("\nNhap gia tri chen: ");
    scanf("%d", &y);
    int i = n-1;
    while (i>=0 && a[i]>y){
        a[i+1] = a[i];
        i--;
    }
    a[i+1]=y;
    n++;
    printf("Mang sau khi chen la: ");
    Xuatmang(a, n);
}