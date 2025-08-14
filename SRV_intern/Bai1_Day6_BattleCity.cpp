#include <iostream>

using namespace std;


const int MAX_SIZE = 305;
const int INF = 20040402;


char maze[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];


struct step {
    int cost, r, c;
};

step pq_heap[MAX_SIZE * MAX_SIZE];
int pq_size;

void swap_items(int i, int j) {
    step temp = pq_heap[i];
    pq_heap[i] = pq_heap[j];
    pq_heap[j] = temp;
}

void push(int cost, int r, int c) {
    pq_heap[pq_size] = {cost, r, c};
    int current = pq_size;
    pq_size++;
    while (current > 0 && pq_heap[current].cost < pq_heap[(current - 1) / 2].cost) {
        swap_items(current, (current - 1) / 2);
        current = (current - 1) / 2;
    }
}

step pop() {
    step item = pq_heap[0];
    pq_heap[0] = pq_heap[pq_size - 1];
    pq_size--;
    int current = 0;
    while (true) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;
        if (left < pq_size && pq_heap[left].cost < pq_heap[smallest].cost) {
            smallest = left;
        }
        if (right < pq_size && pq_heap[right].cost < pq_heap[smallest].cost) {
            smallest = right;
        }
        if (smallest != current) {
            swap_items(current, smallest);
            current = smallest;
        } else {
            break;
        }
    }
    return item;
}

bool pq_is_empty() {
    return pq_size == 0;
}


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int m, n;
    cin >> m >> n;
    
    int start_r, start_c, target_r, target_c;

    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maze[i][j];
            dist[i][j] = INF;
            if (maze[i][j] == 'Y') {
                start_r = i;
                start_c = j;
            } else if (maze[i][j] == 'T') {
                target_r = i;
                target_c = j;
            }
        }
    }

    // Initialize Dijkstra's 
    pq_size = 0;
    dist[start_r][start_c] = 0;
    push(0, start_r, start_c);

    int min_turns = -1;

    //Dijkstra's 
    while (!pq_is_empty()) {
        step current = pop();
        int cost = current.cost;
        int r = current.r;
        int c = current.c;

        if (cost > dist[r][c]) {
            continue;
        }

        if (r == target_r && c == target_c) {
            min_turns = cost;
            break;
        }

        // move
        for (int i = 0; i < 4; ++i) {
            int nx = r + dx[i];
            int ny = c + dy[i];

            // ktra trong map
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int new_cost = INF;

                // di chuyen
                if (maze[nx][ny] == 'E' || maze[nx][ny] == 'T') {
                    new_cost = cost + 1;
                }
                // ban + move
                else if (maze[nx][ny] == 'B') {
                    new_cost = cost + 2;
                }
                
                // Update distanye
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    push(new_cost, nx, ny);
                }
            }
        }
    }

    cout << min_turns << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << endl;
        solve();
    }

    return 0;
}
