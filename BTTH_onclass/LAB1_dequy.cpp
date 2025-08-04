#include <stdio.h>

int CAU1A(int n);
void CAU1B(int n, int &s);
int CAU1C(int n);
void CAU1D(int n, int &s);
void hn_tower(int n, char A, char B, char C);

int main(){
	int n, m, s1, s2=0, s3, s4=0;
	char A, B, C;
	printf("Cau 1:\nNhap so nguyen n: ");
	scanf("%d", &n);
	//Câu 1: Tính tổng các số phần tử của một số nguyên n
	//Cau 1a: Kieu ham return, dung vong lap
	s1 = CAU1A(n);
	printf("Cau 1a: s = %d", s1);
	
	//Cau 1b: Kieu ham void, dung vong lap
	CAU1B(n,s2);
	printf("\nCau 1b: s = %d", s2);
	
	//Cau 1c: Kieu ham return, dung de quy
	s3 = CAU1C(n);
	printf("\nCau 1c: s = %d", s3);
	
	//Cau 1d: Kieu ham void, dung de quy
	CAU1D(n, s4);
	printf("\nCau 1d: s = %d", s4);
	
	//Cau 2: In các bước chuyển đĩa của game tháp Hà Nội
	printf("\n\nCau 2: \nNhap so dia : ");
	scanf("%d", &m);
	printf("\nCach giai bai toan la:\n");
	hn_tower(m, 'A', 'B', 'C');
	
}
int CAU1A(int n){
	int temp, s=0;
	while(n!=0){
		temp = n%10;
		s += temp;
		n = n/10;
	}
	return s;
}
void CAU1B(int n, int&s){
	int temp;
	while(n!=0){
		temp = n%10;
		s += temp;
		n = n/10;
	}
}
int CAU1C(int n){
	if(n==0) 
		return 0;
	else 
		return n%10 + CAU1C(n/10);
}
void CAU1D(int n, int &s){
	if(n!=0){
		s = s + n%10;
		CAU1D(n/10, s);
	}
}
void hn_tower(int n, char A, char B, char C){
	if(n==1){
		printf("Chuyen dia 1 tu coc %c qua coc %c \n", A, B);	
		return;
	}
		hn_tower(n-1, A, C, B);
		printf("Chuyen dia %d tu coc %c qua coc %c \n", n, A, B);
		hn_tower(n-1, C, B, A);
}




