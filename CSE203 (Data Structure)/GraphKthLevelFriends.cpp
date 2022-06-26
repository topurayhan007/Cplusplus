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
	if(s=="A"){src = 0;}
	if(s=="B"){src = 1;}
	if(s=="C"){src = 2;}
	if(s=="D"){src = 3;}
	if(s=="E"){src = 4;}
	if(s=="F"){src = 5;}
	if(s=="G"){src = 6;}
	if(s=="H"){src = 7;}
	if(s=="I"){src = 8;}

	if(d=="A"){dest = 0;}
	if(d=="B"){dest = 1;}
	if(d=="C"){dest = 2;}
	if(d=="D"){dest = 3;}
	if(d=="E"){dest = 4;}
	if(d=="F"){dest = 5;}
	if(d=="G"){dest = 6;}
	if(d=="H"){dest = 7;}
	if(d=="I"){dest = 8;}
	node* n = new node;
	n->a = dest;
	n->next = g->adj[src];
	g->adj[src] = n;
}
void printGraph(graph* g) {
	for (int i = 0; i < g->numVertex; ++i) {
		node* n = g->adj[i];
		if(i==0){cout<<"A"<<" ";}
		if(i==1){cout<<"B"<<" ";}
		if(i==2){cout<<"C"<<" ";}
		if(i==3){cout<<"D"<<" ";}
		if(i==4){cout<<"E"<<" ";}
		if(i==5){cout<<"F"<<" ";}
		if(i==6){cout<<"G"<<" ";}
		if(i==7){cout<<"H"<<" ";}
		if(i==8){cout<<"I"<<" ";}

		while (n != nullptr) {
			if(n->a==0){cout<<"A"<<" ";}
			if(n->a==1){cout<<"B"<<" ";}
			if(n->a==2){cout<<"C"<<" ";}
			if(n->a==3){cout<<"D"<<" ";}
			if(n->a==4){cout<<"E"<<" ";}
			if(n->a==5){cout<<"F"<<" ";}
			if(n->a==6){cout<<"G"<<" ";}
			if(n->a==7){cout<<"H"<<" ";}
			if(n->a==8){cout<<"I"<<" ";}

			n = n->next;
		}
		cout << endl;
	}
}

void kthLevelFriendsHelper(graph* g, int start, int k, int level, queue<int>& l){
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
		l.push(p);

		node* n = g->adj[p];
		while (n != nullptr) {
			if (visited[n->a] == false) {
				visited[n->a] = true;
				q.push(n->a);
			}
			n = n->next;
		}
		if (numNodesEachLevel == 0) {
			if(level != k){
				while(!l.empty()){
					l.pop();
				}
			}
			else{
				return;
			}
			level++;
			numNodesEachLevel = q.size();
		}
	}
}

void kthLevelFriends(graph* g, string s, int k) {
	int src=0;
	if(s=="A"){src = 0;}
	if(s=="B"){src = 1;}
	if(s=="C"){src = 2;}
	if(s=="D"){src = 3;}
	if(s=="E"){src = 4;}
	if(s=="F"){src = 5;}
	if(s=="G"){src = 6;}
	if(s=="H"){src = 7;}
	if(s=="I"){src = 8;}

	int level = 0;
	queue<int> l;
	kthLevelFriendsHelper(g, src, k, level, l);
	if(k == 0){
		cout<<s<<" has no friend 'ekla pothik' ";
	}
	else if (k == 1){
		cout<<s<<"'s "<<k<<"st level friends are: ";
		
	}
	else if (k == 2){
		cout<<s<<"'s "<<k<<"nd level friends are: ";
		
	}
	else if (k == 3){
		cout<<s<<"'s "<<k<<"rd level friends are: ";
		
	}
	else{
		cout<<s<<"'s "<<k<<"th level friends are: ";
	}
	cout<<"{ ";
	while(!l.empty()){
		if(l.front()==0){cout<<"A"<<" ";}
		if(l.front()==1){cout<<"B"<<" ";}
		if(l.front()==2){cout<<"C"<<" ";}
		if(l.front()==3){cout<<"D"<<" ";}
		if(l.front()==4){cout<<"E"<<" ";}
		if(l.front()==5){cout<<"F"<<" ";}
		if(l.front()==6){cout<<"G"<<" ";}
		if(l.front()==7){cout<<"H"<<" ";}
		if(l.front()==8){cout<<"I"<<" ";}

		l.pop();
	}
	cout<<"}"<<endl;
}


int main() {
	graph* g = new graph(9);
	
	addEdge(g, "A", "B");
	addEdge(g, "A", "D");
	addEdge(g, "B", "E");
	addEdge(g, "C", "B");
	addEdge(g, "D", "G");
	addEdge(g, "E", "D");
	addEdge(g, "E", "F");
	addEdge(g, "F", "C");
	addEdge(g, "H", "E");
	addEdge(g, "H", "G");
	addEdge(g, "I", "H");
	addEdge(g, "I", "F");

	//printGraph(g);

	kthLevelFriends(g,"B", 2);
	
	return 0;
}
