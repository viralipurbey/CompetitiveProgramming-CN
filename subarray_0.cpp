#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    int **dp = new int*[row];
    for(int i = 0; i < row; i++){
        dp[i] = new int[col]();
    }
    
    // for(int i = row-1; i >= 0; i--){
    //     if(arr[i][col-1] == 0){
    //         dp[i][col-1] = 1;
    //     }
    // }
    
    // for(int j = col -2; j >= 0; j--){
    //     if(arr[row-1][col] == 0){
    //         dp[row-1][j] = 1;
    //     }
    // }
    
    // for(int i = row - 2; i >= 0; i--){
    //     for(int j = col-2; j >= 0; j--){

    //     	if(arr[i][j] == 0){
    //     		dp[i][j] = 1;
    //     	}
            
    //         if(arr[i+1][j] == 0 && arr[i+1][j+1] == 0 && arr[i][j+1] == 0 && arr[i][j] == 0){
    //             dp[i][j] = min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1])) + 1;
    //         }
    //     }
    // }
    
    // int ans = 1;
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //     	cout << dp[i][j];
    //         if(dp[i][j] > ans){
    //             ans = dp[i][j];
    //         }
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < row; i++){
    	if(arr[i][0] == 0){
    		dp[i][0] = 1;
    	}
    }

    for(int j = 1; j < col; j++){
    	if(arr[0][j] == 0){
    		dp[0][j] = 1;
    	}
    }

    for(int i = 1; i < row; i++){
    	for(int j = 1; j < col; j++){

    		if(arr[i][j] == 0){
    			dp[i][j] = 1;
    		}
    		if((arr[i][j] == 0 )&& (arr[i-1][j] == 0) && (arr[i][j-1] == 0) && (arr[i-1][j-1] == 0)){
    			dp[i][j] = min(dp[i][j-1],min(dp[i-1][j] , dp[i-1][j-1])) + 1;
    		}

    		
    	}
    }


    int max = 1;

    for(int i = 0; i < row; i++){
    	for(int j = 0; j < col; j++){
    		if(max < dp[i][j]){
    			max = dp[i][j];
    		}
    	}
    }

    
    for(int i = 0; i < row; i++){
        delete[] dp[i];
    }
    
    delete[] dp;
    return max;
    
      
}
int main(){
	int m , n;
	cin >> m >> n;
	int **arr = new int*[m];
	for(int i = 0; i < n; i++){
		arr[i] = new int[n];
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}

	int len = findMaxSquareWithAllZeros(arr,m,n);
	for(int i = 0; i < m; i++){
		delete[] arr[i];
	}
	delete[] arr;
	cout << len << endl;
	return 0;
}