/*
Đọc dãy số ban đầu và số lượng lệnh.
Xử lý từng lệnh:
Insert (I): Dời các số sang phải để chèn số mới vào vị trí chỉ định.
Delete (D): Dời các số sang trái để xoá số ở vị trí chỉ định.
Add (A): Thêm số vào cuối dãy.
- Output: in ra 10 phần tử đầu tiên.
*/
#include <iostream>
using namespace std;

int main() {
    int source[5000], data[5000];
    int test_case, command_num;
    int idx, count; // vi tri va so chen
    int idx2, count2;//vi tri va so xoa
    int count3;//so them vao cuoi
    int N; 

    for (test_case = 1; test_case <= 10; test_case++) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> source[i];

        cin >> command_num;
        for (int i = 0; i < command_num; i++) {
            char cmd;
            cin >> cmd;
            
            if (cmd == 'I') {
                cin >> idx >> count;
                for (int j = 0; j < count; ++j)
                    cin >> data[j];

                // Move the existing elements to make space for new ones
                for (int j = N - 1; j >= idx; --j)
                    source[j + count] = source[j];

                // Insert new numbers
                for (int j = 0; j < count; ++j)
                    source[idx + j] = data[j];

                N += count;
            } else if (cmd == 'D') {
                cin >> idx2 >> count2;

                // Shift the remaining elements left
                for (int j = idx2; j < N - count2; ++j)
                    source[j] = source[j + count2];

                N -= count2;
            }else if(cmd == 'A'){
              cin>>count3;
              for (int j = 0; j < count3; j++)
                cin >> data[j];
              for (int j =0; j < count3; j++)
                source[N+j] = data[j];
                N+=count3;

            }
        }

        cout << "#" << test_case << " ";
        for (int i = 0; i < 10; i++)
            cout << source[i] << " ";
        cout << "\n";
    }
    return 0;
}