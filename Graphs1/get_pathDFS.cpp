#include<bits/stdc++.h>
using namespace std;

vector<int> DFS(int** edges, int n, int s,int f, bool* visited){
	
	vector<int> v;
	visited[s] = true;
	if(s == f){
		vector<int> ans;
		ans.push_back(s);
		visited[s] = true;
		return ans;
	}

	for(int i = 0; i < n; i++){
		if(s == i){
			continue;
		}

		if(edges[s][i] == 1){
			if(visited[i]){
				continue;
			}

			vector<int> ans = DFS(edges,n,i,f,visited);
			if(ans.size() != 0){
				ans.push_back(s);
				return ans;
			}
		}
	}

	return v;
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

	vector<int> ans = DFS(edges, n, s, f,visited);

	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;

	for(int i = 0; i < n; i++){
		delete[] edges[i];
	}
	delete[] edges;
	delete[] visited;

}