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

			dp[i][j] = dp[i-1][j];

			if(wt[i-1] <= j){
				dp[i][j] = max(dp[i][j], val[i-1] + dp[i-1][j - wt[i-1]]);
			}
		}
	}

	int ans = dp[n][W];

	for(int i = 0; i <= n; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

int knapsnack_i2(int wt[], int val[], int n, int W){

	int *dp1 = new int[W+1]();
	int *dp2 = new int[W+1]();

	int count = 1;

	while(count <= n){
		for(int j = 1; j <= W; j++){
			dp2[j] = dp1[j];
			if(j >= wt[count-1]){
				dp2[j] = max(dp2[j] , val[count-1] + dp1[j-wt[count-1]]);
			}
		}

		for(int j = 0; j <= W; j++){
			dp1[j] = dp2[j];
		}
		count++;
	}

	return dp2[W];

	delete[] dp1;
	delete[] dp2;
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
	ans = knapsnack_i2(wt, val, n, W);
	cout << ans << endl;
	for(int i = 0; i <= n; i++){
		delete[] dp[i];
	}

	delete[] dp;
}