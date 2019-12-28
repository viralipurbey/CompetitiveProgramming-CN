#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> v, string s1, string s2){
    
    int m = s1.length();
    int n = s2.length();
    int **dp = new int*[m+1];
    for(int i = 0; i <= m; i++){
        dp[i] = new int[n+1];
    }
    
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }
    
    for(int j = 0; j <= n; j++){
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[m-i] == s2[n-j]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int option1 = 1 + dp[i-1][j-1];
                int option2 = 1 + dp[i][j-1];
                int option3 = 1 + dp[i-1][j];
                dp[i][j] = min(option1,min(option2, option3));
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

int main() {
	// your code goes here
	
	string s;
	cin >> s;
	vector<string> v;
	while(s != "END"){
	    v.push_back(s);
	    cin >> s;
	    
	}
	
	string s1, s2;
	cin >> s1 >> s2;
	
	int ans = solve(v,s1,s2);
	cout << ans << endl;
	return 0;
}
