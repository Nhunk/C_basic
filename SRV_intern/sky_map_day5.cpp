/*You are making “sky map” to represent constellation (group of starts) in the sky.
In each element, 1 means star, 0 means empty.
And in a constellation, each start should have at least one connection with others via left/right/up/bottom. 
If two starts are located via diagonal, then
the two stars are not connected (belong to different constellation.)
How many constellations are in your sky map, and what is the number of starts in the greatest constellation?

[Input]
There can be more than one test case in the input.
The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T<=10)
In each test case, the first line has an integer N(5 ≤ N ≤ 25), the size of map.
The map is a square, and is represented as N x N matrix.
For next N lines, each contains each raw of the matrix

[Output]
For each test case, you should print the number of constellation and the number of starts in the greatest constellation separated by blank.
*/

#include<iostream>
using namespace std;

const int MAX = 25*25;

struct Point {
    int x, y;
    Point(): x(-1), y(-1){}
    Point(int i, int j): x(i), y(j){}
};

struct Queue {
    Point arr[MAX];
    int front, rear;

    Queue(): front(-1),  rear(-1) {}
    void enqueue(Point value) {
        rear = (rear + 1) % MAX ;
        arr[rear] = value;
    }

    Point dequeue() {
        if (isEmpty())
            return Point(-1, -1);
        front = (front + 1) % MAX;
        return arr[front];
    }
    bool isEmpty() {
        return front == rear;
    }
    void reset(){
        front = -1;
        rear = -1;
    }
};

Queue queue;
int map[25][25], visited[25][25];
int N;
int dx[4] = {0, 0, 1, -1}; // rows
int dy[4] = {1, -1, 0, 0}; // cols

void input() {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
}

int bfs(int x_start, int y_start) {
    int nx, ny;
    Point cur;
    int stars = 1;

    queue.reset();
    queue.enqueue(Point(x_start, y_start));
    visited[x_start][y_start] = 1;

    while(!queue.isEmpty()) {
        cur = queue.dequeue();
        for(int i = 0; i < 4; i++) {
            nx = cur.x + dx[i];
            ny = cur.y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || map[nx][ny] == 0)
                continue;
            visited[nx][ny] = 1;
            queue.enqueue(Point(nx, ny));
            stars++;
        }
    }
    return stars;
}

int main() {
    int test_case;
    cin >> test_case;
    for(int tc = 1; tc <= test_case; tc++) {
        input();

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                visited[i][j] = 0;

        int num = 0, max_stars = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    int cnt = bfs(i, j);
                    num++;
                    if(cnt > max_stars) max_stars = cnt;
                }
            }
        cout << num << " " << max_stars << endl;
    }
    return 0;
}