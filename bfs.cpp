#include <iostream>
using namespace std;

const int MAX = 100;
int adj[MAX][MAX];
bool visited[MAX];
int n, e;

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
    }

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "BFS Traversal: ";
    bfs(start);

    return 0;
}
