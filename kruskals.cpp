#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_VERTICES = 100; 
const int MAX_EDGES = 100;   

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

struct Graph {
    int V, E;          
    Edge edges[MAX_EDGES]; 
};

Graph createGraph(int V, int E) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(Graph graph) {
    int V = graph.V;
    Edge result[V]; 
    int e = 0;  

    sort(graph.edges, graph.edges + graph.E, [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    Subset subsets[MAX_VERTICES];

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int totalCost = 0;
    for (int i = 0; e < V - 1 && i < graph.E; i++) {
        Edge next_edge = graph.edges[i];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
            totalCost += next_edge.weight;
        }
    }

    cout << "Cost of building the MST: " << totalCost << endl;

    cout << "Edges of MST:" << endl;
    for (int i = 0; i < e; i++)
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
}


int main() {
    int V = 4; 
    int E = 5; 
    Graph graph = createGraph(V, E);

    graph.edges[0].src = 0;
    graph.edges[0].dest = 1;
    graph.edges[0].weight = 10;

    graph.edges[1].src = 0;
    graph.edges[1].dest = 2;
    graph.edges[1].weight = 6;

    graph.edges[2].src = 0;
    graph.edges[2].dest = 3;
    graph.edges[2].weight = 5;

    graph.edges[3].src = 1;
    graph.edges[3].dest = 3;
    graph.edges[3].weight = 15;

    graph.edges[4].src = 2;
    graph.edges[4].dest = 3;
    graph.edges[4].weight = 4;

    KruskalMST(graph);

    return 0;
}