/*
The Samsung S/W Company plans to develop a game using mirrors on a nxn 2-dimensional grid. Each mirror is a two-way mirror and has only two directions as follows.

In the game, when a laser beam starts at (0, 0) in right direction, they need to count the number of times the beam hits a mirror until it hits a wall (boundary) of the grid.

[Example] In the following configuration, the beam hits mirrors 7 times until it hits the upper wall.

For this company, write a program to count the number of times the beam hits a mirror until it hits a wall (boundary) of the grid.

[Constraints]
1. The size n of a 2-dimensional grid is not more than 100. (5 ≤ n ≤ 100)
2.  No mirror in (0, 0)


[Input]
The test cases consist of the following format. In the first line, the number of test cases is given. From the next line, each test case is provided in n+ 1 line. In the first line of each test case, n is given. In the next n lines, a nxn 2-dimensional array is given row-by-row, one row per line. If an element of the array is ‘0’, it indicates an empty cell. When it is ‘1’, there is a mirror with [Direction 1] and if it is ‘2’, there is a mirror with [Direction 2] in the corresponding cell.

 

[Output]
Print out the number of times hits a mirror of the beam that starts at (0, 0), for each test case on a separate line, starting with ‘#x’, where x is the case number. Place a blank between two adjacent numbers for printing.
*/



#include <iostream>
using namespace std;



int main() {

    int T; // Số lượng bộ test
    cin >> T;
    int grid[100][100];

    for (int t = 1; t <= T; ++t) {
        int n; // Kích thước của lưới (n x n)
        cin >> n;

        // Đọc cấu hình lưới từ input
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        int currentRow = 0; // Hàng hiện tại của tia laser (bắt đầu từ 0)
        int currentCol = 0; // Cột hiện tại của tia laser (bắt đầu từ 0)

        int dr = 0;
        int dc = 1;

        int hitCount = 0; // Biến đếm số lần tia laser đập vào gương

        while (true) {
            // Di chuyển tia laser đến ô kế tiếp
            currentRow += dr;
            currentCol += dc;

            // Kiểm tra xem tia laser đã đập vào tường (ranh giới của lưới) chưa
            if (currentRow < 0 || currentRow >= n || currentCol < 0 || currentCol >= n) {
                break; // Tia laser đập vào tường, kết thúc mô phỏng
            }

            // Kiểm tra xem ô hiện tại có chứa gương hay không
            if (grid[currentRow][currentCol] != 0) {
                hitCount++; // Tăng số lần đập nếu gặp gương

                if (grid[currentRow][currentCol] == 1) {//gương hướng 1 thì quay sang phải 90 độ
                    int temp_dr = dr; // Lưu giá trị dr hiện tại để tính dc mới
                    dr = -dc;
                    dc = -temp_dr;
                }

                else if (grid[currentRow][currentCol] == 2) {//gương hướng 2 thì quay trái 90 độ
                    int temp_dr = dr; // Lưu giá trị dr hiện tại để tính dc mới
                    dr = dc;
                    dc = temp_dr;
                }
            }
        }

        // In kết quả cho bộ test hiện tại theo định dạng yêu cầu
        cout << "#" << t << " " << hitCount << "\n";
    }

    return 0; // Kết thúc chương trình thành công
}
