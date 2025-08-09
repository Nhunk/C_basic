/*
The problem is to investigate whether there is a route from point A to point B depicted in a map as the figure shows. There can be up to two crossroads. 
All roads are one way and cannot be returned.
Create a program to determine if there is a route from point A to point B when the roads are given.
- Points A and B are fixed with numbers 0 and 99, respectively.
- All roads are expressed in a number pair. In the example above, the roads starting from number 2 can be expressed in (2, 5) and (2, 9).
- The route exists if there is at least one route.
- One cannot go against the arrow direction.
﻿[Input]
The first line of the input file provides the test case number and the total number of roads. The next line contains the sequence pairs.
The sequence pairs are not separately displayed. They are paired in the listed sequence.
.[Output]
Output the answer to each test case. Each line begins with ‘#x’ followed by a space and then the next answer. Output “1” if the route exists and “0” if not.
Here, x is the test case number.
*/
#include <iostream>
using namespace std;

int main() {
    int T, numRoads;
    for (int test = 1; test <= 10; ++test) { // up to 10 test cases
        cin >> T >> numRoads;
        int adj[100][2];      // each node has up to 2 outgoing roads
        int adj_count[100];   // count of outgoing roads
        int visited[100];

        // Initialize
        for (int i = 0; i < 100; ++i) {
            adj_count[i] = 0;
            visited[i] = 0;
        }

        // Input roads
        for (int i = 0; i < numRoads; ++i) {
            int from, to;
            cin >> from >> to;
            adj[from][adj_count[from]++] = to;
        }

        // DFS stack
        int stack[100], top = -1;
        stack[++top] = 0; // start from node 0
        visited[0] = 1;
        int found = 0;

        while (top >= 0) {
            int curr = stack[top--];
            if (curr == 99) {//Da tim thay
                found = 1;
                break;
            }
            for (int i = 0; i < adj_count[curr]; ++i) {
                int next = adj[curr][i];
                if (!visited[next]) {
                    stack[++top] = next;
                    visited[next] = 1;
                }
            }
        }

        cout << "#" << T << " " << found << endl;
    }
    return 0;
}