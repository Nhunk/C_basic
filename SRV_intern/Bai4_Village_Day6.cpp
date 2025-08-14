// Level 3
// L�ng m?c
// Cho b?n ?? m?ng l??i giao th�ng gi?a c�c l�ng m?c. M?t v�ng ???c ??nh ngh?a l� m?t t?p h?p c�c l�ng m� t? b?t k? m?t l�ng n�o trong v�ng ??u c� th? ?i ??n m?t l�ng kh�c trong v�ng.
// H�y t�nh s? v�ng trong b?n ??, s? l�ng c� l?p (l�ng kh�ng c� ???ng ?i ??n b?t k? l�ng kh�c) v� s? con ???ng ?�ng vai tr� l� �C?u� gi?a hai v�ng (n?u b? con ???ng n�y ?i th� s? l??ng v�ng t?ng l�n 1).
// Input:
// D�ng ??u c� m?t s? T l� s? l??ng test c?a file input. M?i test ???c b? c?c nh? sau: d�ng ??u l� m?t s? nguy�n d??ng N (N <= 300) N l� s? l�ng, ti?p theo l� m?t ma tr�n A[i, j] trong ?� A[i][j] c� gi� tr? b?ng 1 l� c� ???ng ?i t? l�ng i t?i l�ng j v� 0 n?u kh�ng c� ???ng t? l�ng i t?i l�ng j. D? li?u ??m b?o n?u c� ???ng t? l�ng i t?i l�ng j th� c?ng s? c� ???ng ng??c l?i.
// Output
// V?i m?i test, in ra s?v�ng c� tr�n b?n ??, s? l�ng c� l?p v� s? ???ng ?�ng vai tr� l� c?u.
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

// DFS t�m v�ng
void dfs_region(int u) {
    visited[u] = 1;
    for (int v = 1; v <= N; v++) {
        if (A[u][v] && !visited[v]) {
            dfs_region(v);
        }
    }
}

// DFS t�m c?u
void dfs_bridge(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeDFS;

    for (int v = 1; v <= N; v++) {
        if (!A[u][v]) continue; // kh�ng c� c?nh

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

        // 1. ??m s? v�ng
        for (int i = 1; i <= N; i++) visited[i] = 0;
        int region_count = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs_region(i);
                region_count++;
            }
        }

        // 2. ??m s? l�ng c� l?p
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


