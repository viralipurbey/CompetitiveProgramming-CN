#include<bits/stdc++.h>
using namespace std;

int happiness(string s1, string s2, int l){

	int m = s1.length();
	int n = s2.length();

	int dp[m+1][n+1][l+1];

	for(int i = 0; i <= m; i++){
		dp[i][0][0] = 0;
		for(int k = 1; k <= l; k++){

			dp[i][0][k] = INT_MIN;
		}
	}

	for(int j = 0; j <= n; j++){
		dp[0][j][0] = 0;
		for(int k = 1; k <= l; k++){

			dp[0][j][k] = INT_MIN;
		}
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){

			dp[i][j][0] = 0;

			if(s1[i-1] == s2[j-1]){
				for(int k = 1; k <= l; k++){
					dp[i][j][k] = max( dp[i-1][j-1][k-1] + s1[i-1] , max( dp[i][j-1][k], dp[i-1][j][k]));
				}
			}
			else{
				for(int k = 1; k <= l; k++){
					dp[i][j][k] = max( dp[i-1][j][k] , dp[i][j-1][k]);
				}
			}
 		}
	}

	if(dp[m][n][l] < 0){
		return 0;
	}
	else{
		return dp[m][n][l];
	}
}


int main(){

	int t;
	cin >> t;

	while(t--){

		string s1, s2;
		cin >> s1 >> s2;
		int l;
		cin >> l;

		int ans = happiness(s1, s2, l);
		cout << ans << endl;
	}

}