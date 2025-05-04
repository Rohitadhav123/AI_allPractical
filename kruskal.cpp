#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of edges or vertices

// Structure to represent an edge of the graph
struct Edge {
    int u, v, weight; // u and v are the vertices, weight is the edge weight
};

// Function to find the parent of a node (used in Disjoint Set Union - DSU)
int findParent(int parent[], int i) {
    // Keep going up until we find the root of the set
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to unite two subsets (used in DSU)
void unionSets(int parent[], int u, int v) {
    // Find parents of both vertices
    int uParent = findParent(parent, u);
    int vParent = findParent(parent, v);
    // Set one parent as parent of the other (join the sets)
    parent[uParent] = vParent;
}

int main() {
    int V, E; // V = number of vertices, E = number of edges
    Edge edges[MAX]; // Array to store all edges

    // Taking user input for number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // Taking user input for each edge: (u, v, weight)
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Step 1: Sort all edges in ascending order based on weight using bubble sort
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Swap edges[j] and edges[j + 1]
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Step 2: Initialize parent array for DSU
    int parent[MAX];
    for (int i = 0; i < V; i++) {
        parent[i] = i; // Initially, each vertex is its own parent
    }

    // Step 3: Process edges and build MST
    cout << "\nEdges in MST:\n";
    int mstWeight = 0; // To store total weight of MST

    // Loop through sorted edges, pick smallest edge that doesn't form a cycle
    for (int i = 0, count = 0; count < V - 1 && i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // Find parents of u and v
        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        // If including this edge does NOT form a cycle
        if (uParent != vParent) {
            // Include this edge in MST
            cout << u << " - " << v << " = " << w << endl;
            mstWeight += w;
            // Join the sets
            unionSets(parent, u, v);
            count++; // One more edge added to MST
        }
    }

    // Print total weight of MST
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}
