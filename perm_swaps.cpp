#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

void DFS(vector<int> *edges, int sv,unordered_set<int>* component, bool* visited){

	visited[sv] = true;
	component->insert(sv);

	for(int i = 0; i < edges[sv].size() ; i++){
		
		int next = edges[sv][i];
		if(visited[next]){
			continue;
		}
		DFS(edges, next,component, visited);
	}
}

unordered_set<unordered_set< int>*>* getComponents(vector<int>* edges, int n){

	bool *visited = new bool[n];

	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	unordered_set<unordered_set< int>*>* output = new unordered_set<unordered_set< int>*>();
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			unordered_set<int>* component = new unordered_set<int>();
			DFS(edges, i,component, visited);

			output->insert(component);
		}

	}
	delete[] visited;
	return output;

}

int main(){

	int T;
	cin >> T;
	while(T--){
		int v, e;
		cin >> v >> e;

		int* P = new int[v];
		int* Q = new int[v];

		for(int i = 0; i < v; i++){
			cin >> P[i];
		}

		for(int i = 0; i < v; i++){
			cin >> Q[i];
		}
		vector<int>* edges = new vector<int>[v];

		for(int i = 0; i < e; i++){
			int j , k;
			cin >> j >> k;

			edges[j-1].push_back(k-1);
			edges[k-1].push_back(j-1);
		}

		unordered_set< unordered_set< int>*>* components = getComponents(edges, v);
		unordered_set< unordered_set< int>*>::iterator it1 = components->begin();
		bool flag = true;

		while(it1 != components->end()){

			vector<int> p;
			vector<int> q;
			unordered_set<int>* component = *it1;
			unordered_set<int>::iterator it2 = component->begin();
			while(it2 != component->end()){
				p.push_back(P[*it2]);
				q.push_back(Q[*it2]);
				it2++;
			}
			
			sort(p.begin(),p.end());
			sort(q.begin(),q.end());

			for(int i = 0; i < p.size(); i++){
				if(p[i] != q[i]){
					flag = false;
				}
			}
			it1++;
			delete component;
		}
		if(flag){
			cout <<"YES" << endl;
		}
		else{
			cout <<"NO" << endl;
		}

		delete components;
		delete[] edges;
		delete[] P;
		delete[] Q;
	}
}