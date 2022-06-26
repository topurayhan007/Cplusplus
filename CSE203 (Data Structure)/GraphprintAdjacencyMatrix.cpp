#include <iostream>
#include <queue>
#include <stack>

using namespace std;
struct node {
	int a = 0;
	node* next = nullptr;
};
struct graph {
	int numVertex = 0;
	node** adj = nullptr;
	graph(int numV) {
		numVertex = numV;
		adj = new node * [numVertex];
		for (int i = 0; i < numVertex; ++i) {
			adj[i] = nullptr;
		}
	}
};

void addEdge(graph* g, int src, int dest) {
	node* n = new node;
	n->a = dest;
	n->next = g->adj[src];
	g->adj[src] = n;
}

void freeMemory(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
	}
}
void printAdjacencyMatrix(graph* g) {
    int** arr = new int* [g->numVertex];
    for (int i = 0; i < g->numVertex; ++i) {
        arr[i] = new int[g->numVertex];
    }
    for (int i = 0; i < g->numVertex; ++i) {
        for (int j = 0; j < g->numVertex; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < g->numVertex; ++i){
        node* n = g->adj[i];
        while (n != NULL) {
            arr[i][n->a] = 1;
            n = n->next;
        }
    }
    cout<<"   | ";
    for (int i = 0; i < g->numVertex; ++i) {
    	cout<<i<<" ";
    }
    cout<<endl;
    for (int i = 0; i < (4+(2*g->numVertex)); ++i) {
    	if(i==3){
    		cout<<"|";
    	}
    	else{
    		cout<<"_";
    	}
    }
    cout<<endl;
    for (int i = 0; i < g->numVertex; ++i) {
        cout << i << "  | ";
        for (int j = 0; j < g->numVertex; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    freeMemory(arr, g->numVertex);
}

int main() {
	graph* g = new graph(9);
	addEdge(g, 0, 1);
	addEdge(g, 0, 7);
	addEdge(g, 0, 8);
	addEdge(g, 1, 8);
	addEdge(g, 2, 8);
	addEdge(g, 2, 4);
	addEdge(g, 3, 2);
	addEdge(g, 5, 8);
	addEdge(g, 5, 3);
	addEdge(g, 5, 4);
	addEdge(g, 6, 5);
	addEdge(g, 7, 6);
	addEdge(g, 7, 5);
	addEdge(g, 8, 3);

	cout<<"     Adjacency Matrix"<<endl<<endl; 
	printAdjacencyMatrix(g); cout<<endl;

	return 0;
}
