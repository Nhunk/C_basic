/*
Write a program to read in and solve path-finding puzzles. Each puzzle consists of an NxN array of integers
The problem is as follows: Starting in the upper left-hand corner (location [0][0]), find a sequence of moves that takes you to the bottom right-hand corner (for an NxN array, this would be location [N-1][N-1]). From each location in the array you may move left, right, up, or down; the number in the location tells you exactly how far to move.

For example, location [0][0] contains a 7, so from there you must move exactly 7 squares, either to the right or down. You cannot move up or left, because that would take you outside the array.
To help you see the solution, the squares along the solution path have been colored orange. From 7 you move right to 2, down to 4, down to 5, up to 5, etc. The complete solution is 
     [(0, 0), (0, 7), (2, 7), (6, 7), (1, 7), (1, 5), (1, 2),
      (7, 2), (7, 4), (7, 8), (4, 8), (5, 8), (5, 9), (9, 9)].
(Also, in the example, there are several squares from which you cannot move at all! Can you find them?)

Input
The first line contains t, the number of test cases followed by a blank space. Each of the t tests start with a number n (n <= 20). Then n + 1 lines follow. In the ith line a number A[i - 1] is given. The (n + 1)th line is a blank space.
Output
If you can reach the destination, print 'YES', otherwise print 'NO'.

*/

#include<iostream>
using namespace std;

const int MAX = 201*201;

struct Point {
    int x, y;
    Point(): x(-1), y(-1){} // Constructor
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
int map[201][201], visited[201][201];
int N;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void input(){
  cin >> N ;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> map[i][j];
}

int bfs(Point start, Point end){
    int nx, ny;
    Point cur;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            visited[i][j] = 0;
            
    queue.reset();
    queue.enqueue(start);
    visited[start.x][start.y] = 0;

    while(!queue.isEmpty()){
        cur = queue.dequeue();

        if (cur.x == end.x && cur.y == end.y) {
            return visited[cur.x][cur.y];
        }

        for(int i = 0; i < 4; i++){
            nx = cur.x + dx[i];
            ny = cur.y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] != 0 || map[nx][ny] == 0)
                continue;

            visited[nx][ny] = visited[cur.x][cur.y] + 1;
            queue.enqueue(Point(nx, ny));
        }
    }
    return -1;
}

int main(){
    int test_case;
    cin >> test_case;
    for(int tc = 1; tc <= test_case; tc++){
        input();
        
        Point princess(-1, -1);
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
              if (map[i][j] == 2)
                princess = Point(i, j);

        // Nếu không tìm thấy vị trí princess
        if (princess.x == -1) {
            cout << -1 << endl;
            continue;
        }

        int step1 = bfs(Point(0,0), princess);
        int step2 = bfs(princess, Point(N-1,N-1));
        
        if (step1 == -1 || step2 == -1)
            cout << -1 << endl;
        else
            cout << step1 + step2 << endl;
    }
    return 0;
}