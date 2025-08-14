#include <iostream>
using namespace std;

int main() {
    const int MAXN = 1005;
    const int MAXH = 10005;
    int N, M, H;//Tong so dao, dao co dien va so cac ket noi giua hai dao
    int adj[MAXN][MAXN]; // Ma tr?n k?
    int weak[MAXN];
    int queue[MAXN * 10];
    
    int T;
    cin >> T;
    for (int test = 1; test <=T; ++test) {
        cin >> N >> M >> H;

        // Reset ma tr?n k?
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                adj[i][j] = 0;
                
        //Nhap dao co may phat dien
        int power[MAXN];
        for (int i = 0; i < M; ++i) cin >> power[i];

        // Nhap cac ket noi
        for (int i = 0; i < H; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        // Kh?i t?o m?ng weak
        for (int i = 0; i < N; ++i)
            weak[i] = -1;

        // BFS ?a ngu?n b?ng m?ng queue
        int head = 0, tail = 0;
        for (int i = 0; i < M; ++i) {
            weak[power[i]] = 0;
            queue[tail++] = power[i];
        }
        while (head < tail) {
            int u = queue[head++];
            for (int v = 0; v < N; ++v) {
                if (adj[u][v] && weak[v] == -1) {
                    weak[v] = weak[u] + 1;
                    queue[tail++] = v;
                }
            }
        }

        // Tìm ??o y?u nh?t
        int max_weak = -1, ans_id = -1;
        bool has_infinity = false;
        for (int i = 0; i < N; ++i) {
            if (weak[i] == -1) {
                if (!has_infinity || i < ans_id) {
                    has_infinity = true;
                    ans_id = i;
                }
            } else if (!has_infinity) {
                if (weak[i] > max_weak || (weak[i] == max_weak && i < ans_id)) {
                    max_weak = weak[i];
                    ans_id = i;
                }
            }
        }
        cout << "#"<<test<<" "<<ans_id << endl;
    }
    return 0;
}