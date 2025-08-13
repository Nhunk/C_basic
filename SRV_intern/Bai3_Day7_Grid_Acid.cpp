#include <iostream>
using namespace std;
//#define file() freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);

const int MAX = 101;

struct Point {
    int x, y;
    Point(): x(-1), y(-1) {}
    Point(int i, int j): x(i), y(j) {}
};

struct Queue {
    Point arr[MAX * MAX];
    int front, rear;
    Queue(): front(-1), rear(-1) {}
    void reset() { front = rear = -1; }
    bool isEmpty() { return front == rear; }
    void enqueue(Point p) {
        rear = (rear + 1) % (MAX * MAX);
        arr[rear] = p;
    }
    Point dequeue() {
        if (isEmpty()) return Point(-1, -1);
        front = (front + 1) % (MAX * MAX);
        return arr[front];
    }
};

int N, M;
int start_x, start_y;
int end_x, end_y;
int grid[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

Queue q;

void input() {
    cin >> N >> M;
    cin >> start_x >> start_y;
    start_x--; start_y--; // đưa về chỉ số mảng
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            visited[i][j] = -1; // reset visited
            if (grid[i][j] == 2) {
                end_x = i;
                end_y = j;
            }
        }
    }
}

void bfs(int tc) {
    q.reset();
    visited[start_x][start_y] = 0;
    q.enqueue(Point(start_x, start_y));

    int count1 = -1; // số bước ngắn nhất đến đích
    int count2 = 0;  // số bước xa nhất

    while (!q.isEmpty()) {
        Point cur = q.dequeue();
        int cur_dist = visited[cur.x][cur.y];

        if (cur.x == end_x && cur.y == end_y && count1 == -1) {
            count1 = cur_dist;
        }

        if (cur_dist > count2) count2 = cur_dist;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (grid[nx][ny] != 0 && visited[nx][ny] == -1) {
                visited[nx][ny] = cur_dist + 1;
                q.enqueue(Point(nx, ny));
            }
        }
    }

    cout << "Case #" << tc << "\n" << count1 << " " << count2 << "\n";
}

int main() {
   // file();
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        input();
        bfs(tc);
    }
    return 0;
}
