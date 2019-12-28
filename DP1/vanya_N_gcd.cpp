#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int solve(int arr[], int n){

	int **dp = new int*[n];

	for(int i = 0; i < n;i++){
		dp[i] = new int[101]();
	}

	dp[0][arr[0]] = 1;

	for(int i = 1; i < n; i++){
		dp[i][arr[i]] = 1;

		for(int k = 0; k < i; k++){

			if(arr[k] < arr[i]){

				for(int g = 1; g <= 100; g++){
					int ng = __gcd(arr[i], g);
					dp[i][ng] = (dp[i][ng] + dp[k][g])%MOD;
				}
			}
		}
	}

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum = (sum + dp[i][1])%MOD;
	}
	for(int i = 0; i < n; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return sum;
}

int main(){

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int ans = solve(arr, n);
	cout << ans << endl;
}