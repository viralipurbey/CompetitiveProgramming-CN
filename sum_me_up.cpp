#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int num;
		cin >> num;
		int sum = 0;
		int rem;
		while(num != 0){
			rem = num % 10;
			sum += rem;
			num /= 10;
		}
		cout << sum << endl;
	}
	return 0;
}