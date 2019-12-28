#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int countBST(int n){

	int *dp = new int[n+1]();
	dp[0] = 1;
	dp[1] = 1;

	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp[i] = (dp[i] + (dp[j-1]*dp[i-j])%MOD)%MOD;
		}
	}

	int ans = dp[n];
	delete[] dp;
	return ans;
}

int main(){

	int n;
	cin >> n;

	int ans = countBST(n);
	cout << ans << endl;
}