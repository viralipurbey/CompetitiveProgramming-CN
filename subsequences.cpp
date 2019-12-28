#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int subsequences(string input, string output[]){

	if(input.empty()){
		output[0] = "";
		return 1;
	}

	string smallstring = input.substr(1);
	int smalloutput = subsequences(smallstring, output);

	for(int i = 0; i < smalloutput; i++){
		output[smalloutput + i] = input[0] + output[i];
	}

	return (2 * smalloutput);
}

int main(){
	string input;
	cin >> input;
	int len = input.size();
	int m = pow(2,len);
	string *output = new string[m];
	int count = subsequences(input, output);

	for(int i = 0; i < count; i++){
		cout << output[i] << endl;
	}
	
}