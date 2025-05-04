#include<iostream>
using namespace std;

const int MAX = 100;       // Maximum number of vertices
const int INF = 1e9;       // Represents infinity (for unreachable edges)

int adj[MAX][MAX];         // Adjacency matrix to store edge weights
int key[MAX];              // Stores the minimum weight to connect each vertex to MST
int parent[MAX];           // Stores the parent of each vertex in MST
bool visited[MAX];         // Tracks whether a vertex is included in MST

// Function to initialize graph data structures
void initializeGraph(int n) {
    for(int i = 0; i < n; i++) {
        key[i] = INF;             // Initialize all keys to infinity
        visited[i] = false;       // No vertex visited yet
        parent[i] = -1;           // No parent assigned yet
        for(int j = 0; j < n; j++) {
            adj[i][j] = INF;      // Set all edge weights to INF (no edge)
        }
    }
}

// Function to input edges into the adjacency matrix
void inputEdges(int e) {
    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;       // Undirected graph: add both u->v and v->u
        adj[v][u] = w;
    }
}

// Prim's Algorithm to find Minimum Spanning Tree
void primMST(int n) {
    key[0] = 0;  // Start from vertex 0, so set its key to 0

    // Loop n-1 times to include n-1 edges in MST
    for(int count = 0; count < n - 1; count++) {
        int minKey = INF, u;

        // Find the unvisited vertex with the minimum key value
        for(int i = 0; i < n; i++) {
            if(!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;  // Store index of vertex with min key
            }
        }

        visited[u] = true; // Mark the selected vertex as visited

        // Update key and parent of all adjacent unvisited vertices
        for(int v = 0; v < n; v++) {
            // If there's an edge from u to v, and v is unvisited, and weight is smaller than current key[v]
            if(adj[u][v] != INF && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];    // Update key to smaller edge
                parent[v] = u;         // Set parent of v to u
            }
        }
    }
}

// Function to print the edges in the MST and total weight
void printMST(int n) {
    cout << "\nEdges in MST:\n";
    int totalWeight = 0;
    for(int i = 1; i < n; i++) {
        // Print edge between parent[i] and i with its weight
        cout << parent[i] << " - " << i << " : weight = " << adj[parent[i]][i] << "\n";
        totalWeight += adj[parent[i]][i]; // Add to total weight
    }
    cout << "Total weight of MST = " << totalWeight << "\n";
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Step 1: Initialize the graph structures
    initializeGraph(n);

    // Step 2: Input edges and weights
    inputEdges(e);

    // Step 3: Run Prim's algorithm to find MST
    primMST(n);

    // Step 4: Print the resulting MST
    printMST(n);

    return 0;
}
