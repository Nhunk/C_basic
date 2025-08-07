/*
Bài toán: Chia không gian cho các nhóm sao cho tổng thời gian chia nhỏ là nhỏ nhất.
- Mỗi lần chia, thời gian tỷ lệ với tổng kích thước không gian đang chia.
- Thứ tự chia ảnh hưởng đến tổng thời gian.
- Yêu cầu: Tìm tổng thời gian nhỏ nhất để chia hết cho các nhóm.

Ý tưởng:
- Luôn ghép hai nhóm nhỏ nhất trước để giảm tổng thời gian (giống bài ghép file tối ưu).
- Áp dụng hàng đợi ưu tiên (min-heap) để chọn hai nhóm nhỏ nhất mỗi lần.

Input:
- Số bộ test T.
- Mỗi test: số nhóm N, kích thước từng nhóm.

Output:
- Với mỗi test: In tổng thời gian tối thiểu.
*/
#include <iostream>
using namespace std;
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, max_idx;
    for (i = 0; i < n-1; i++){
	    max_idx = i;
	    for (j = i+1; j < n; j++)
	      if (arr[j] > arr[max_idx])
		      max_idx = j;
        swap(arr[max_idx], arr[i]);
    }
}
int main() 
{
    int N, test_cases;
    int num;
    int source[1000];
    cin>>N;
    for(test_cases=1; test_cases<=N;test_cases++){
      cin>>num;
      for(int i = 0; i< num; i++){
        cin>>source[i];
      }
      
      int maxIdx = 0;
      int result = 0;
      //sap xep tu lon den be
      selectionSort(source, num);
		  while (num > 1) {
			  int tmp = source[num - 1] + source[num - 2];
			  result += tmp;
			  --num;
			  source[num - 1] = tmp;
			  selectionSort(source,num);
		  }
      
      cout<<"Case #"<<test_cases<<endl;
      cout<<result<<endl;
    }
    
    return 0;
}