#include<bits/stdc++.h>
using namespace std;

int lis_i(int arr[], int n){
	int *dp = new int[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		int max = 1;
		for(int j = i-1; j >= 0; j--){
			if(arr[j] <arr[i]){
				int curr = dp[j] + 1;
				if(curr > max){
					max = curr;
				}
			}
		}
		dp[i] = max;
	}
	int output = 0;
	for(int i = 0; i < n; i++){
		if(output < dp[i]){
			output = dp[i];
		}
	}
	delete[] dp;
	return output;
}
int main(){
	int n;
	cin >> n; 
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	cout << lis_i(arr,n) << endl;
	return 0;
}