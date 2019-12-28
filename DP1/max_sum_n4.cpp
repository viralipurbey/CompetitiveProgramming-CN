#include<bits/stdc++.h>
using namespace std;

int max_sum(int **arr, int row, int col){

	int **dp = new int*[row + 1];
	for(int i = 0; i <=row; i++){
		dp[i] = new int[col + 1]();
	}

	dp[row-1][col-1] = arr[row-1][col-1];

	for(int i = row -2; i >= 0; i--){
		dp[i][col-1] = dp[i+1][col-1] + arr[i][col-1]; 
	}

	for(int j = col -2 ; j>= 0; j--){
		dp[row-1][j] = dp[row-1][j+1] + arr[row-1][j];
	}

	for(int i = row -2; i >= 0; i--){
		for(int j = col-2; j >= 0; j--){
			dp[i][j] =  arr[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
		}
	}



	int max = INT_MIN;
	for(int i1 = 0; i1 < row; i1++){
		for(int j1 = 0; j1 < col; j1++){

			for(int i2 = i1+1; i2 <= row; i2++){
				for(int j2 = j1 + 1; j2 <= col; j2++){
					int curr = dp[i1][j1] - dp[i1][j2] - dp[i2][j1] + dp[i2][j2];
					if(curr > max){
						max = curr;
					}
				}
			}
		}
	}

	cout << max << endl;
	for(int i = 0; i <= row; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}

int main(){
	int n,m;
	cin >> n >> m;
	int **arr = new int*[n];
	for(int i = 0; i < n; i++){
		arr[i] = new int[m];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}

	int sum = max_sum(arr, n, m);
}
