#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int row, int col){

	int **dp = new int*[row];
	for(int i = 0; i < row; i++){
		dp[i] = new int[col]();
	}

	if(arr[0][0] == 0){
		dp[0][0] = 1;
	}

	for(int i = 1; i < row; i++){
		if(arr[i][0] == 0){
			dp[i][0] = 1;
		}
	}

	for(int j = 1; j < col; j++){
		if(arr[0][j] == 0){
			dp[0][j] = 1;
		}
	}

	for(int i = 2; i < row; i++){
		for(int j = 2; j < col; j++){
			if(arr[i][j] == 0){
				dp[i][j] = min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1])) + 1;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(ans < dp[i][j]){
				ans = dp[i][j];
			}
		}
	}

	for(int i = 0; i < row; i++){
		delete[] dp[i];
	}
	delete[] dp;

	return ans;
}

int main(){

	int row, col;
	cin >> row >> col;

	int **arr = new int*[row];
	for(int i = 0; i < row; i++){
		arr[i] = new int[col];
		for(int j = 0; j < col; j++){
			cin >> arr[i][j];
		}
	}

	int ans = findMaxSquareWithAllZeros(arr, row, col);

	for(int i = 0; i < row; i++){
		delete[] arr[i];
	}
	delete[] arr;
	cout << ans << endl;
}