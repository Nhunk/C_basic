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


int main() {
  char source[100][100];
  int test_case;
  for (int test_case = 1; test_case <= 10; test_case++) {
    int a;
    cin>>a;
      for (int i = 0; i < 100; ++i)
          for (int j = 0; j < 100; ++j)
              cin >> source[i][j];

      int maxLen = 1;

      // Kiểm tra theo hàng
      for (int row = 0; row < 100; ++row) {
          for (int len = 100; len >= 2; --len) {
              bool found = false;
              for (int start = 0; start <= 100 - len; ++start) {
                  bool palin = true;
                  for (int k = 0; k < len / 2; ++k) {
                      if (source[row][start + k] != source[row][start + len - 1 - k]) {
                          palin = false;
                          break;
                      }
                  }
                  if (palin) {
                      if (len > maxLen) maxLen = len;
                      found = true;
                      break; // đã tìm được palin dài nhất ở hàng này
                  }
              }
              if (found) break; 
          }
      }

      // Kiểm tra theo cột
      for (int col = 0; col < 100; ++col) {
          for (int len = 100; len >= 2; --len) {
              bool found = false;
              for (int start = 0; start <= 100 - len; ++start) {
                  bool palin = true;
                  for (int k = 0; k < len / 2; ++k) {
                      if (source[start + k][col] != source[start + len - 1 - k][col]) {
                          palin = false;
                          break;
                      }
                  }
                  if (palin) {
                      if (len > maxLen) maxLen = len;
                      found = true;
                      break;
                  }
              }
              if (found) break;
          }
      }

      cout << "#" << test_case << " " << maxLen << endl;
    }
    return 0;
}