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
void bfs(graph* g, int start) {
	queue<int> q;
	q.push(start);
	int numNodesEachLevel = 1;
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	visited[start] = true;


	while (!q.empty()) {
		int p = q.front();
		q.pop();
		numNodesEachLevel -= 1;
		cout << p << " ";

		node* n = g->adj[p];
		while (n != nullptr) {
			if (visited[n->a] == false) {
				visited[n->a] = true;
				q.push(n->a);
			}
			n = n->next;
		}
		if (numNodesEachLevel == 0) {
			numNodesEachLevel = q.size();
			cout << endl;
		}
	}
}
void dfs(graph* g, int start) {
	stack<int> st;
	st.push(start);

	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	visited[start] = true;


	while (!st.empty()) {
		int p = st.top();
		st.pop();

		cout << p << " ";

		node* n = g->adj[p];
		while (n != nullptr) {
			if (visited[n->a] == false) {
				visited[n->a] = true;
				st.push(n->a);
			}
			n = n->next;
		}
	}
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void dfs_arrayHelper(graph* g, int start,int end, bool*& visited,int *arr, int index) {
	visited[start] = true;
	//cout << start << " ";
	arr[index] = start; 
	index = index + 1;
	if (start == end) {
		printArray(arr, index);
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			dfs_arrayHelper(g, n->a, end, visited, arr, index);
		}
		n = n->next;
	}
	visited[start] = false;
}

void dfs_array(graph* g, int start, int end) {
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0;
	dfs_arrayHelper(g, start,end , visited, arr, index);
}

void pathHelper(graph* g, int start,int end, bool*& visited,int *arr, int index, int &c) {
	visited[start] = true;
	//cout << start << " ";
	arr[index] = start; 
	index = index + 1;
	if (start == end) {
		if (index < c){
			c = index;
		}
		//printArray(arr, index);
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			pathHelper(g, n->a, end, visited, arr, index, c);
		}
		n = n->next;
	}
	visited[start] = false;
}

int shortestPath(graph* g, int start, int end) {
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0; int c = INT_MAX;
	pathHelper(g, start, end, visited, arr, index, c);
	return c;

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

	//printGraph(g);
	//bfs(g, 0);
	//dfs(g, 0,8);
	cout<<"Shortest Path length is: "<< shortestPath(g,0,8)<<endl;
	
	return 0;
}
