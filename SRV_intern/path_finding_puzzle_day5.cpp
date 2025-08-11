/*
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

const int MAX = 21*21;

struct Point {
    int x, y;
    Point(): x(-1), y(-1){}//Constructor
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


Queue queue;
int map[21][21], visited[21][21];
int N;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void input(){
  cin >> N ;
  
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> map[i][j];
}

int max(int a, int b){
	return (a > b) ? a : b;
}

bool bfs(){
	int nx, ny;
	Point cur;
  
  for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            visited[i][j] = 0;
            
	queue.reset();
	queue.enqueue(Point(0,0));
	visited[0][0] = 1;

	while(!queue.isEmpty()){
		cur = queue.dequeue();

		if (cur.x == N - 1 && cur.y == N - 1) {
            return true;
        }
        
		int move_dist = map[cur.x][cur.y];

		for(int i = 0; i < 4; i++){
			nx = cur.x + dx[i]*move_dist;
			ny = cur.y + dy[i]*move_dist;

			if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] !=0 || map[nx][ny] == 0)
				continue;

			visited[nx][ny] = true;
			queue.enqueue(Point(nx, ny));
		}
	}
	return false;
}

int main(){
	int test_case;
	cin >> test_case;
	for(int tc = 1; tc <= test_case; tc++){
		input();
    
		cout << (bfs()? "YES" : "NO") << endl;
	}
	return 0;
}
			