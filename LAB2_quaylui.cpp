#include <stdio.h>

void inkq(int x[], int n) ;
void Try_Binary(int i, int x[], int n);
void Try_HV(int i, int y[],int b[], int n);

int main() {
    int n;
    printf("Nhap do dai n: ");
    scanf("%d", &n); 
    int x[10], y[10], b[10]={0};
    printf("Cau 1:\n Chuoi so nhi phan tim duoc la:");
    Try_Binary(0, x, n);
    printf("\n\nCau 2:\n Chuoi so hoan vi cac phan tu tu 1 den %d la: ", n); 
    Try_HV(0, y, b, n);
    return 0;
}
void inkq(int x[], int n) {
    printf("\n");  
    for (int j = 0; j < n; j++) {
        printf("%d", x[j]); 
    }
}
void Try_Binary(int i, int x[], int n) {
    int k;
    for (k = 0; k <= 1; k++) {
        x[i] = k; 
        if (i == n - 1) 
            inkq(x, n);  
        else 
            Try_Binary(i + 1, x, n); 
    }
}
void Try_HV(int i, int y[],int b[], int n){
    for(int j = 1; j<=n;j++){
        if(b[j]==0){
            y[i] = j;
            b[j]=1;
            if(i==n-1)
                inkq(y,n);
            else
                Try_HV(i+1, y, b, n);
            b[j]=0;
        }
    }
}
