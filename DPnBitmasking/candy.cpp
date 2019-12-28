#include<bits/stdc++.h>
using namespace std;

long long solve(int** like, int n){

	long long *dp = new long long[(1<< n)]();
	dp[0] = 1;

	for(long long mask = 0; mask < (1 << n)-1; mask++){
		int k = 0;
		for(int j = 0; j < n; j++){
			if(mask & (1 << j)){
				k++;
			}
		}

		for(int j = 0; j < n; j++){
			if(like[k][j] && !(mask & (1 << (j)))){
				dp[mask | (1 << (j))] = dp[mask | (1 << (j))] + dp[mask];
			}
		}
	}

	long long ans = dp[(1 << n)-1];
	delete[] dp;
	return ans;
}

int main(){

	int n;
	cin >> n;
	int **like = new int*[n];
	for(int i = 0; i < n; i++){
		like[i] = new int[n];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> like[i][j];
		}
	}

	long long ways = solve(like, n);
	cout << ways << endl;

	for(int i = 0; i < n; i++){
		delete[] like[i];
	}
	delete[] like;
}