#include <iostream>
using namespace std;
#define file() freopen("input.exe", "r", stdin), freopen("output.exe", "w", stdout);
const int MAX = 1001;

struct Point {
    int x, y;
    Point(): x(-1), y(-1) {}
    Point(int i, int j): x(i), y(j) {}
};

struct Queue {
    Point arr[650000];
    int front, rear;

    Queue(): front(-1), rear(-1) {}

    void enqueue(Point value) {
        rear = (rear + 1) % (MAX * MAX);
        arr[rear] = value;
    }

    Point dequeue() {
        if (isEmpty()) return Point(-1, -1);
        front = (front + 1) % (MAX * MAX);
        return arr[front];
    }

    bool isEmpty() {
        return front == rear;
    }

    void reset() {
        front = -1;
        rear = -1;
    }
};

Queue queue;
int visited[MAX][MAX];
int N, M;
int ax, ay, dx, dy;
int mx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int my[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void input() {
    cin >> N >> M;
    cin >> ax >> ay >> dx >> dy;
    ax--;
    ay--;
    dx--;
    dy--;
}

int bfs_steps() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            visited[i][j] = -1;
        }

    queue.reset();
    queue.enqueue(Point(ax, ay));
    visited[ax][ay] = 0;

    while (!queue.isEmpty()) {
        Point cur = queue.dequeue();

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + mx[i];
            int ny = cur.y + my[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M|| visited[nx][ny] >= 0) continue;
            visited[nx][ny] =  visited[cur.x][cur.y] + 1;
            queue.enqueue(Point(nx, ny));
            
            if (nx == dx && ny == dy) 
                return visited[nx][ny];
            }
        }
    return visited[dx][dy]; 
}

int main() {
	file();
    int test_case;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++) {
        input();
        int steps = bfs_steps();
        cout << "Case #" << tc << "\n" << steps << endl;
    }
    return 0;
}
