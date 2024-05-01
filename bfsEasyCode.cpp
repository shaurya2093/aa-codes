#include <iostream>
#include <queue>

using namespace std;

const int MAX_NODES = 10; // Maximum number of nodes

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix representing the graph
bool visited[MAX_NODES]; // Array to keep track of visited nodes

void bfs(int start, int numNodes) {
    queue<int> q;
    q.push(start);

    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Enqueue all adjacent nodes of the current node
        for (int i = 0; i < numNodes; ++i) {
            if (graph[current][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    // Initialize graph and visited arrays
    for (int i = 0; i < MAX_NODES; ++i) {
        visited[i] = 0;
        for (int j = 0; j < MAX_NODES; ++j) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1; // Assuming undirected graph
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "Breadth-First Search starting from node " << startNode << ": ";
    bfs(startNode, numNodes);
    cout << endl;

    return 0;
}
