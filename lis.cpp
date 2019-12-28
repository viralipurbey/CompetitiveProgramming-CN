#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<int> longestSubsequence(int *arr, int n){
    // Write your code here
    unordered_map<int,bool> mark;
    for(int i = 0; i < n; i++){
        mark[arr[i]] = true;
    }
    unordered_map<int,int> indices;
    for(int i = 0; i < n; i++){
        indices[arr[i]] = i; 
    }

    int curr;
    int max_len = 0;
    int start;
    int cstart;
    int len;

    
    unordered_map<int,bool>::iterator it;
    for(it = mark.begin(); it != mark.end(); it++){
        curr = it->first;
        len = 0;
        cstart = curr;
        while(mark[curr]){
            len++;
            mark[curr] = false;
            curr++;
        }
        curr = cstart -1;
        while(mark[curr]){
            len++;
            mark[curr] = false;
            curr--;
        }
        cstart = curr + 1;
        if(max_len == len){
            if(indices[start] > indices[cstart]){
                start = cstart;
            }
            
        }
        if(max_len < len){
            max_len = len;
            start = cstart;
        }

    }
    vector<int> ans;
    for(int i = 0; i < max_len;i++){
        ans.push_back(start++);
    }
    
    return ans;
    
}
int main(){
	int arr[] = { 2, 12, 9, 16, 10, 5, 3, 11, 4, 1, 8, 18, 12 };
	int n = 13;
	vector<int> ans = longestSubsequence(arr, n);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}

}