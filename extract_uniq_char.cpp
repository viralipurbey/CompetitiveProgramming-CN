#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;

char* uniquechar(string str){
	char* ans = new char[str.length()];
	unordered_map<char,int> freq;
	int j = 0;
	for(int i =0; i <str.length(); i++){
		if(freq[str[i]] == 0){
			ans[j++] = str[i];
		}
		freq[str[i]]++;
	}
	ans[j] = '\0';
	return ans;

}

int main(){
	string s;
	cin >> s;
	string ans = uniquechar(s);
	cout << ans << endl;
	return 0;
}