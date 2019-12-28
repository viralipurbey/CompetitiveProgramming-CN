#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int main(){

	int n , k, x;
	cin >> n >> k >> x;

	int arr[n];
	arr[0] = 1;
	arr[n-1] = x;

	int oneCount = 1;
	int nononeCount = 0;
	for(int i = 1; i < n; i++){
		int prevoneCount = oneCount;
		oneCount = (nononeCount * (k-1))%M;
		nononeCount = (prevoneCount + ((nononeCount * (k-2)))%M)%M; 
	}

	if(x == 1){
		cout << oneCount << endl;
	}
	else{
		cout << nononeCount << endl;
	}
	return 0;

}