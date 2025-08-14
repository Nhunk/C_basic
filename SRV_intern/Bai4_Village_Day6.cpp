// Level 3
// Làng m?c
// Cho b?n ?? m?ng l??i giao thông gi?a các làng m?c. M?t vùng ???c ??nh ngh?a là m?t t?p h?p các làng mà t? b?t k? m?t làng nào trong vùng ??u có th? ?i ??n m?t làng khác trong vùng.
// Hãy tính s? vùng trong b?n ??, s? làng cô l?p (làng không có ???ng ?i ??n b?t k? làng khác) và s? con ???ng ?óng vai trò là “C?u” gi?a hai vùng (n?u b? con ???ng này ?i thì s? l??ng vùng t?ng lên 1).
// Input:
// Dòng ??u có m?t s? T là s? l??ng test c?a file input. M?i test ???c b? c?c nh? sau: dòng ??u là m?t s? nguyên d??ng N (N <= 300) N là s? làng, ti?p theo là m?t ma trân A[i, j] trong ?ó A[i][j] có giá tr? b?ng 1 là có ???ng ?i t? làng i t?i làng j và 0 n?u không có ???ng t? làng i t?i làng j. D? li?u ??m b?o n?u có ???ng t? làng i t?i làng j thì c?ng s? có ???ng ng??c l?i.
// Output
// V?i m?i test, in ra s?vùng có trên b?n ??, s? làng cô l?p và s? ???ng ?óng vai trò là c?u.
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


