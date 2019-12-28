#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> remove_duplicates(vector<int> input){

	vector<int> result;
	sort(input.begin(), input.end());
	int curr = 0;
	int prev = 0;
	for(int i =0; i < input.size(); i++){
		curr = input[i];
		if(curr != prev){
			result.push_back(input[i]);
		}
		prev = input[i];
	}
	return result;
}


int main(){

	vector<int> v(6);
	for(int i = 0; i < v.size(); i++){
		cin >> v[i];
	}
	vector<int> res = remove_duplicates(v);
	vector<int>::iterator it;

	for(it = res.begin(); it != res.end(); it++){
		cout <<*it << endl;
	}
	
	return 0;
}