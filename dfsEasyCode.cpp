#include <iostream>
#include <stack>

using namespace std;

const int MAX_NODES = 7; // Maximum number of nodes

int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix representing the graph
bool visited[MAX_NODES]; // Array to keep track of visited nodes

void dfs(int start, int numNodes) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = 1;

            // Push all adjacent nodes of the current node onto the stack
            for (int i = 0; i < numNodes; ++i) {
                if (graph[current][i] && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;
    
    for (int i = 0; i < MAX_NODES; ++i) {
        visited[i] = 0;
        for (int j = 0; j < MAX_NODES; ++j) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter the edges (format: from to):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    int startNode;
    cout << "Enter the starting node for DFS: ";
    cin >> startNode;

    cout << "Depth-First Search starting from node " << startNode << ": ";
    dfs(startNode, numNodes);
    cout << endl;

    return 0;
}