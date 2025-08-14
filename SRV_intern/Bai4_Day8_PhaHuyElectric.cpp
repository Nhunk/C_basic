#include <iostream>
using namespace std;
#define file() freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);

const int MAX = 111; // 1..100

struct Queue {
    int arr[MAX*MAX];
    int front, rear;

    Queue(): front(-1), rear(-1) {}

    void enqueue(int value) {
        rear = (rear + 1) % (MAX * MAX);
        arr[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) return int(-1, -1);
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
int map[MAX][MAX], visited[MAX][MAX], Point[MAX];
int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
	cin >> N ;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> map[i][j];
}

int count_components(int N, int map[MAX][MAX], int remove) {

	int visited[MAX] = {0};
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (i == remove || visited[i]) continue;
        // BFS t? ??o i
        count++;
        queue.reset();
        queue.enqueue(Point(i));
        visited[i] = 1;

        while (!queue.isEmpty()) {
            Point cur = queue.dequeue();
            int u = cur;

            for (int v = 1; v <= N; v++) {
                if (v == remove) continue;
                if (map[u-1][v-1] && !visited[v]) {
                    visited[v] = 1;
                    queue.enqueue(v));
                }
            }
        }
    }
    return count;
}

int find_best_cut() {
    int best = 0, best_id = 0;
    for (int k = 1; k <= N; k++) {
        int comps = count_components(N, map, k);
        if (comps > best) {
            best = comps;
            best_id = k;
        }
    }
    // N?u xóa không chia thành >1 thành ph?n (best == 1), in 0
    return (best <= 1) ? 0 : best_id;
}
int main(){
	file();
	int test_case;
	cin >> test_case;
	for( int t = 1; t<=test_case; t++){
		input();
		cout<<find_best_cut()<<endl;
	}
	return 0;
}