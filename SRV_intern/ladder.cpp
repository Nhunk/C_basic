#include <iostream>
using namespace std;

int main() {
    const int SIZE = 100;
    int T;
    for (int test_case = 1; test_case <= 10; ++test_case) {
        cin >> T; 
        int ladder[SIZE][SIZE];
        int x = 0, y = 0;
        // tim '2'
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cin >> ladder[i][j];
                if (ladder[i][j] == 2) {
                    x = j;
                    y = i;
                }
            }
        }    
        while (y > 0) {
            ladder[y][x] = 0; // da di qua
            //left
            if (x > 0 && ladder[y][x - 1] == 1) {
                while (x > 0 && ladder[y][x - 1] == 1) {
                    x--;
                    ladder[y][x] = 0;
                }
            }
            //right
            else if (x < SIZE - 1 && ladder[y][x + 1] == 1) {
                while (x < SIZE - 1 && ladder[y][x + 1] == 1) {
                    x++;
                    ladder[y][x] = 0;
                }
            }
            //up
            y--;
        }
        cout << "#" << test_case<< " " << x << "\n";
    }
    return 0;
}