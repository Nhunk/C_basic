#include <iostream>
using namespace std;

const int MAXN = 505;
const int MAXQ = 250000 + 10;

struct IntQueue {
    int a[MAXQ];
    int f, r;
    IntQueue(): f(0), r(0) {}
    inline bool empty() const { return f == r; }
    inline void clear() { f = r = 0; }
    inline void push(int x) { a[r++] = x; } 
    inline int pop() { return a[f++]; }
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m, r1, c1, r2, c2;
        cin >> n >> m >> r1 >> c1 >> r2 >> c2;


        if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= m || r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) {
            cout << "NO\n";

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) { char dummy; cin >> dummy; }
            continue;
        }

        static char grid[MAXN][MAXN];
        static bool vis[MAXN][MAXN];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                vis[i][j] = false;
            }

        IntQueue q;
        for (int d = 0; d < 4; ++d) {
            int nr = r1 + dr[d], nc = c1 + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                vis[nr][nc] = true;
                q.push(nr * m + nc);
            }
        }
        while (!q.empty()) {
            int id = q.pop();
            int r = id / m, c = id % m;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    q.push(nr * m + nc);
                }
            }
        }

        int cnt = 0;
        for (int d = 0; d < 4; ++d) {
            int nr = r2 + dr[d], nc = c2 + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (vis[nr][nc]) ++cnt;
            else if (nr == r1 && nc == c1) ++cnt; 
        }

        bool ans = false;
        if (r1 == r2 && c1 == c2) {
            ans = (cnt >= 1);
        } else if (grid[r2][c2] == '0') {
            ans = (cnt >= 1);
        } else { // grid[r2][c2] == '1'
            ans = (cnt >= 2);
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}
