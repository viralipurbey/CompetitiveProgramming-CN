#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int n, int sv, bool* visited){

	visited[sv] = true;

	for(int i = 1; i <= n; i++){

		if(i == sv){
			continue;
		}

		if(edges[sv][i] == 1){

			if(visited[i]){
				continue;
			}
			printDFS(edges, n, i,visited);
		}
	}
}

int DFS(int**edges, int n){

    bool* visited = new bool[n];
	for(int i =0; i <= n; i++){
		visited[i] = false;
	}

    int count = 0;
    for(int i = 1; i <= n; i++){
		if(!visited[i]){
            count++;
			printDFS(edges,n,i,visited);
		}
	}
    delete[] visited;

    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **edges = new int*[n+1];
	for(int i = 0; i <= n; i++){
		edges[i] = new int[n+1]();
	}

    for(int i = 0; i < m; i++){
		edges[u[i]][v[i]] = 1;
		edges[v[i]][u[i]] = 1;
	}

    int ans = DFS(edges, n);

    for(int i = 0; i <= n; i++){
		delete[] edges[i];
	}
	delete[] edges;
    return ans;

}

int main(){

	int n, m;
	cin >> n>> m;
	
    vector<int> u;
    vector<int> v;

	for(int i = 0; i < m; i++){
		int f;
		cin >> f;
		u.push_back(f);
	}

    for(int i = 0; i < m; i++){
		int f;
		cin >> f;
		v.push_back(f);
	}
    cout << solve(n, m, u, v) << endl;

}