#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
void countdiffnames(string s){
	string name = "";
	unordered_map<string,int> freq;
	for(int i =0; i < s.length(); i++){
		if(s[i] == ' ' ){
			freq[name]++;
			name = "";
		}
		else{
			name = name + s[i];
		}
	}
	freq[name]++;
	int count = 0;
	unordered_map<string,int>::iterator it;
	for(it = freq.begin(); it!= freq.end(); it++){
		if(it->second >= 2){
			count++;
		}
	}
	if(count == 0){
		cout <<"-1"<< endl;
		return;
	}
	for(it = freq.begin(); it!= freq.end(); it++){
		if(it->second >=2){
			cout << it->first <<" " << it->second << endl;
		}
	}
}


int main(){
	string s;
	getline(cin, s);
	countdiffnames(s);
}