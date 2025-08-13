#include <iostream>
using namespace std;

const int MAX = 20;

int M, N;
char maze[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Pos {
    int x, y;
};

struct Stack {
    Pos arr[MAX * MAX];
    int top;
    Stack() { top = -1; }
    void push(Pos p) { if (top < MAX * MAX - 1) arr[++top] = p; }
    Pos pop() { 
        if (top >= 0) 
            return arr[top--]; 
        else 
            return Pos{-1, -1}; 
    }
    bool empty() { return top == -1; }
};

// Hàm DFS để tìm đường đi
bool dfs(Pos start, Pos end) {
    // Đánh dấu tất cả các ô chưa được thăm
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            visited[i][j] = false;

    Stack s;
    s.push(start);
    visited[start.x][start.y] = true;

    while (!s.empty()) {
        Pos cur = s.pop();
        if (cur.x == end.x && cur.y == end.y) return true;

        // Kiểm tra 4 hướng đi
        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
                !visited[nx][ny] && maze[nx][ny] == '.') {
                visited[nx][ny] = true;
                s.push(Pos{nx, ny});
            }
        }
    }
    return false;
}

// Hàm kiểm tra tính hợp lệ của mê cung
bool validateMaze() {
    Pos openings[80];
    int openCount = 0;

    // Quét biên để tìm cửa vào ra
    for (int i = 0; i < M; i++) {
        if (maze[i][0] == '.') {
            openings[openCount].x = i;
            openings[openCount].y = 0;
            openCount++;
        }
        if (N > 1 && maze[i][N - 1] == '.') {
            openings[openCount].x = i;
            openings[openCount].y = N - 1;
            openCount++;
        }
    }
    for (int j = 0; j < N; j++) {
        if (maze[0][j] == '.') {
            openings[openCount].x = 0;
            openings[openCount].y = j;
            openCount++;
        }
        if (M > 1 && maze[M - 1][j] == '.') {
            openings[openCount].x = M - 1;
            openings[openCount].y = j;
            openCount++;
        }
    }

    // Loại bỏ các cửa trùng nhau (góc bị đếm hai lần)
    Pos uniqueOpen[80];
    int uniqueCount = 0;
    for (int i = 0; i < openCount; i++) {
        bool found = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (openings[i].x == uniqueOpen[j].x && openings[i].y == uniqueOpen[j].y) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueOpen[uniqueCount].x = openings[i].x;
            uniqueOpen[uniqueCount].y = openings[i].y;
            uniqueCount++;
        }
    }

    // Kiểm tra có đúng 2 cửa vào ra không
    if (uniqueCount != 2) return false;

    // Thực hiện DFS giữa hai cửa
    return dfs(uniqueOpen[0], uniqueOpen[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> maze[i][j];
            }
        }
        if (validateMaze()) cout << "valid\n";
        else cout << "invalid\n";
    }
    return 0;
}
