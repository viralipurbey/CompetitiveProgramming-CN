#include<bits/stdc++.h>
#define lli long long int 
using namespace std;

bool check(lli n, lli k){
	lli sum = 0;
	lli curr = n;
	while(curr > 0){
		sum += min(curr,k);
		curr -= k;
		curr -= (curr/10);
	}
	if((2 * sum) >= n){
		return true;
	}
	else{
		return false;
	}
}

lli find_min_k(lli n){

	lli min = 1;
	lli max = pow(10,18);
	lli ans;

	while(min <= max){
		lli mid = min + (max - min)/2;

		if(check(n,mid)){
			ans = mid;
			max = mid -1 ;
		}
		else{
			min = mid + 1;
		}
	}
	return ans;
}

int main(){
	lli n;
	cin >> n;

	lli min_k = find_min_k(n);
	cout << min_k << endl;
}