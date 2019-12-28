#include<bits/stdc++.h>
using namespace std;

void DFS(int **edges, int n, int sv, bool* visited){

	visited[sv] = true;

	for(int i = 0; i < n; i++){

		if(i == sv){
			continue;
		}

		if(edges[sv][i] == 1){

			if(visited[i]){
				continue;
			}
			DFS(edges, n, i,visited);
		}
	}
}

int main(){

	int n, e;
	cin >> n>> e;
	int **edges = new int*[n];
	for(int i = 0; i < n; i++){
		edges[i] = new int[n]();
	}

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	bool* visited = new bool[n];
	for(int i =0; i < n; i++){
		visited[i] = false;
	}


	DFS(edges,n,0,visited);

	bool flag = true;

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			flag = false;
			break;
		}
	}

	if(flag){
		cout <<"true" << endl;
	}
	else{
		cout <<"false" << endl;
	}
	
	for(int i = 0; i < n; i++){
		delete[] edges[i];
	}
	delete[] edges;
	delete[] visited;

}