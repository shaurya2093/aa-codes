#include <iostream>
#include <stack>
using namespace std;
#define MAX 20

class graphnode{
    int vertex;
    int weight;
    graphnode *next;
    public:
    graphnode(int n=0, int w=0){
        vertex=n;
        weight=w;
        next=NULL;
    }
    friend class listgraph;
};

class listgraph{
    graphnode *list[MAX];
    int n;
    public:
    listgraph(int nov){
        n=nov;
        for(int j=0; j<n;j++)
            list[j]=NULL;
    }
    void create();
    void display();
    void prims();
};

void listgraph::create(){
    int i, j;
    graphnode *temp, *newnode;
    char ans;
    for(i=0; i<n;i++){
        for(j=0;j<n;j++){
            if (i==j){
                continue;
            }
            cout<<"\nIs there an edge between vertex " << i+1<<" and "<<j+1 <<"? ";
            cin>>ans;

            if (ans=='y' || ans=='Y'){
                int weight;
                cout << "Enter the weight of the edge: ";
                cin >> weight;
                newnode=new graphnode(j+1, weight);
                if(list[i]==NULL)
                    list[i]=temp=newnode;
                else{
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}

void listgraph::display(){
    graphnode *temp;
    int i;
    for(i=0;i<n;i++){
        cout << endl;
        cout<< "V" << i+1 << " -> ";
        temp=list[i];
        while(temp!=NULL){
            cout<< "v" <<temp->vertex<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
}

void listgraph::prims()
{
    int T[MAX], mincost = 0, u, v, min;
    for (int i = 0; i < n; i++){
        T[i] = 0;
    }
        T[0] = 1;

    for (int k = 1; k < n; k++){ 
        min = 100;
        for (int i = 0; i < n; i++){
            if (T[i] != 0){
                graphnode* temp = list[i];
                while (temp != NULL){
                    int j = temp->vertex - 1;
                    if (T[j] == 0 && temp->weight < min){
                        min = temp->weight;
                        u = i;
                        v = j;
                    }
                    temp = temp->next;
                }
            }
        }
        if (min == INT_MAX){
            cout << "\n\nNo spanning tree exists.";
            return;
        }
        T[v] = u+1;
    }
    cout << "\nEdges in spanning tree:\n";
    for (int i = 1; i < n; i++){
        cout << T[i] << " - " << i+1 << endl;
    }
}

int main(){
    int n;
    cout << "Enter the number of vertices: ";

    cin >> n;
    listgraph g(n);
    g.create();
    g.display();
    g.prims();
    return 0;
}