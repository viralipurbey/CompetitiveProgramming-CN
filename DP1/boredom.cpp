#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> A){

	int *freq = new int[1001]();

	for(int i = 0; i < n; i++){
		freq[A[i]]++;
	}

	int *dp = new int[1001]();
	dp[0] = 0;
	dp[1] = 1 * freq[1];

	for(int i = 2; i <= 1000; i++){

		int one = dp[i-2] + i * freq[i];
		int second = dp[i-1];
		dp[i] = max(one, second);
	} 

	int ans = dp[1000];
	delete[] dp;
	delete[] freq;
	return ans;
} 

int main(){

	int n;
	cin >> n;

	vector<int> A;

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		A.push_back(a);
	}

	int ans = solve(n, A);
	cout << ans << endl;
}