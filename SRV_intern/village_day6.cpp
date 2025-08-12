// Level 3
// Làng mạc
// Cho bản đồ mạng lưới giao thông giữa các làng mạc. Một vùng được định nghĩa là một tập hợp các làng mà từ bất kỳ một làng nào trong vùng đều có thể đi đến một làng khác trong vùng.
// Hãy tính số vùng trong bản đồ, số làng cô lập (làng không có đường đi đến bất kỳ làng khác) và số con đường đóng vai trò là “Cầu” giữa hai vùng (nếu bỏ con đường này đi thì số lượng vùng tăng lên 1).
// Input:
// Dòng đầu có một số T là số lượng test của file input. Mỗi test được bố cục như sau: dòng đầu là một số nguyên dương N (N <= 300) N là số làng, tiếp theo là một ma trân A[i, j] trong đó A[i][j] có giá trị bằng 1 là có đường đi từ làng i tới làng j và 0 nếu không có đường từ làng i tới làng j. Dữ liệu đảm bảo nếu có đường từ làng i tới làng j thì cũng sẽ có đường ngược lại.
// Output
// Với mỗi test, in ra sốvùng có trên bản đồ, số làng cô lập và số đường đóng vai trò là cầu.
// Sample
// Input
// 2
// 5
// 0 1 0 1 0
// 1 0 0 1 0
// 0 0 0 0 1
// 1 1 0 0 0
// 0 0 1 0 0
// 7
// 0 0 0 1 0 0 1
// 0 0 0 1 0 0 0
// 0 0 0 0 1 0 0
// 1 1 0 0 0 0 1
// 0 0 1 0 0 0 0
// 0 0 0 0 0 0 0
// 1 0 0 1 0 0 0
// Output
// 2 0 1
// 3 1 2


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

// DFS tìm cầu
void dfs_bridge(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeDFS;

    for (int v = 1; v <= N; v++) {
        if (!A[u][v]) continue; // không có cạnh

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

        // 1. Đếm số vùng
        for (int i = 1; i <= N; i++) visited[i] = 0;
        int region_count = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs_region(i);
                region_count++;
            }
        }

        // 2. Đếm số làng cô lập
        int isolated = 0;
        for (int i = 1; i <= N; i++) {
            int deg = 0;
            for (int j = 1; j <= N; j++) deg += A[i][j];
            if (deg == 0) isolated++;
        }

        // 3. Đếm số cầu
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


