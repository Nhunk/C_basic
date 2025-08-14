#include <iostream>
using namespace std;

const int MAXN = 305;
int N;
int A[MAXN][MAXN];
int visited[MAXN];
int disc[MAXN], low[MAXN];
int timeDFS;
int bridges;

// DFS tìm vùng
void dfs_region(int u) {
    visited[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (A[u][v] && !visited[v]) {
            dfs_region(v);
        }
    }
}

// DFS tìm c?u
void dfs_bridge(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeDFS;

    for (int v = 1; v <= N; v++) {
        if (!A[u][v]) continue; // không có c?nh

        if (!visited[v]) {
            dfs_bridge(v, u);
            if (low[v] > disc[u]) {
                bridges++;
            }
            if (low[v] < low[u]) low[u] = low[v];
        }
        else if (v != parent) {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> A[i][j];
            }
        }

        // 1. ??m s? vùng
        for (int i = 1; i <= N; i++) visited[i] = 0;
        int region_count = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs_region(i);
                region_count++;
            }
        }

        // 2. ??m s? làng cô l?p
        int isolated = 0;
        for (int i = 1; i <= N; i++) {
            int deg = 0;
            for (int j = 1; j <= N; j++) deg += A[i][j];
            if (deg == 0) isolated++;
        }

        // 3. ??m s? c?u
        for (int i = 1; i <= N; i++) visited[i] = 0;
        bridges = 0;
        timeDFS = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs_bridge(i, -1);
            }
        }

        cout << region_count << " " << isolated << " " << bridges << "\n";
    }
    return 0;
}
