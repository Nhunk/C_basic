#include <iostream>
using namespace std;

const int MAXN = 55;
const int MAXQ = 3000;

int N, M;
int map[MAXN][MAXN];
bool visited[MAXN][MAXN];
int sr, sc, gr, gc;

int queueR[MAXQ], queueC[MAXQ];

inline bool inside(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

bool canReach(int h) {
  
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            visited[i][j] = false;

    int f = 0, r = 0;
    queueR[r] = sr; queueC[r] = sc; ++r;
    visited[sr][sc] = true;

    while (f < r) {
        int cr = queueR[f], cc = queueC[f]; ++f;
        if (cr == gr && cc == gc) return true;

        
        int nc = cc - 1;
        if (inside(cr, nc) && !visited[cr][nc] && map[cr][nc] != 0) {
            visited[cr][nc] = true;
            queueR[r] = cr; queueC[r] = nc; ++r;
        }
        nc = cc + 1;
        if (inside(cr, nc) && !visited[cr][nc] && map[cr][nc] != 0) {
            visited[cr][nc] = true;
            queueR[r] = cr; queueC[r] = nc; ++r;
        }

    
        for (int k = 1; k <= h; ++k) {
            int nr = cr - k;
            if (nr < 0) break;
            if (!visited[nr][cc] && map[nr][cc] != 0) {
                visited[nr][cc] = true;
                queueR[r] = nr; queueC[r] = cc; ++r;
            }
        }
     
        for (int k = 1; k <= h; ++k) {
            int nr = cr + k;
            if (nr >= N) break;
            if (!visited[nr][cc] && map[nr][cc] != 0) {
                visited[nr][cc] = true;
                queueR[r] = nr; queueC[r] = cc; ++r;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> M;
        sr = sc = gr = gc = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> map[i][j];
                if (map[i][j] == 2) { sr = i; sc = j; map[i][j] = 1; } // coi nh? ô ?i ???c
                if (map[i][j] == 3) { gr = i; gc = j; map[i][j] = 1; } // coi nh? ô ?i ???c
            }
        }

        int lo = 0, hi = N - 1, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canReach(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << "Case #" << tc << "\n";
        cout << ans << "\n";
    }
    return 0;
}