#include<bits/stdc++.h>
using namespace std;

bool printBFS(int** edges, int n , int s,int e, bool* visited){

	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()){

		int curr = q.front();
		q.pop();

		for(int i = 0; i < n; i++){
			if(i == curr){
				continue;
			}

			if(edges[curr][i] == 1){
				if(visited[i]){
					continue;
				}

				if(i == e){
					return true;
				}
				q.push(i);
				visited[i] = true;
			}
		}
	}

	return false;
}

int main(){

	int n , e;
	cin >> n >> e;

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

	int s , f;
	cin >> s >> f;

	bool* visited = new bool[n];

	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

	if(printBFS(edges,n,s,f,visited)){
		cout <<"true" << endl;
	}
	else{
		cout << "false" << endl;
	}

	for(int i = 0; i < n; i++){
		delete[] edges[i];
	}
	delete[] edges;	
	delete[] visited;
}
