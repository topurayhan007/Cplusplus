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

void addEdge(graph* g, string s, string d) {
	int src=0; int dest=0;
	if(s=="Gulshan"){src = 0;}
	if(s=="Lalbagh"){src = 1;}
	if(s=="Motijheel"){src = 2;}
	if(s=="Mirpur"){src = 3;}
	if(s=="DOHS"){src = 4;}
	if(s=="Jatrabari"){src = 5;}
	if(s=="Azimpur"){src = 6;}
	if(s=="Gabtoli"){src = 7;}
	if(s=="Nilkhet"){src = 8;}

	if(d=="Gulshan"){dest = 0;}
	if(d=="Lalbagh"){dest = 1;}
	if(d=="Motijheel"){dest = 2;}
	if(d=="Mirpur"){dest = 3;}
	if(d=="DOHS"){dest = 4;}
	if(d=="Jatrabari"){dest = 5;}
	if(d=="Azimpur"){dest = 6;}
	if(d=="Gabtoli"){dest = 7;}
	if(d=="Nilkhet"){dest = 8;}
	node* n = new node;
	n->a = dest;
	n->next = g->adj[src];//src is anything between 0-5
	g->adj[src] = n;
}
void printGraph(graph* g) {
	for (int i = 0; i < g->numVertex; ++i) {
		node* n = g->adj[i];
		if(i==0){cout<<"Gulshan";}
		if(i==1){cout<<"Lalbagh";}
		if(i==2){cout<<"Motijheel";}
		if(i==3){cout<<"Mirpur";}
		if(i==4){cout<<"DOHS";}
		if(i==5){cout<<"Jatrabari";}
		if(i==6){cout<<"Azimpur";}
		if(i==7){cout<<"Gabtoli";}
		if(i==8){cout<<"Nilkhet";}
		cout <<" ";
		while (n != nullptr) {
			if(n->a==0){cout<<"Gulshan";}
			if(n->a==1){cout<<"Lalbagh";}
			if(n->a==2){cout<<"Motijheel";}
			if(n->a==3){cout<<"Mirpur";}
			if(n->a==4){cout<<"DOHS";}
			if(n->a==5){cout<<"Jatrabari";}
			if(n->a==6){cout<<"Azimpur";}
			if(n->a==7){cout<<"Gabtoli";}
			if(n->a==8){cout<<"Nilkhet";}
			cout <<" ";

			n = n->next;
		}
		cout << endl;
	}
}


void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		if(arr[i]==0){cout<<"Gulshan";}
		if(arr[i]==1){cout<<"Lalbagh";}
		if(arr[i]==2){cout<<"Motijheel";}
		if(arr[i]==3){cout<<"Mirpur";}
		if(arr[i]==4){cout<<"DOHS";}
		if(arr[i]==5){cout<<"Jatrabari";}
		if(arr[i]==6){cout<<"Azimpur";}
		if(arr[i]==7){cout<<"Gabtoli";}
		if(arr[i]==8){cout<<"Nilkhet";}

		if(i != n-1){
			cout<<" -> ";
		}

	}
	cout << endl;
}
void newArray(int* arr, int *parr, int n) {
	for (int i = 0; i < n; ++i) {
		parr[i]=arr[i];
	}
}
void pathHelper(graph* g, int start,int end, bool*& visited,int *arr, int index, int &c, int *parr) {
	visited[start] = true;
	arr[index] = start; 
	index = index + 1;
	if (start == end) {
		if (index < c){
			c = index;
			newArray(arr, parr, c);
		}		
	}
	node* n = g->adj[start];
	while (n != nullptr) {
		if (!visited[n->a]) {
			pathHelper(g, n->a, end, visited, arr, index, c, parr);
		}
		n = n->next;
	}
	visited[start] = false;
}

void printShortestPath(graph* g, string s, string d) {
	int src=0; int dest=0;
	if(s=="Gulshan"){src = 0;}
	if(s=="Lalbagh"){src = 1;}
	if(s=="Motijheel"){src = 2;}
	if(s=="Mirpur"){src = 3;}
	if(s=="DOHS"){src = 4;}
	if(s=="Jatrabari"){src = 5;}
	if(s=="Azimpur"){src = 6;}
	if(s=="Gabtoli"){src = 7;}
	if(s=="Nilkhet"){src = 8;}

	if(d=="Gulshan"){dest = 0;}
	if(d=="Lalbagh"){dest = 1;}
	if(d=="Motijheel"){dest = 2;}
	if(d=="Mirpur"){dest = 3;}
	if(d=="DOHS"){dest = 4;}
	if(d=="Jatrabari"){dest = 5;}
	if(d=="Azimpur"){dest = 6;}
	if(d=="Gabtoli"){dest = 7;}
	if(d=="Nilkhet"){dest = 8;}
	bool* visited = new bool[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int* arr = new int[g->numVertex];
	int* parr = new int[g->numVertex];
	for (int i = 0; i < g->numVertex; ++i) {
		visited[i] = false;
	}
	int index = 0; int c = INT32_MAX; 
	pathHelper(g, src, dest, visited, arr, index, c, parr);
	printArray(parr, c);

}

int main() {
	graph* g = new graph(9);
	
	addEdge(g, "Gulshan", "Lalbagh");
	addEdge(g, "Lalbagh", "Motijheel");
	addEdge(g, "Lalbagh", "Gabtoli");
	addEdge(g, "Motijheel", "Gabtoli");
	addEdge(g, "Mirpur", "Gulshan");
	addEdge(g, "Mirpur", "Lalbagh");
	addEdge(g, "Mirpur", "Azimpur");
	addEdge(g, "Mirpur", "DOHS");
	addEdge(g, "Jatrabari", "DOHS");
	addEdge(g, "Jatrabari", "Mirpur");
	addEdge(g, "Azimpur", "Jatrabari");
	addEdge(g, "Gabtoli", "Azimpur");
	addEdge(g, "Gabtoli", "Jatrabari");
	addEdge(g, "Gabtoli", "Nilkhet");
	addEdge(g, "Nilkhet", "Motijheel");

	//"Gulshan"
	//"Lalbagh"
	//"Motijheel"
	//"Mirpur"
	//"DOHS"
	//"Jatrabari"
	//"Azimpur"
	//"Gabtoli"
	//"Nilkhet"
	printShortestPath(g,"Motijheel","DOHS");
	
	return 0;
}
