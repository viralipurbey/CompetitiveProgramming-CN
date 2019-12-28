#include<bits/stdc++.h>
using namespace std;

int minCostforJobs(int** arr, int n,int p, int mask, int *dp){
	if(p >= n){
		return 0;
	}

	if(dp[mask] != INT_MAX){
		return dp[mask];
	}

	int minCost= INT_MAX;
	for(int i = 0; i < n; i++){
		if(mask & (1 << (n-i-1))){
			continue;
		}
		int m = mask | (1 << (n-i-1));
		int cost = arr[p][i] + minCostforJobs(arr,n,p+1,m, dp);
		if(cost < minCost){
			minCost = cost;
		}
	}
	dp[mask] = minCost;
	return minCost;

}

int minCostforJobs_i(int** arr, int n){
	int* dp = new int[(1 << n)];
	for(int i = 0; i < (1 << n); i++){
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	
	for(int mask = 0; mask < ((1 << n)-1); mask++){

		int no_of_set_bits = 0;
		for(int j = 0; j < n; j++){
			if(mask & (1 << j)){
				no_of_set_bits++;
			}
		}

		int p = no_of_set_bits;

		for(int j = 0; j < n; j++){
			if(!(mask & (1 << (n-j-1)))){
				dp[mask | (1 << (n-j-1))] = min(dp[mask | (1 << (n-j-1))], dp[mask] + arr[p][j]);
			}
		}
	}

	int ans = dp[(1 << n) - 1];
	delete[] dp;
	return ans;
}
int main(){

	int n;
	cin >> n;

	int** jobs = new int*[n];
	for(int i = 0; i < n; i++){
		jobs[i] = new int[n];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> jobs[i][j];
		}
	}

	int *dp = new int[(1 << n)];

	for(int i = 0; i < (1 << n); i++){
		dp[i] = INT_MAX;
	}

	int ans = minCostforJobs(jobs, n,0, 0,dp);

	cout << ans << endl;

	cout << minCostforJobs_i(jobs, n);
	for(int i = 0; i < n; i++){
		delete[] jobs[i];
	}
	delete[] jobs;
	delete[] dp;
}