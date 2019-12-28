#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2){
	if(s1.length() == 0 || s2[0] == '\0'){
		return 0;
	}

	if(s1[0] == s2[0]){
		s1 = s1.substr(1,s1.length());
		s2 = s2.substr(1);
		return 1 + LCS(s1, s2 );
	}
	else{
		string temp1 = s1.substr(1);
		string temp2 = s2.substr(1);
		return max(LCS(temp1, s2), LCS(s1, temp2));
	}
}

int LCS2Helper(string s1, string s2, int m, int n, int **dp){

	if(m == 0 || n == 0){
		return 0;
	}

	if(dp[m][n] >-1){
		return dp[m][n];
	}
	int ans;

	if(s1[0] == s2[0]){
		s1 = s1.substr(1,s1.length());
		s2 = s2.substr(1);
		ans = 1 + LCS2Helper(s1, s2, m-1, n-1, dp);
	}
	else{
		string temp1 = s1.substr(1);
		string temp2 = s2.substr(1);
		ans = max(LCS2Helper(temp1, s2, m-1, n, dp), LCS2Helper(s1, temp2, m, n-1, dp));
	}
	dp[m][n] = ans;
	return ans;

}

int LCS2(string s1, string s2){
	int m = s1.length();
	int n = s2.length();

	int **dp = new int*[m + 1];
	for(int i = 0; i <= m; i++){
		dp[i] = new int[n+1];
	}

	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = -1;
		}
	}

	int ans = LCS2Helper(s1, s2, m, n, dp);

	for(int i = 0; i <= m; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;

}

int LCS_i(string s1, string s2){
	int m = s1.length();
	int n = s2.length();

	int **dp = new int*[m+1];
	for(int i = 0; i <= m; i++){
		dp[i] = new int[n+1]();
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(s1[m -i] == s2[n- j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
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
	string s1, s2;
	cin >> s1 >> s2;

	int n = LCS2(s1, s2);
	cout << n << endl;

	int n1 = LCS_i(s1, s2);
	cout << n1 << endl;

	int n2 = LCS(s1, s2);
	cout << n2 << endl;
	return 0;
}
