#include<bits/stdc++.h>
using namespace std;

int balancedBTs(int h){

	if((h == 0) || (h==1)){
		return 1;
	}

	int m = pow(10,9) + 7;

	int x = balancedBTs(h-1);
	int y = balancedBTs(h-2);

	long m1 = (long)x * x;
	long m2 = (long)x*y*2;

	int ans1 = (int)(m1 % m);
	int ans2 = (int)(m2 % m);

	int ans = (ans1 + ans2) % m;
	return ans;
}

int main(){
	int h;
	cin >> h;

	int count = balancedBTs(h);

	cout << count << endl;
	return 0;

}