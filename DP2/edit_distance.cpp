#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2){
	int m = s1.length();
	int n = s2.length();

	int **dp = new int*[m+1];
	for(int i = 0; i <= m; i++){
		dp[i] = new int[n+1]();
	}

	for(int i = 1; i <= m; i++){
		dp[i][0] = i;
	}

	for(int j = 1; j <= n; j++){
		dp[0][j] = j;
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(s1[m-i] == s2[n-j]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				int one = 1 + dp[i][j-1];   //inserted a character
				int two = 1 + dp[i-1][j-1];   //substituted a character
				int three = 1 + dp[i-1][j];   //deleted a character
				dp[i][j] = min(one, min(two, three));
			}
		}
	}
	int ans = dp[m][n];
	for(int i = 0; i <= m; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

int main(){

	string s1;
	string s2;

	cin >> s1 >> s2;
	int ans = editDistance(s1, s2);
	cout << ans << endl;
}