#include <iostream>
using namespace std;

const int MAX = 200;

int dr[4] = {-1,1,0,0};//trên trái dưới phải của hàng
int dc[4] = {0,0,-1,1};//trên trái dưới phải của cột 

struct Pos {
    int r, c;
};

class Stack {
    Pos arr[MAX];
    int top;
public:
    Stack() : top(-1) {}
    void push(Pos x) { if (top < MAX-1) arr[++top] = x; }
    Pos pop() { return top >= 0 ? arr[top--] : Pos{0, 0}; }
    bool isEmpty() { return top == -1; }
    void clear() { top = -1; }
};


bool check(int a[16][16]){
    bool visited[16][16] = {false};
    Stack s;
    s.push(Pos{1,1});
    visited[1][1] = true;

    while(!s.isEmpty()){
        Pos pos = s.pop();
        int r = pos.r, c = pos.c;
        if(a[r][c] == 3) return true; // Found goal
        for(int d=0; d<4; d++){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr>=0 && nr<16 && nc>=0 && nc<16 && !visited[nr][nc] && a[nr][nc]!=1){
                s.push(Pos{nr,nc});
                visited[nr][nc]=true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    string row;
    int source[16][16];
    for(int test_cases = 1; test_cases<=10; test_cases++){ 
        cin >> t;
        for(int i = 0; i< 16; i++){
            cin >> row;//input dang chuoi
            for(int j = 0; j < 16; j++)
                source[i][j] = row[j] - '0';
        }
               
        int ans = check(source) ? 1 : 0;
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}