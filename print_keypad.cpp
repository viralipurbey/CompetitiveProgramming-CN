#include<bits/stdc++.h>
using namespace std;

string input[10] ={ "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void print_keypad(int num, string output){

	if(num == 0){
		cout << output << endl;
		return;
	}
	int small_num = num / 10;
	int rem = num % 10;

	for(int i = 0; i < input[rem].size(); i++){
		print_keypad(small_num, input[rem][i] + output);
	}
}

int main(){
	int num;
	cin >> num;
	string output = "";
	print_keypad(num,output);
}