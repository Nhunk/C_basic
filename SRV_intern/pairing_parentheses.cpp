#include <iostream>
using namespace std;

const int MAX = 300;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}') ||
           (open == '<' && close == '>');
}

int main() {
    int N;
    char data[MAX];

    for (int tc = 1; tc <= 10; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> data[i];

        char stack[MAX];
        int top = -1;
        bool valid = true;

        for (int i = 0; i < N; i++) {
            char ch = data[i];
            if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
                stack[++top] = ch;
            } else if (ch == ')' || ch == ']' || ch == '}' || ch == '>') {
                if (top == -1 || !isMatching(stack[top], ch)) {
                    valid = false;
                    break;
                }
                top--;
            }
        }
        if (top != -1) valid = false; // Unmatched opening

        cout << "#" << tc << " " << (valid ? 1 : 0) << endl;
    }
    return 0;
}