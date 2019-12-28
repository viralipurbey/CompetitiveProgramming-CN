#include<bits/stdc++.h>
using namespace std;

int findTouches(int pos, int mask, vector<string> &v, int** dp){

	if(!(mask & (mask - 1))){
		return 0;
	}

	if(pos < 0){
		return 10000;
	}

	if(dp[pos][mask] != INT_MAX){
		return dp[pos][mask];
	}

	int nm1 = 0;
	int nm2 = 0;
	int touches = 0;

	for(int i = 0; i < v.size(); i++){

		if( mask & (1<<i)){
            touches++;
            if(v[i][pos]=='0'){
                nm1 |= (1<<i);
            }else{
                nm2|=(1<<i);
            }
        }
	}

	int ans1 = findTouches(pos - 1, nm1, v, dp) + findTouches(pos - 1, nm2, v, dp) + touches;
	int ans2 = findTouches(pos - 1, mask, v, dp);
	int ans = min(ans1 , ans2);
	dp[pos][mask] = ans;
	return ans;
}

int minimumTouchesRequired(int n, vector<string> v){

	int len = v[0].size();
	int **dp = new int*[len];

	int mask = (1 << n) - 1;

	for(int i = 0; i < len; i++){
		dp[i] = new int[1 << (n+1)];
		for(int j = 0; j < (1 << (n+1)); j++){
			dp[i][j] = INT_MAX;
		}
	}
	int ans = findTouches(len - 1, mask, v, dp);
	for(int i = 0;i < len; i++){
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

int main(){

	int n;

	cin >> n;

	vector<string> v;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}

	int ans = minimumTouchesRequired(n,v);
	cout << ans << endl;

}