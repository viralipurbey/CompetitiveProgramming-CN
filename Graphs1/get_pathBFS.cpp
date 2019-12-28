#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<int> printBFS(int** edges, int n , int s,int e, bool* visited){

	vector<int> ans;
	unordered_map<int,int> m;
	queue<int> q;
	q.push(s);
	visited[s] = true;
	int curr = -1;
	while(!q.empty()){

		curr = q.front();
		q.pop();

		for(int i = 0; i < n; i++){
			if(i == curr){
				continue;
			}

			if(edges[curr][i] == 1 && visited[i]!= 0 ){
				//if(visited[i]){
				//	continue;
				//}

				m[i] = curr;
				q.push(i);

				if(i == e ){
					curr = e;
					ans.push_back(e);
					break;
				}
				
			}
		}
	}

	while(curr != s || curr != -1){
		curr = m[curr];
		ans.push_back(curr);
	}
	return ans;
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

	vector<int> ans = printBFS(edges,n,s,f,visited);
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] <<" ";
	}
	cout << endl;

	for(int i = 0; i < n; i++){
		delete[] edges[i];
	}
	delete[] edges;	
	delete[] visited;
}
