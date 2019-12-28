#include<bits/stdc++.h>
using namespace std;

void print_subsequences(string input, string output){

	if(input.empty()){
		cout << output << endl;
		return;
	}

	string small = input.substr(1);
	
	print_subsequences(small, output);
	print_subsequences(small, output + input[0]);
}


int main(){

	string s;
	cin >> s;
	string output = "";
	print_subsequences(s, output);
}