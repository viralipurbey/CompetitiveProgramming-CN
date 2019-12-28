#include <bits/stdc++.h>
#include <string>
#include <map>
using namespace std;

char nonrepeatingchar(string input){

	map<char,int> frequency;
	for(int i = 0; i < input.length(); i++){
		char curr_char = input[i];
		frequency[curr_char]++;
	}
	for(int i =0; i < input.length(); i++){
		if(frequency[input[i]] == 1){
			return input[i];
		}
	}

	return input[0];
	
}


int main(){

	string s;
	cin >> s;
	char ans = nonrepeatingchar(s);
	cout << ans << endl;
	return 0;
}