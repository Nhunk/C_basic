/*
Đề bài:
Tìm độ dài xâu đối xứng (palindrome) có độ dài theo yêu cầu từ bảng 8x8 ký tự.

Input:
- 10 test cases, mỗi test case gồm độ dài chuỗi palin cần tìm và ma trận 8x8

Output:
- Với mỗi test case, in ra "#t KQ" với t là số test case, KQ là palindrome tìm được.
*/
#include <iostream>
using namespace std;

int main() {
    int test_case;
    int N;//Do dai palindrome can tim
    char source[8][8];

    for (test_case = 1; test_case <= 10; test_case++) {
        cin >> N;
        for (int i = 0; i < 8; ++i)
          for(int j = 0; j < 8;j++)
            cin >> source[i][j];
        int count=0;
        //Kiem tra theo hang
        for(int i = 0; i <8; i++){//duyet theo hang
          for(int j = 0;j <= 8-N; j++){ // duyet doan n can tim
            bool kt = true;
            for(int k = 0; k < N/2; k++){ // kiem tra cap doi xung
              if(source[i][j + k] != source[i][j + N - 1 - k]){
                kt = false;
                break;
              }
            }
            if(kt)
              count++;
          }
        }
        
        //Kiem tra theo cot
        for(int i = 0; i < 8;i++){//duyet theo cot
          for(int j = 0; j<=8-N; j++){ // duyet doan n can tim
            bool kt = true;
            for(int k = 0; k<N/2;k++){ // kiem tra cap doi xung
              if(source[j+k][i] != source[j+N-1-k][i]){
                kt = false;
                break;
              }
            }
            if(kt)
              count++;
          }
        }

        cout << "#" << test_case << " "<< count <<endl;
    }
    return 0;
}