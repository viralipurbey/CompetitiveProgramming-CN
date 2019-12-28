#include<bits/stdc++.h>
using namespace std;

int getMaxMoney(int money[], int n){

	int *dp = new int[n]();
	dp[0] = money[0];
	dp[1] = money[1];

	for(int i = 2; i < n; i++){
		int max = 0;
		for(int j = i-2; j >= 0; j--){
			if(max < dp[j]){
				max = dp[j];
			}
		}
		dp[i] = money[i] + max;
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(ans < dp[i]){
			ans = dp[i];
		}
	}
	delete[] dp;
	return ans;
}
int main(){

	int n;
	cin >> n;
	int money[n];
	for(int i = 0; i < n; i++){
		cin >> money[i];
	}

	int ans = getMaxMoney(money, n);
	cout << ans << endl;
}