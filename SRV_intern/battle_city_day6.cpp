/*
﻿ There can be more than one test case in the input. The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T<=10).
The first line of each test case contains two integers M and N (2 <= M, N< = 300). Each of the following M lines contains N uppercase letters, each of which is one of 'Y' (you), 'T' (target), 'S' (steel wall), 'B' (brick wall), 'R' (river) and 'E' (empty space). Both 'Y' and 'T' appear only once. 
Output
For each test case, please output the turns you take at least in a separate line. If you can't arrive at the target, output "-1" instead.
*/

#include <iostream>
using namespace std;

const int MAX = 301;
struct Point {
    int x, y;
    Point(): x(-1), y(-1){}//Constructor
    Point(int i, int j): x(i), y(j){}
};

struct Queue {
    Point arr[MAX*MAX];
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
    
    Point Qpeek(){
      if (isEmpty()) 
        return Point(-1, -1);
      return arr[front + 1];
    }

    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull(){
      return (rear + 1) % MAX == front;
    }
    
    void reset(){
      front = -1;
      rear = -1;
    }
};

int M, N;
int sx, sy, tx, ty;
int dx[4] = {1, -1, 0, 0};   // hướng đi
int dy[4] = {0, 0, 1, -1};
char map[MAX][MAX];
int count[MAX][MAX];

Queue queue;

void input(){
    cin >> M >> N;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            if(map[i][j]=='Y') { sx=i; sy=j; }
            if(map[i][j]=='T') { tx=i; ty=j; }
        }
    }
}


int bfs() {
    int nx, ny;
    Point cur;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            count[i][j] = -1;

    queue.reset();
    queue.enqueue(Point(sx, sy));
    count[sx][sy] = 0;

    while(!queue.isEmpty()) {
        cur = queue.dequeue();

        if(cur.x == tx && cur.y == ty)
            return count[cur.x][cur.y];

        for(int i = 0; i < 4; i++) {
            nx = cur.x + dx[i];
            ny = cur.y + dy[i];

            if(nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;

            if(map[nx][ny] == 'S' || map[nx][ny] == 'R')
                continue;

            int step = count[cur.x][cur.y] + (map[nx][ny] == 'B' ? 2 : 1);

            if(count[nx][ny] == -1 || step < count[nx][ny]) {
                count[nx][ny] = step;
                queue.enqueue(Point(nx, ny));
            }
        }
    }
    return -1;
}
int main() {
    int T;
    cin >> T;
    for(int testcase=1; testcase<=T;testcase++) {
        input();
        cout <<"Case #"<<testcase<<endl<< bfs() << endl;
    }
    return 0;
}


// #include <iostream>
// using namespace std;

// const int MAX = 301;
// struct Point {
//     int x, y;
//     Point(): x(-1), y(-1){}//Constructor
//     Point(int i, int j): x(i), y(j){}
// };

// struct Queue {
//     Point arr[MAX];
//     int front, rear;

//     Queue(): front(-1),  rear(-1) {}
    
//     void enqueue(Point value) {
//       rear = (rear + 1) % MAX ;
//       arr[rear] = value;
//     }

//     Point dequeue() {
//       if (isEmpty()) 
//         return Point(-1, -1);
//       front = (front + 1) % MAX;
//       return arr[front];
//     }
    
//     Point Qpeek(){
//       if (isEmpty()) 
//         return Point(-1, -1);
//       return arr[front + 1];
//     }

//     bool isEmpty() {
//         return front == rear;
//     }
    
//     bool isFull(){
//       return (rear + 1) % MAX == front;
//     }
    
//     void reset(){
//       front = -1;
//       rear = -1;
//     }
// };

// int M, N;
// int sx, sy, tx, ty;
// int dx[4] = {1, -1, 0, 0};   // hướng đi
// int dy[4] = {0, 0, 1, -1};
// char map[MAX][MAX];
// int count[MAX][MAX];

// Queue queue;

// void input(){
//     cin >> M >> N;
//     for(int i=0; i<M; i++) {
//         for(int j=0; j<N; j++) {
//             cin >> map[i][j];
//             if(map[i][j]=='Y') { sx=i; sy=j; }
//             if(map[i][j]=='T') { tx=i; ty=j; }
//         }
//     }
// }


// int bfs() {
//     int nx, ny;
//     Point cur;
//     for(int i = 0; i < M; i++)
//         for(int j = 0; j < N; j++)
//             count[i][j] = -1;

//     queue.reset();
//     queue.enqueue(Point(sx, sy));
//     count[sx][sy] = 0;

//     while(!queue.isEmpty()) {
//         cur = queue.dequeue();

//         if(cur.x == tx && cur.y == ty)
//             return count[cur.x][cur.y];

//         for(int i = 0; i < 4; i++) {
//             nx = cur.x + dx[i];
//             ny = cur.y + dy[i];

//             if(nx < 0 || nx >= M || ny < 0 || ny >= N)
//                 continue;

//             if(map[nx][ny] == 'S' || map[nx][ny] == 'R')
//                 continue;

//             int step = count[cur.x][cur.y] + (map[nx][ny] == 'B' ? 2 : 1);

//             if(count[nx][ny] == -1 || step < count[nx][ny]) {
//                 count[nx][ny] = step;
//                 queue.enqueue(Point(nx, ny));
//             }
//         }
//     }
//     return -1;
// }
// int main() {
//     int T;
//     cin >> T;
//     for(int testcase=1; testcase<=T;testcase++) {
//         input();
//         cout <<"Case #"<<testcase<<endl<< bfs() << endl;
//     }
//     return 0;
// }