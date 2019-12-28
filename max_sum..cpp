#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr, int n){
	int curr_sum = 0;
	int best_sum = 0;
	for(int i = 0; i < n; i++){
		curr_sum += arr[i];
		if(best_sum < curr_sum)
			best_sum = curr_sum;
		if(curr_sum < 0){
			curr_sum = 0;
		}
	}
	return best_sum;
}

// int max_sum_n4(int **arr, int row, int col){

// 	int **dp = new int*[row + 1];
// 	for(int i = 0; i <=row; i++){
// 		dp[i] = new int[col + 1]();
// 	}

// 	dp[row-1][col-1] = arr[row-1][col-1];

// 	for(int i = row -2; i >= 0; i--){
// 		dp[i][col-1] = dp[i+1][col-1] + arr[i][col-1]; 
// 	}

// 	for(int j = col -2 ; j>= 0; j--){
// 		dp[row-1][j] = dp[row-1][j+1] + arr[row-1][j];
// 	}

// 	for(int i = row -2; i >= 0; i--){
// 		for(int j = col-2; j >= 0; j--){
// 			dp[i][j] =  arr[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i+1][j+1];
// 		}
// 	}



// 	int max = INT_MIN;
// 	for(int i1 = 0; i1 < row; i1++){
// 		for(int j1 = 0; j1 < col; j1++){

// 			for(int i2 = i1+1; i2 <= row; i2++){
// 				for(int j2 = j1 + 1; j2 <= col; j2++){
// 					int curr = dp[i1][j1] - dp[i1][j2] - dp[i2][j1] + dp[i2][j2];
// 					if(curr > max){
// 						max = curr;
// 					}
// 				}
// 			}
// 		}
// 	}

// 	for(int i = 0; i <= row; i++){
// 		delete[] dp[i];
// 	}
// 	delete[] dp;
// 	return max;
// }

int max_sum_n3(int **arr, int row, int col){

	int **dp = new int*[row + 1];
	for(int i = 0; i <=row; i++){
		dp[i] = new int[col + 1]();
	}
	int array[row];
	int max = INT_MIN;
	for(int i = 0; i < row; i++){
		for(int j = i+1 ; j <= row; j++){
			if(i + 1 == j){
				dp[i][j] = arr[i][j];
				array[i] = dp[i][j];
			}
			else{
				dp[i][j] = dp[i-1][j-1] + arr[i][j];
				array[i] = dp[i][j];
			}
			int curr_max = kadane(array, row);
			if(curr_max > max){
				max = curr_max;
			}
		}
	}
	return max;
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

	// int sum = max_sum_n4(arr, n, m);
	// cout << sum << endl;
	int sum = max_sum_n3(arr,n, m);
	cout << sum << endl;

	return 0;
}