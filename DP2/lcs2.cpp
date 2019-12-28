#include<bits/stdc++.h>
using namespace std;

int knapsnack(int n, int W, int wt[], int val[], int **dp){

	if(W == 0){
		return 0;
	}

	if(n == 0){
		return 0;
	}

	if(dp[n][W] >= 0){
		return dp[n][W];
	}

	int ans;

	if(wt[n-1] <= W){
		ans = max(val[n-1] + knapsnack(n-1, W- wt[n-1],wt, val, dp), knapsnack(n-1, W, wt, val, dp));
	}
	else{
		ans = knapsnack(n-1, W, wt, val, dp);
	}

	dp[n][W] = ans;
	return ans;
}

int knapsnack_i(int wt[], int val[], int n, int W){

	int **dp = new int*[n+1];
	for(int i = 0; i <= n; i++){
		dp[i] = new int[W+1]();
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			if(j - wt[i-1] >= 0){
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
			}
			dp[i][j] = dp[i-1][j];
			
		}
	}

	int ans = dp[n][W];

	for(int i = 0; i <= n; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}
int main(){

	int n, W;
	cin >> n >> W;
	int wt[n], val[n];
	for(int i = 0; i < n; i++){
		cin >> wt[i];
	}

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}

	int **dp = new int*[n+1];
	for(int i = 0; i <= n; i++){
		dp[i] = new int[W+1];
		for(int j = 0; j <= W; j++){
			dp[i][j] = -1;
		}
	}

	int ans = knapsnack(n, W, wt, val, dp);

	cout << ans << endl;
	ans = knapsnack_i(wt, val, n, W);
	cout << ans << endl;
	for(int i = 0; i <= n; i++){
		delete[] dp[i];
	}

	delete[] dp;
}