/*
An uniform distribution of an n xn square array of cells is a partition of the n*n cells in the array inexactly n sets, each one with n contiguous cells. Two cells are contiguous when they have a common side.

A good uniform distribution is composed of contiguous regions. The figures show a good and a wrong uniform distribution for a 5 x 5 square:

Note that in the second example the cells labeled with 4 describe three non-contiguous regions and cells labeled with 5describe two non-contiguous regions. You must write a program that evaluates if an uniform distribution of the cells in a square array is good or not. 

 

Input

﻿The first line contains the number of test cases.  Test cases follow in next lines.

It is understood that a cell in an n x n square array is denoted by a pair (i, j),with 1 <= i  , j<= n. The input file contains several test cases. Each test case begins with a line indicating n, 0100,the side of the square array to be partitioned. Next, there are n-1 lines, each one corresponding to one partition of the cells of the square, with some non-negative integer numbers. Consecutive integers in a line are separated with a single blank character. A line of the form 

a1 a2 a3 a4…

means that cells denoted with the pairs (a1,a2),(a3, a4), ... belong to one of the areas in the partition.

The last area in the partition is defined by those cells not mentioned in the n- 1 given lines.

 

Output

For each test case ‘good’ must be printed if the uniform distribution is good, in other case, ‘wrong’ must be

printed. The answers for the different cases must preserve the order of the input.  The first output line for each test case should be "Case #tn", where tn is the test case number.

 

Sample

Input

3

2

1 2 2 1

5

1 1 1 2 1 3 3 2 2 2

2 1 4 2 4 1 5 1 3 1

4 5 5 2 5 3 5 5 5 4

2 5 3 4 3 5 4 3 4 4

5

1 1 1 2 1 3 3 2 2 2

2 1 3 1 4 1 5 1 4 2

4 5 5 2 5 3 5 5 5 4

2 4 1 4 3 5 4 3 4 4

  

Output

Case #1

wrong

Case #2

good

Case #3

wrong
*/
#include <iostream>
#define MAX 100

using namespace std;

int T, N;
int map[MAX][MAX];  
int visited[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0,-1, 1 };

void reset_map(int n) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            map[i][j] = 0;
}

void reset_visited(int n) {
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = 0;
}

void mark_area(int area, int points[], int len) {
    for(int i=0; i<len/2; i++) {
        int x = points[2*i] - 1;
        int y = points[2*i+1] - 1;
        map[x][y] = area;
    }
}

// Duyệt DFS kiểm tra liên thông
void dfs(int x, int y, int label, int n) {
    visited[x][y] = 1;
    for(int k=0; k<4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny] && map[nx][ny]==label)
            dfs(nx, ny, label, n);
    }
}

int check_connected(int label, int n) {
    reset_visited(n);
    int cnt_block = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(map[i][j]==label && !visited[i][j]) {
                dfs(i, j, label, n);
                cnt_block++;
            }
    return cnt_block==1; // chỉ 1 khối liên thông
}

int main() {
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        cin >> N;
        reset_map(N);

        // Đánh dấu n-1 vùng
        int total_cells = N*N;
        int used[MAX][MAX] = {0};
        for(int area=1; area<=N-1; area++) {
            int points[2*MAX];
            int len = 0;
            string line;
            // Đọc hết dòng
            while(len < 2*N) {
                int v;
                cin >> v;
                points[len++] = v;
                if(cin.peek()=='\n' || len%2==0 && len>=2*N) break;
            }
            mark_area(area, points, len);
            // Đánh dấu đã dùng
            for(int i=0; i<len/2; i++)
                used[points[2*i]-1][points[2*i+1]-1] = 1;
        }

        // Vùng cuối: những ô chưa xuất hiện
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(!map[i][j])
                    map[i][j] = N;

        // Kiểm tra liên thông từng vùng
        int good = 1;
        for(int v=1; v<=N; v++) {
            if(!check_connected(v, N)) {
                good = 0;
                break;
            }
        }

        cout << "Case #" << tc << endl;
        if(good) cout << "good\n";
        else cout << "wrong\n";
    }
    return 0;
}