#include<bits/stdc++.h>
using namespace std;
inline int max(int a, int b){
	return ((a > b) ? a : b);
}

int sum(int arr[], int size , int si = 0){
	int sum = 0;
	for(int i = si; i < size; i++){
		sum += arr[i];
	}
	return sum;
}
int main(){
	int a, b;
	cin >> a >> b;
	cout << max(a,b) << endl;
	int arr[5] = { 1,2 ,3 ,4, 5};
	cout << sum(arr, 5, 2) << endl;
	return 0;
}