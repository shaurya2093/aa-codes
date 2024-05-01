#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

using namespace std;

class GraphNode {
public:
    int vertex, status;
    GraphNode* next;
    GraphNode(int n) {
        vertex = n;
        next = NULL;
        status = 0;
    }
};

class ListGraph {
public:
    GraphNode* list[MAX], * temp;
    int n;
    ListGraph(int nov) {
        n = nov;
        for (int j = 0; j < n; j++) {
            list[j] = NULL;
        }
        temp = NULL;
    }
    void create();
    void display();
    void bfs();
};

void ListGraph::create() {
    char ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            cout << "Is there an edge between vertex " << i + 1 << " and " << j + 1 << "? ";
            cin >> ans;
            if (ans == 'y') {
                GraphNode* newnode = new GraphNode(j + 1);
                if (list[i] == NULL) {
                    list[i] = temp = newnode;
                }
                else {
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
    }
}

void ListGraph::display() {
    for (int i = 0; i < n; i++) {
        cout << "\nVertex " << i + 1 << "-> ";
        temp = list[i];
        while (temp != NULL) {
            cout << "v" << temp->vertex << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
}

void ListGraph::bfs() {
    int visited[MAX] = { 0 };
    int queue[MAX];
    int front = -1, rear = -1;
    int v = 0;
    queue[++rear] = v;
    visited[v] = 1;

    while (front != rear) {
        v = queue[++front];
        cout << v + 1 << " ";
        temp = list[v];
        while (temp != NULL) {
            int w = temp->vertex - 1;
            if (visited[w] == 0) {
                queue[++rear] = w;
                visited[w] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int sw, n = 1, nov;
    cout << "Enter the number of vertices: ";
    cin >> nov;
    ListGraph l(nov);
    while (n == 1) {
        cout << "\n1. Create\n2. Display\n3. BFS Traversal\nEnter your choice: ";
        cin >> sw;
        switch (sw) {
        case 1:
            l.create();
            break;
        case 2:
            l.display();
            break;
        case 3:
            l.bfs();
            break;
        default:
            cout << "Enter a valid choice.";
        }
        cout << "\nEnter 1 to continue: ";
        cin >> n;
    }
}
