#include <iostream>
using namespace std;

const int MAX = 200;

template<typename T>
class Stack {
    T arr[MAX];
    int top;
public:
    Stack() : top(-1) {}
    void push(T x) { if (top < MAX-1) arr[++top] = x; }
    T pop() { return top >= 0 ? arr[top--] : T(); }
    T peek() { return top >= 0 ? arr[top] : T(); }
    bool isEmpty() { return top == -1; }
    void clear() { top = -1; }
};

int precedence(char op) {
    if (op == '+') return 1;
    if (op == '*') return 2;
    return 0;
}

bool isOperand(char c) {
    return c >= '0' && c <= '9';
}

void infixToPostfix(const char* expr, int n, char* postfix) {
    Stack<char> opStack;
    int j = 0;
    for (int i = 0; i < n; i++) {
        char ch = expr[i];
        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else {
            while (!opStack.isEmpty() && precedence(opStack.peek()) >= precedence(ch)) {
                postfix[j++] = opStack.pop();
            }
            opStack.push(ch);
        }
    }
    while (!opStack.isEmpty()) postfix[j++] = opStack.pop();
    postfix[j] = '\0';
}

int evalPostfix(const char* postfix) {
    Stack<int> valStack;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isOperand(ch)) {
            valStack.push(ch - '0');
        } else {
            int b = valStack.pop();
            int a = valStack.pop();
            if (ch == '+') valStack.push(a + b);
            else if (ch == '*') valStack.push(a * b);
        }
    }
    return valStack.pop();
}

int main() {
    int N;
    char data[MAX], postfix[MAX];
    for (int tc = 1; tc <= 10; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> data[i];
        infixToPostfix(data, N, postfix);
        cout << "#" << tc << " " << evalPostfix(postfix) << endl;
    }
    return 0;
}