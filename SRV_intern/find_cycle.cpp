/*
Given a directed graph, check whether the graph contains a cycle or not. 
Your function should return 1 if the given graph contains at least one cycle, else return 0. 
*/

#include <iostream>
using namespace std;

const int MAXV = 105; // Số đỉnh tối đa
int adj[MAXV][MAXV];  // Ma trận kề 
int visited[MAXV], recStack[MAXV];
int V;

bool dfs(int u) {
    visited[u] = 1;
    recStack[u] = 1;
    for (int v = 1; v <= V; ++v) {
        if (adj[u][v]) {
            if (!visited[v]) {
                if (dfs(v)) return true;
            } else if (recStack[v]) {
                return true; // Có chu trình
            }
        }
    }
    recStack[u] = 0;
    return false;
}

int isCyclic() {
    for (int i = 1; i <= V; ++i) {
        visited[i] = 0;
        recStack[i] = 0;
    }
    for (int i = 1; i <= V; ++i) {
        if (!visited[i]) {
            if (dfs(i)) return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int test_cases = 1; test_cases <= T; test_cases++) {
        int E;
        cin >> V >> E;
        // Khởi tạo ma trận kề
        for (int i = 1; i <= V; ++i)
            for (int j = 1; j <= V; ++j)
                adj[i][j] = 0;

        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
        }
        cout << "Case #" << test_cases << endl;
        cout << isCyclic() << endl;
    }
    return 0;
}