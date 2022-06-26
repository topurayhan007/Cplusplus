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
	//Directed graphs
	node* n = new node;
	n->a = dest;
	n->next = g->adj[src];//src is anything between 0-5
	g->adj[src] = n;
}
void printGraph(graph* g) {
	for (int i = 0; i < g->numVertex; ++i) {
		node* n = g->adj[i];
		cout << i << " ";
		while (n != nullptr) {
			cout << n->a << " ";
			n = n->next;
		}
		cout << endl;
	}
}


void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void pathHelper(graph* g, int start,int end, bool*& visited,int *arr, int index, float &sum, float &path) {
	visited[start] = true;
	arr[index] = start; 
	index = index + 1;
	
	if (start == end) {
		int a = index - 1;
		sum = sum + a;
		path++;
		//printArray(arr, index);
		
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			pathHelper(g, n->a, end, visited, arr, index, sum, path);
		}
		n = n->next;
	}
	visited[start] = false;
}

float avgDistDFS(graph* g, int src, int dest) {
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0; float sum = 0; float path = 0;
	pathHelper(g, src, dest, visited, arr, index, sum, path);
    
	return sum/path;

}

int main() {
	//A = 0
	//B = 1
	//C = 2
	//D = 3
	//E = 4
	//F = 5
	//G = 6
	//H = 7

	graph* g = new graph(9);
	addEdge(g, 0, 1);
	addEdge(g, 0, 3);
	addEdge(g, 0, 4);
	addEdge(g, 0, 2);
	addEdge(g, 1, 2);
	addEdge(g, 3, 6);
	addEdge(g, 5, 2);
	addEdge(g, 5, 0);
	addEdge(g, 5, 3);
	addEdge(g, 6, 4);
	addEdge(g, 6, 7);
	addEdge(g, 7, 4);
	addEdge(g, 7, 5);
	addEdge(g, 7, 2);
	
	//A(0) -> E(4)

	cout<<"Average Distance is = "<<avgDistDFS(g,0,4)<<endl;
	
	return 0;
}
