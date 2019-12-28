#include <bits/stdc++.h>
using namespace std;

int max_blessing(string s1, string s2, int k){

    
    int m = s1.length();
    int n = s2.length();
    char *str = new char[m + n];
    int **dp = new int*[m + 1];
    for(int i =  0; i <= m; i++){
        dp[i] = new int[n + 1]();
    }
    
    for(int i = 0; i <= m; i++){
        dp[i][0] = 0;
    }
    
    for(int j = 1; j <= n; j++){
        dp[0][j] = 0;
    }
    int count = 0;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[m - i] != s2[n - j])
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
                str[count++] = s1[m-i];
            }
                
        }
    }
    int max = dp[m][n];
    
    for(int i = 0; i <= s1.length(); i++){
        delete[] dp[i];
    }
    
    delete[] dp;
    int ans = 0;

    if(max < k){
        ans = 0;
    }
    else if( max == k){
        for(int i = 0; i < count; i++){
            ans += int(str[i]);
        }
    }
    else{
        cout << str << endl;
    }

    return ans;
}

int main()
{
    
    int t;
    cin >> t;
    while(t--){
        
        string s1, s2;
        cin >> s1;
        cin >> s2;
        int k ;
        cin >> k;
        
        int happiness = max_blessing(s1,s2,k);
        cout << happiness << endl;
    }
    return 0;
}
