#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 20

class edge {
public:
    int src, dest, weight;
};

class listgraph{
    edge edges[MAX];
    int n, e;
    public:
    listgraph(int nov, int noe){
        n = nov;
        e = noe;
    }
    void create();
    void display();
    void kruskals();
};

bool compareEdges(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

void listgraph::create(){
    for(int i = 0; i < e; i++) {
        cout << "Enter source, destination, and weight of edge " << i+1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
}

void listgraph::display(){
    cout << "Edges in the graph:\n";
    for(int i = 0; i < e; i++) {
        cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
    }
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void listgraph::kruskals() {
    edge result[n];
    int parent[n];
    int i = 0, e = 0;

    sort(edges, edges + this->e, compareEdges);

    fill(parent, parent + n, -1);

    while (e < n - 1 && i < this->e) {
        edge next_edge = edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    if (e < n - 1) {
        cout << "\nNo spanning tree exists.";
        return;
    }

    cout << "\nEdges in spanning tree:\n";
    for (int i = 0; i < e; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
}

int main(){
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    listgraph g(n, e);
    g.create();
    g.display();
    g.kruskals();
    return 0;
}
