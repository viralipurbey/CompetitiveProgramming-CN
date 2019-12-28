#include<bits/stdc++.h>
using namespace std;

int coinchange(int arr[], int len, int n){
	if(n== 0){
		return 1;
	}

	if(n < 0){
		return 0;
	}

	if(len == 0){
		return 0;
	}

	int first = coinchange(arr,len,n-arr[0]);
	int second = coinchange(arr + 1, len -1, n);
	int ans = first + second;
	return ans;
}

int countWaysToMakeChange(int arr[], int len, int n){

	int **dp = new int*[n+1];
	for(int i =0; i <= n; i++){
		dp[i] = new int[len+1];
	}

	for(int j = 0; j <= len; j++){
		dp[0][j] = 1;
	}

	for(int i = 1; i <= n; i++){
		dp[i][0] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= len; j++){
			if((i-arr[j-1]) >= 0)
				dp[i][j] = dp[i-arr[j-1]][j] + dp[i][j-1];
			else
				dp[i][j] = dp[i][j-1];
		}
	}
	int ans = dp[n][len];
	delete[] dp;
	return ans;

}

// int countWaysToMakeChange(int arr[], int len, int n){

// 	int **dp = new int*[n+1];
// 	for(int i =0; i <= n; i++){
// 		dp[i] = new int[len+1];
// 	}

// 	for(int j = 0; j <= len; j++){
// 		dp[0][j] = 1;
// 	}

// 	for(int i = 1; i <= n; i++){
// 		dp[i][0] = 0;
// 	}

// 	for(int i = 1; i <= n; i++){
// 		for(int j = 1; j <= len; j++){
// 			if((i-arr[j-1]) >= 0)
// 				dp[i][j] = dp[i-arr[j-1]][j] + dp[i][j-1];
// 			else
// 				dp[i][j] = dp[i][j-1];
// 		}
// 	}
// 	int ans = dp[n][len];
// 	delete[] dp;
// 	return ans;

// }
int main(){
	int len;
	cin >> len;
	int arr[len];
	for(int i = 0; i < len; i++){
		cin >> arr[i];
	}
	int n;
	cin >> n;
	int ans = coinchange(arr, len,n);
	cout << ans << endl;
	ans = countWaysToMakeChange(arr,len,n);
	cout << ans << endl;
	return 0;
}