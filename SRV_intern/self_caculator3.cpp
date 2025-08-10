#include <iostream>
using namespace std;

const int MAX = 200;

template<typename T>
class Stack{
  T arr[MAX];
  int top;
public:
  Stack() : top(-1){}
  void push(T x)  { if (top < MAX-1) arr[++top] = x; }
  T pop()         { return top >= 0 ? arr[top--] : T(); }
  T peek()        { return top >= 0 ? arr[top]   : T(); }
  bool isEmpty()  { return top == -1; }     
  void clear()    { top = -1; }             
};

// Kiểm tra toán hạng (số 1 ký tự)
bool isOperand(char c){
  return c >= '0' && c <= '9';
}

// Độ ưu tiên
int precedence(char op){
  switch(op){
    case '+': case '-':           return 1;
    case '*': case '/': case '%': return 2;
    case '^':                     return 3;
    case '~':                     return 4; // unary minus (đổi dấu)
    default:                      return 0;
  }
}

// Kết hợp phải cho ^ và ~
bool right_assoc(char op){ return (op == '^' || op == '~'); }

// Lũy thừa số nguyên, yêu cầu b >= 0
long long exponen(long long a, long long b){
  long long result = 1;
  while (b){
    if (b & 1) result *= a;
    a *= a;
    b >>= 1;
  }
  return result;
}

// Infix -> Postfix (RPN), có ngoặc và unary minus
void infixToPostfix(const char* expr, int n, char* postfix){
  Stack<char> ops;
  int j = 0;
  bool expectUnary = true; // đầu chuỗi / sau '(' / sau toán tử -> '-' là unary

  for (int i = 0; i < n; i++){
    char ch = expr[i];

    // Bỏ qua khoảng trắng nếu input có
    if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') continue;

    if (isOperand(ch)){
      postfix[j++] = ch;
      expectUnary = false;
    }
    else if (ch == '('){
      ops.push(ch);
      expectUnary = true;
    }
    else if (ch == ')'){
      while (!ops.isEmpty() && ops.peek() != '(')
        postfix[j++] = ops.pop();
      if (!ops.isEmpty() && ops.peek() == '(') ops.pop(); // bỏ '('
      expectUnary = false;
    }
    else { // toán tử
      char op = ch;
      if (op == '-' && expectUnary) op = '~'; // đánh dấu unary minus

      // Pop theo ưu tiên + kết hợp
      while (!ops.isEmpty() && ops.peek() != '('){
        char top = ops.peek();
        int pt = precedence(top), pc = precedence(op);
        bool shouldPop = (!right_assoc(op) && pt >= pc) || (right_assoc(op) && pt > pc);
        if (!shouldPop) break;
        postfix[j++] = ops.pop();
      }
      ops.push(op);
      expectUnary = true;
    }
  }
  while (!ops.isEmpty()) postfix[j++] = ops.pop();
  postfix[j] = '\0';
}

// Tính giá trị postfix
long long evalPostfix(const char* postfix){
  Stack<long long> vals;
  for (int i = 0; postfix[i] != '\0'; i++){
    char ch = postfix[i];

    if (isOperand(ch)){
      vals.push((long long)(ch - '0')); // số 1 ký tự
      continue;
    }

    switch(ch){
      case '~': { // unary minus
        long long x = vals.pop();
        vals.push(-x);
        break;
      }
      case '+': {
        long long b = vals.pop(), a = vals.pop();
        vals.push(a + b);
        break;
      }
      case '-': {
        long long b = vals.pop(), a = vals.pop();
        vals.push(a - b);
        break;
      }
      case '*': {
        long long b = vals.pop(), a = vals.pop();
        vals.push(a * b);
        break;
      }
      case '/': {
        long long b = vals.pop(), a = vals.pop();
        // Giả sử input hợp lệ, b != 0
        vals.push(a / b);
        break;
      }
      case '%': {
        long long b = vals.pop(), a = vals.pop();
        vals.push(a % b);
        break;
      }
      case '^': {
        long long b = vals.pop(), a = vals.pop(); // a^b, yêu cầu b >= 0
        // Nếu b âm sẽ không đúng cho số nguyên — giả định đề không cho mũ âm
        vals.push(exponen(a, b));
        break;
      }
      default:
        // ký tự lạ: bỏ qua
        break;
    }
  }
  return vals.pop();
}

int main(){

  int N;
    char expr[MAX], postfix[MAX];

    for (int tc = 1; tc <= 10; ++tc) {
        cin >> N;
        cin >> expr;

        int n = 0; while (expr[n] != '\0') ++n;
        if (n != N) N = n;

        infixToPostfix(expr, N, postfix);
        long long ans = evalPostfix(postfix);
        cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}
