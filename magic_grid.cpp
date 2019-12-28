#include<bits/stdc++.h>
using namespace std;

int health(int **arr, int r, int c){
	int dp[r][c];

	dp[r-1][c-1] = 1;
	dp[r-2][c-1] = 1;
	dp[r-1][c-2] = 1;

	for(int i = r-3; i >= 0; i--){
		dp[i][c-1] = dp[i+1][c-1] - arr[i+1][c-1];
		if(dp[i][c-1] <= 0){
			dp[i][c-1] = 1;
		}
	}

	for(int j = c-3; j >= 0; j--){
		dp[r-1][j] = dp[r-1][j+1] - arr[r-1][j+1];
		if(dp[r-1][j] <= 0){
			dp[r-1][j] = 1;
		}
	}

	for(int i = r-2; i >= 0; i--){
		for(int j = c-2; j >= 0; j--){
			int first = dp[i+1][j] - arr[i+1][j];
			int second = dp[i][j+1] - arr[i][j+1];
			dp[i][j] = min(first,second);
			if(dp[i][j] <= 0){
				dp[i][j] = 1;
			}
		}
	}

	int ans = dp[0][0];
	return ans;
}

int main(){

	int T;
	cin >> T;
	while(T--){
		int r,c;
		cin >> r >> c;
		int **arr = new int*[r];
		for(int i = 0; i < r; i++){
			arr[i] = new int[c];
		}
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin >> arr[i][j];
			}
		}

		int min_H = health(arr, r,c);
		cout << min_H << endl;
		for(int i = 0; i < r; i++){
			delete[] arr[i];
		}

		delete[] arr;
	}
}