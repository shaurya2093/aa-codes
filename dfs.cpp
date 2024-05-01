#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10

using namespace std;

class GraphNode{
    public:
    int vertex, status;
    GraphNode *next;
        GraphNode(int n){
            vertex=n;
            next=NULL;
            status=0;
        }
};

class ListGraph{
    public:
    GraphNode *list[MAX],*temp;
    int n;
        ListGraph(int nov){ 
            n=nov;
            for(int j=0; j<n; j++){
                list[j]=NULL;
            }
            temp=NULL;
        }
        void create();
        void display();
        void dfs();
};

void ListGraph::create(){
    char ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            cout<<"is there edge between vertex "<<i+1<<" and "<<j+1<<"?";
            cin>>ans;
            if(ans=='y'){
                GraphNode *newnode = new GraphNode(j+1);
                if(list[i]==NULL){
                    list[i]=temp=newnode;
                }
                else{
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}

void ListGraph::display(){
    for(int i=0;i<n;i++){
        cout<<"\nvertex "<<i+1<<"-> ";
        temp=list[i];
        while(temp!=NULL){
            cout<<"v"<<temp->vertex<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
}

void ListGraph::dfs(){
    int visited[MAX]={0};
    int stack[20], top=-1;
    int v=0;
    stack[++top]=v;
    while(top!=-1){
        v=stack[top--];
        if(visited[v]==0){
            visited[v]=1;
            cout<<v+1<<" ";
            temp=list[v];
            while(temp!=NULL){
                int w = temp->vertex-1;
                if(visited[w]==0){
                    stack[++top]=w;
                }
                temp=temp->next;
            }
        }
    }
}

int main(){
    int sw,n=1,nov;
    cout<<"enter number of vertices: ";
    cin>>nov;
    ListGraph l(nov);
    while(n==1){
        cout<<"1. create\n2. display\n3. DFS traversal\nEnter your choice: ";
        cin>>sw;
        switch(sw){
            case 1:
                l.create();
                break;
            case 2:
                l.display();
                break;
            case 3:
                l.dfs();
                break;
            default:
                cout<<"Enter valid choice: ";
        }
        cout<<"\nenter 1 to continue: ";
        cin>>n;
    }
}