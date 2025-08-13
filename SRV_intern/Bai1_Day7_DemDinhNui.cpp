#include <iostream>
using namespace std;
//#define file() freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);

const int MAX = 701; // 1..100

struct Point{
	int x, y;
	Point(): x(-1), y(-1){}
	Point(int i, int j): x(i), y(j){}
};

struct  Queue{
	Point arr[MAX];
	int front, rear;

	Queue(): front(-1), rear(-1){}

	void enqueue(Point value){
		rear = (rear + 1) % MAX;
		arr[rear] = value;
	}

	Point dequeue(){
		if(isEmpty())
			return Point(-1, -1);
		front = (front + 1) % MAX;
		return arr[front];
	}

	bool isEmpty(){
		return front == rear;
	}

	void reset(){
		front = -1; 
		rear = -1;
	}
};

Queue queue;
int map[MAX][MAX], visited[MAX][MAX];
int N, M;
int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

void input(){
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
}

bool bfs(int nx, int ny){

	queue.reset();
	queue.enqueue(Point(nx, ny));
	visited[nx][ny] = true;
	int heigh = map[nx][ny];

	bool found = true;

	while(!queue.isEmpty()){
		Point cur = queue.dequeue();

		for(int i = 0; i < 8; i++){
			nx = cur.x + dx[i];
			ny = cur.y + dy[i];

			if( nx < 0  || nx >=N || ny < 0 || ny >=M )
				continue;

			if(map[nx][ny] > heigh){
				found = false;
			}

			if(!visited[nx][ny] && map[nx][ny] == heigh){
				visited[nx][ny] = true;
				queue.enqueue(Point(nx, ny));
			}
			
		}
	}
	return found;
}

int solve() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            visited[i][j] = false;

    int countPeak = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j]) {
                if(bfs(i, j)) countPeak++;
            }
        }
    }
    return countPeak;
}

int main(){
	//file();
	int test_case;
	cin>>test_case;
	for(int tc= 1; tc<=test_case; tc++){
		input();
		cout << "#" << tc << " " << solve()<< endl;
	}
	return 0;
}