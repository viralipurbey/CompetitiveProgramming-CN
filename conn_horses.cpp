#include<bits/stdc++.h>
#include<unordered_set>
#define MOD 1000000007
using namespace std;

int fact(int n){

	int *arr = new int[n+1];
	arr[0] = 1;
	arr[1] = 1;
	for(int i = 2; i <= n; i++){
		arr[i] = (i*arr[i-1])%MOD;
	}
	int ans = arr[n];
	delete[] arr;
	return ans;
}

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

	int n, m;
	cin >> n>> m;
	int q;
	cin >> q;
	int **chess = new int*[n+1];
	for(int i = 0; i <= n; i++){
		chess[i] = new int[m+1];
	}

	vector<int>* edges = new vector<int>[q];
	int count = 1;

	while(count <= q){
		int i, j;
		cin >> i >> j;
		chess[i][j] = count;

		if(i > 2 && j > 1){
			if(chess[i-2][j-1]){
				edges[chess[i][j]-1].push_back(chess[i-2][j-1]-1);
				edges[chess[i-2][j-1]-1].push_back(chess[i][j]-1);
			}
		}
		else if(i > 2 && j < m){
			if(chess[i-2][j+1]){
				edges[chess[i][j]-1].push_back(chess[i-2][j+1]-1);
				edges[chess[i-2][j+1]-1].push_back(chess[i][j]-1);
			}
		}
		count++;
	}


	for(int i = 0; i <= q; i++){
		for(int j = 0; j < edges[i].size(); j++){
			cout << edges[i][j] <<" ";
		}
		cout <<endl;
	}
	// unordered_set< unordered_set< int>*>* components = getComponents(edges, q);
	// unordered_set< unordered_set< int>*>::iterator it1 = components->begin();
	// int ans = 1;

	// while(it1 != components->end()){

	// 	unordered_set<int>* component = *it1;
		
	// 	int curr_size = component->size();
	// 	int ans = (ans *fact(curr_size))%MOD;
	// 	it1++;
	// 	delete component;
	// }
	// cout << ans << endl;

	for(int i = 0; i <= n; i++){
		delete[] chess[i];
	}

	delete[] chess;
	//delete components;
	delete[] edges;
}