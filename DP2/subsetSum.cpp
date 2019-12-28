#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int val[], int n, int s){

	bool **dp = new bool*[n+1];

	for(int i = 0; i <= n; i++){
		dp[i] = new bool[s+1];
	}

	for(int j = 1; j <= s; j++){
		dp[0][j] = false;
	}

	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= s; j++){

			dp[i][j] = dp[i-1][j];
			if(j >= val[i-1]){
				dp[i][j] = dp[i][j] || dp[i-1][j- val[i-1]];
			}
		}
	}

	bool ans = dp[n][s];
	for(int i = 0; i <= n; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

bool subsetSum2(int val[], int n, int s){

	bool **dp = new bool*[2];
	for(int i =0; i <= 1; i++){
		dp[i] = new bool[s+1];
	}

	for(int j = 1; j <= s; j++){
		dp[0][j] = false;
	}

	for(int i = 0; i <= 1; i++){
		dp[i][0] = true;
	}

	int flag = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= s; j++){

			dp[flag][j] = dp[flag ^ 1][j];
			if(j >= val[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag ^ 1][j- val[i-1]];
			}
		}
		flag = flag ^ 1;
	}

	bool ans = dp[flag ^ 1][s];
	for(int i = 0; i <= 1; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;

}

int main(){

	int n, s;
	cin >> n >> s;

	int val[n];
	for(int i = 0; i < n; i++){
		cin >> val[i];
	}

	bool ans = subsetSum(val, n, s);
	cout << ans << endl;

	cout << subsetSum2(val, n, s) << endl;
}