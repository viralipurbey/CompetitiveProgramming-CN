#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
using namespace std;
void make_palindrome(string s){
	unordered_map<char,vector<int>> m;
	for(int i = 0; i < s.length(); i++){
		m[s[i]].push_back(i+1);
	}
	unordered_map<char,vector<int>>::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		cout<<it->first<< " : { ";
		for(int i = 0; i < it->second.size(); i++){
			cout << it->second[i] <<" ";
		}
		cout <<"}" << endl;
	}
	int count = 0;
	for(it = m.begin(); it!= m.end();it++){
		if(it->second.size() % 2 != 0){
			count++;
		}
	}
	if(count >1){
		cout <<"-1" << endl;
		return;
	}
	int length = s.length();
	int arr[length];
	int k = 0;
	for(it = m.begin(); it != m.end(); it++){
		if(it->second.size() % 2 != 0){

			arr[length/2] = it->second[0];

			for (int i = 1; i < it->second.size(); i+=2)
			{
				arr[k++] = it->second[i];
				arr[length - k] = it->second[i+1];
			}
		}
		else{
			for (int i = 0; i < it->second.size(); i+=2)
			{
				arr[k++] = it->second[i];
				arr[length - k] = it->second[i+1];
			}
		}	
	}
	for(int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(){
	string s;
	int T;
	cin >> T;
	while(T--){
		cin >> s;
		make_palindrome(s);
	}
}

// for(int i = 0; i < 26; i++){
// 	for(int j = 0; j < m[char(i+97)].size();j+=2){
// 		if((m[(char)(i+97)].size() - j) == 1){
// 			ans[s.length()/2] = m[getchar(i)][j];
// 			continue; 
// 		}
// 		ans[start] = m[getchar(i)][j];
// 		ans[end] = m[getchar(i)][j+1];
// 		start++;
// 		end--;
// 	}
// }