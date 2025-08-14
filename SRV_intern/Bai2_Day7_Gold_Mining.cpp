#include <iostream>
using namespace std;
#define file() freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);

const int MAX =21; // 1..100
const int INF = 20040402;

struct Point{
	int x, y;
	Point(): x(-1), y(-1){}
	Point(int i, int j): x(i), y(j){}
};

struct  Queue{
	Point arr[MAX*MAX];
	int front, rear;

	Queue(): front(-1), rear(-1){}

	void enqueue(Point value){
		rear = rear + 1;
		arr[rear] = value;
	}

	Point dequeue(){
		if(isEmpty())
			return Point(-1, -1);
		front = front + 1;
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
Point gold[5];
int N, G;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0,-1, 1};

void input(){
	cin >> N >> G;
	for(int i = 0; i < G; i++){
		cin>> gold[i].x >> gold[i].y;
		gold[i].x--;
		gold[i].y--;
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
}

int bfs(int nx, int ny){
  for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            visited[i][j] = -1;
        }
    }
	queue.reset();
	queue.enqueue(Point(nx, ny));
	visited[nx][ny] = 0;

	while(!queue.isEmpty()){
		Point cur = queue.dequeue();

		for(int i = 0; i < 4; i++){
			nx = cur.x + dx[i];
			ny = cur.y + dy[i];

			if( nx >= 0  && nx < N && ny >= 0 && ny <N && visited[nx][ny]==-1 && map[nx][ny] == 1){
				visited[nx][ny] = visited[cur.x][cur.y] + 1;
				queue.enqueue(Point(nx, ny));		
			}
		}
	}
	int max_cost = 0;
    for (int i = 0; i < G; ++i) {
        int x = gold[i].x;
        int y = gold[i].y;
        if (visited[x][y] == -1) {
            return INF;
        }
        if (visited[x][y] > max_cost) {
            max_cost = visited[x][y];
        }
    }
    return max_cost;
}

void solve(int tc) {
    
    int min_final_cost = INF;

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            bool is_gold_mine = false;
            for (int i = 0; i < G; ++i) {
                if (x == gold[i].x && y == gold[i].y) {
                    is_gold_mine = true;
                    break;
                }
            }

            if (map[x][y] == 1 && !is_gold_mine) {
                int cost = bfs(x, y);
                if (cost < min_final_cost) {
                    min_final_cost = cost;
                }
            }
        }
    }
	cout << "Case #" << tc << '\n' <<min_final_cost << endl;
}

int main(){
	file();
	int test_case;
	cin>>test_case;
	for(int tc= 1; tc<=test_case; tc++){
		input();
		solve(tc);
	}
	return 0;
}