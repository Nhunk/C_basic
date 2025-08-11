/* [Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 30) are given in a row.
The row and column of the city, N and M are given by being separated with a blank on the first row of each test case. (1 ≤ N, M ≤ 100)
The status within city is given by being separated with a blank from the second row to N number rows. 1 means people exist and 0 means people do not exist.
The coordinate of the row and column on which the bomb fall is given by being separated with a blank on the last row.

[Output]
Output how long does it take to contaminate al people on the first row of each test case.
*/
#include<iostream>
using namespace std;

const int MAX = 101*101;

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
int x_start, y_start;
int map[100][100], visited[100][100];
int N, M;
int dx[4] = {0, 0, 1, -1}; // rows
int dy[4] = {1, -1, 0, 0}; // cols

void input(){
  cin >> N >> M;
  
  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++)
      cin >> map[i][j];
      
  cin >> y_start >> x_start;
  x_start--;
  y_start--;
}

int max(int a, int b){
	return (a > b) ? a : b;
}

int bfs(){
	int nx, ny;
	Point cur;
	int maxtime = 1;
  
  for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            visited[i][j] = 0;
            
	queue.reset();
	queue.enqueue(Point(x_start, y_start));
	visited[x_start][y_start] = 1;

	while(!queue.isEmpty()){
		cur = queue.dequeue();
		for(int i = 0; i < 4; i++){
			nx = cur.x + dx[i];
			ny = cur.y + dy[i];

			if(nx < 0 || nx >= M || ny < 0 || ny >= N || visited[nx][ny] !=0 || map[nx][ny] == 0)
				continue;

			visited[nx][ny] = visited[cur.x][cur.y] + 1;
			queue.enqueue(Point(nx, ny));
			maxtime= max(maxtime, visited[nx][ny]);
		}
	}
	return maxtime;
}

int main(){
	int test_case;
	cin >> test_case;
	for(int tc = 1; tc <= test_case; tc++){
		input();
    int result = bfs();
		cout << result << endl;
	}
	return 0;
}
			