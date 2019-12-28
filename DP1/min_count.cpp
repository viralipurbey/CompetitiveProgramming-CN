#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int minCount(int n){

	int *dp = new int[n+1];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for(int i = 4; i <= n; i++){
		dp[i] = INT_MAX;
	}

	for(int i = 4; i <= n; i++){
		for(int j = 1; j <= ceil(sqrt(i)); j++){

			int temp = j * j;

			if(temp > i){
				break;
			}
			else{
				dp[i] = min(dp[i] , dp[i-temp] + 1);
			}
		}
	}

	int ans = dp[n];
	delete[] dp;
	return ans;
}

int main(){

	int n;
	cin >> n;

	int ans = minCount(n);
	cout << ans << endl;
}