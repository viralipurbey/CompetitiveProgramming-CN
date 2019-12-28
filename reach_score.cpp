#include <iostream>
using namespace std;

int noOfWays(int n){
    int *dp = new int[n + 11];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 0;
    dp[5] = 1;
    dp[6] = 1;
    dp[7] = 0;
    dp[8] = 1;
    dp[9] = 1;
    dp[10] = 2;
    
    for(int i = 12; i <= n; i++){
        dp[i] = dp[i-3] + dp[i-5] + dp[i-10];
    }
    
    for(int i = 0; i < n; i++){
        cout << dp[i] <<" ";
    }
    cout << endl;
    int ans = dp[n];
    delete[] dp;
    return ans;
}

int main() {
	//code
	int T;
	cin >> T;
	while(T--){
	    int n;
	    cin >> n;
	    int num = noOfWays(n);
	    cout << num << endl;
	}
	return 0;
}