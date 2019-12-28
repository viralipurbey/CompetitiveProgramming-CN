#include<bits/stdc++.h>
using namespace std;

int mincost(int **input, int si, int sj, int ei, int ej){
	if(si == ei && sj == ej){
		return input[ei][ej];
	}

	if(si > ei || sj > ej){
		return INT_MAX;
	}

	int option1 = mincost(input,si + 1, sj, ei, ej);
	int option2 = mincost(input,si + 1, sj + 1, ei, ej);
	int option3 = mincost(input, si, sj + 1, ei, ej);
	return input[si][sj] + min(option1,min(option2,option3));
}

int min_i(int **input, int si, int sj, int ei, int ej){

	int dp[ei + 1][ej + 1];

	dp[ei][ej] = input[ei][ej];

	for(int i = ei -1; i >= 0; i--){
		dp[i][ej] = dp[i+1][ej] + input[i][ej];
	}

	for(int j = ej -1; j >= 0; j--){
		dp[ei][j] = dp[ei][j+1] + input[ei][j];
	}

	for(int i = ei - 1; i >= 0; i--){
		for(int j = ej - 1; j >= 0; j--){
			dp[i][j] = min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1])) + input[i][j];
		}
	}

	int ans = dp[si][sj];
	return ans;
}
int main(){
	int **input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];

	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;

	cout << mincost(input, 0, 0 ,2,2) <<endl;
	cout << min_i(input,0,0,2,2) << endl;
	delete[] input[0];
	delete[] input[1];
	delete[] input[2];
	delete[] input;
	return 0;
}
