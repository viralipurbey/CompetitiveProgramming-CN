#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){

	string s;
	cin >> s;

	int sum = 0; 
	int total = 0;
	for(int i = 0; i != s.length(); i++){
		int curr = s[i] - '0';
		sum = ((sum * 10)%MOD + (curr *(i+1))%MOD ) % MOD;
		total = (total + sum)%MOD;
	}
	cout << total << endl;

}