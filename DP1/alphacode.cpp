#include<bits/stdc++.h>
using namespace std;

int num_codes(int *n, int size){

	if(size == 1){
		return 1;
	}

	if(size == 0){
		return 1;
	}

	int output = num_codes(n, size -1);
	if(n[size-2] * 10 + n[size-1] <= 26){
		output += num_codes(n, size -2);
	}

	return output;
}

int num_codes_i(int *n, int size){
	int *arr = new int[size + 1];
	arr[0] = 1;
	arr[1] = 1;

	for(int i = 2; i <= size; i++){
		arr[i] = arr[i-1];
		if(n[i-2]*10 + n[i-1] <=26){
			arr[i] += arr[i-2];
		}
	}

	int output = arr[size];
	delete[] arr;
	return output;
}

int num_codes(int *n, int size, int *arr){

	if(size == 1){
		return 1;
	}

	if(size == 0){
		return 1;
	}

	if(arr[size] > 0){
		return arr[size];
	}

	int output = num_codes(n, size -1);
	if(n[size-2] * 10 + n[size-1] <= 26){
		output += num_codes(n, size -2);
	}
	arr[size] = output;
	return output;
}

int main(){

	string s;
	cin >> s;
	int size = s.length();
	int ans = num_codes_i(s,s.length());

}