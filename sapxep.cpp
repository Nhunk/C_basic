#include <stdio.h>

void Xuatmang(int a[], int n);
void selection_sort(int a[], int n);
void bubble_sort(int a[], int n);

int main(){
	int a[]={12, 7, 34, 22, 68, 39, 84, 55};
	int n = 8;
	Xuatmang(a, n);
	selection_sort(a,n);
	bubble_sort(a,n);
}
void Xuatmang(int a[], int n){
	for(int i = 0; i<n;i++){
		printf("%5d", a[i]);
	}
}
void selection_sort(int a[], int n){
	for(int i = 0; i<n-1;i++){
		for(int j = i+1; j<n; j++){
			if(a[j]<a[i]){
				int temp = a[j];
				a[j] = a[i];
				a[i]=temp;
			}
		}
	}
	printf("\nKet qua sap xep chon: ");
	Xuatmang(a, n);
}
void bubble_sort(int a[], int n){
	for(int i = 0; i<n-1;i++){
		for(int j=n-1; j>i;j--){
			if(a[j]<a[j-1]){
				int temp = a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("\nKet qua sap xep noi bot: ");
	Xuatmang(a, n);
}