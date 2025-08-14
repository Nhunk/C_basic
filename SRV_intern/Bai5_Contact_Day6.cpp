#include <iostream>
using namespace std;
#define file() freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);

const int MAX = 101; // 1..100
struct Queue {
    int arr[MAX*MAX];
    int front, rear;
    Queue() : front(-1), rear(-1) {}
    bool isEmpty() { return front == rear; }
    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() { return isEmpty() ? -1 : arr[++front]; }
    void reset() { front = rear = -1; }
};

Queue queue;
int cont[MAX][MAX], visited[MAX], level[MAX];
int lenData, start;

void input() {
    // reset
    for (int i = 1; i < MAX; i++) {
        visited[i] = 0;
        level[i] = 0;
        for (int j = 1; j < MAX; j++) {
            cont[i][j] = 0;
        }
    }

    cin >> lenData >> start;
    int edges = lenData / 2; // m?i c?nh là 2 s?
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        cont[u][v] = 1;
    }
}

int bfs() {
    int maxLevel = 0;
    queue.reset();

    queue.enqueue(start);
    visited[start] = 1;
    level[start] = 1;

    while (!queue.isEmpty()) {
        int u = queue.dequeue();
        if (level[u] > maxLevel) maxLevel = level[u];

        for (int v = 1; v < MAX; v++) {
            if (cont[u][v] && !visited[v]) {
                visited[v] = 1;
                level[v] = level[u] + 1;
                queue.enqueue(v);
            }
        }
    }

    int ans = -1;
    for (int i = 1; i < MAX; i++) {
        if (level[i] == maxLevel && i > ans) ans = i;
    }
    return ans;
}

int main() {
	file();
    for (int tc = 1; tc <= 10; tc++) {
        input();
        int result = bfs();
        cout << "#" << tc << " " << result << "\n";
    }
    return 0;
}
