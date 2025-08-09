#include <iostream>
using namespace std;

int graph[100][2];      // hai node dang ket noi
int out_deg[100];       // bac cua node
bool visited[100];      // Mang da vieng tham

bool dfs(int node) {
    if (node == 99) return true;
    visited[node] = true;
    for (int i = 0; i < out_deg[node]; i++) {
        int next = graph[node][i];
        if (!visited[next] && dfs(next)) return true;//backtrack
    }
    return false;
}

int main() {
    int T, road_count;
    for (int tc = 1; tc <= 10; tc++) {
        cin >> T >> road_count;
        fill(out_deg, out_deg + 100, 0);
        fill(visited, visited + 100, false);

        for (int i = 0; i < road_count; i++) {
            int from, to;
            cin >> from >> to;
            graph[from][out_deg[from]++] = to;//Chua node ke voi node from
        }

        cout << "#" << T << " " << (dfs(0) ? 1 : 0) << endl;
    }
    return 0;
}