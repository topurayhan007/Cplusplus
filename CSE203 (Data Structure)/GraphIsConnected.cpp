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
void dfs_arrayHelper(graph* g, int start,int end, bool*& visited, bool& found){
	if (start == end) {
		found = true;
	}
	visited[start] = true;
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			dfs_arrayHelper(g, n->a, end, visited, found);
		}
		n = n->next;
	}
}

bool isReachable(graph* g, int src, int dest) {
	bool found = false;
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	dfs_arrayHelper(g, src, dest, visited, found);
	return found;
}
bool isConnected(graph* g){
	bool connected = true;
	if ( g->numVertex == 0){
		connected = true;
	}
	for (int i = 0; i < g->numVertex; ++i){
		for (int j = 0; j < g->numVertex; ++j){
			if(isReachable(g, i, j) == false){
				connected = false;
				break;
			}
		}
	}
	return connected;
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
	//printGraph(g); cout<<endl;
	//dfs(g,0); cout<<endl;
	cout<<isConnected(g)<<endl;

	return 0;
}
