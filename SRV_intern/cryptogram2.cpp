#include <iostream>
using namespace std;

int main() {
    int source[500], data[500];
    int test_case, command_num;
    int idx, count;
    int idx2, count2;
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
            }
        }

        cout << "#" << test_case << " ";
        for (int i = 0; i < 10; i++)
            cout << source[i] << " ";
        cout << "\n";
    }
    return 0;
}