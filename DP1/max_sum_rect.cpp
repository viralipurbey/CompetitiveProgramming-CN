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

int max_sum_n3(int **arr, int row, int col){

	int max = INT_MIN;
	for(int l = 0; l < col; l++){
		int array[row];
		for(int r = l+1 ; r <= col; r++){
			if(l + 1 == r){
				for(int i = 0; i < row; i++){
					array[i] = arr[i][r-1];
				}
			}
			else{
				for(int i = 0; i < row; i++){
					array[i] = array[i] + arr[i][r-1];				}
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

	int sum = max_sum_n3(arr,n, m);
	cout << sum << endl;

	return 0;
}
