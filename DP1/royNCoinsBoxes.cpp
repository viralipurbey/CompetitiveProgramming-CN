#include<bits/stdc++.h>
using namespace std;

int main(){

	 int n,m;
	 cin >> n >> m;
	 int v = m;
	 int *start = new int[n+1]();
	 int *end = new int[n+1]();

	 while(m--){
	 	int s , e;
	 	cin >> s >> e;
	 	start[s]++;
	 	end[e]++;
	 }

	 int *coins = new int[n+1]();
	 coins[1] = start[1];

	 for(int i = 2; i <= n; i++){
	 	coins[i] = start[i] - end[i-1] + coins[i-1];
	 }

	 int *boxes = new int[v+1]();
	 for(int i = 1; i <= n; i++){
	 	boxes[coins[i]]++;
	 }

	 for(int i = v-1; i >= 0; i--){
	 	boxes[i] = boxes[i] + boxes[i+1];
	 }

	 int q;
	 cin >> q;
	 while(q--){
	 	int c;
	 	cin >> c;
	 	cout << boxes[c] << endl;
	 }

	 delete[] start;
	 delete[] end;
	 delete[] coins;
	 delete[] boxes;
}