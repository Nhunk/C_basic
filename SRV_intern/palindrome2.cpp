/*
Đề bài:
Tìm độ dài xâu đối xứng (palindrome) dài nhất trong bảng 100x100 ký tự.

Input:
- 10 test cases, mỗi test case gồm 100 dòng, mỗi dòng 100 ký tự (chỉ gồm các chữ cái in hoa A/B/C...).

Output:
- Với mỗi test case, in ra "#t KQ" với t là số test case, KQ là palindrome dài nhất tìm được.
*/

#include <iostream>
using namespace std;

int main() 
{
    int test_case;
    int N;// Độ dài chuỗi palindrome(xâu đối xứng) cần tìm
    char data[100][100];

    for(test_case=1; test_case<=10; test_case++){
      
      //Nhập input
      cin>>N;
      for(int i = 0; i< 100; i++)
        for(int j = 0; j< 100; j++)
          cin>>data[i][j];
      
      int maxLen = 0; //Biến lưu số chuỗi đối xứng lớn nhất tìm được
      
      //Kiểm tra theo hàng
      for(int row = 0; row <100; row++){
        for(int len = 100; len >= 2; len--){
          bool found = false;
          for(int i = 0; i<= 100 - len; i++){
            bool palin = true;
            for(int j = 0; j <len/2;j++){
              if(data[row][i+j] != data[row][i+len-1-j]){
                palin = false;
                break;
              }
            }
          
          if(palin)
            if(len>maxLen){
              maxLen = len;
              found = true;
            }
          }
        if(found) break;
        }
      }
      
      //Kiểm tra theo cột
      for(int col = 0; col <100; col++){
        for(int len = 100; len >=2; len--){
          bool found = false;
          for(int i = 0; i <= 100-len; i++){
            bool palin = true;
            for(int j = 0; j < len/2;j++){
              if(data[i+j][col] != data[i+len - 1 - j][col]){
                palin = false;
                break;
              }
            }
          
          if(palin)
            if(len>maxLen){
              maxLen=len;
              found = true;
            }
          }
        if(found) break;
        }
      }
      
      
      cout<<'#'<<test_case<<' '<<maxLen<< endl;
    }
    return 0;
}