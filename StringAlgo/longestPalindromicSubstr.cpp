#include<bits/stdc++.h>
using namespace std;

int countPalindromicSubstring(string s){
    int count = 0;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        // Even length
        int l = i;
        int r = i + 1;
        while(s[l] == s[r] && r < n && l >= 0){
            l--; r++;
            count++;
        }

        // Odd length
        l = i;
        r = i;
        while(s[l] == s[r] && r < n && l >= 0){
            l--; r++;
            count++;
        }
    }
    return count;

}
int longestPalindromicSubstring(string s){
    int max_len = 0;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        // Even length
        int l = i;
        int r = i + 1;
        while(s[l] == s[r] && r < n && l >= 0){
            l--; r++;
        }
        l++, r--;
        int curr_len = r-l +1;
        if(max_len < curr_len){
            max_len = curr_len;
        }

        // Odd length
        l = i;
        r = i;
        while(s[l] == s[r] && r < n && l >= 0){
            l--; r++;
        }
        l++,r--;
        curr_len = r-l +1;
        if(max_len < curr_len){
            max_len = curr_len;
        }
    }
    return max_len;
}

int main(){
    string s = "cbbbbaba";
    cout << longestPalindromicSubstring(s) << endl;
}