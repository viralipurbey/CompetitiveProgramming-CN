#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

struct interval{
	int st;
	int et;
};	

bool compare(interval i1, interval i2){

	//return i1.st <i2.st;
	return i1.st > i2.st;
}

int main(){

	// interval arr[] = { {6,4},{3,4},{4,6},{8,13}};
	// sort(arr,arr+4,compare);
	// for(int i = 0; i < 4; i++){
	// 	cout << arr[i].st <<" "<< arr[i].et << endl;
	// }

	int arr[] = {1,3,2,3,5,7,6};
	//sort(arr, arr + 6);
	//sort(arr+2,arr+6
	sort(arr,arr+ 6);  // in decreasing order

	cout << binary_search(arr,arr+6,3) << endl;
	cout << lower_bound(arr,arr+6,60) - arr<< endl;

	cout << upper_bound(arr,arr+6,3) - arr << endl;

	cout << __gcd(10,6) << endl;
	cout <<pow(2.5,2) << endl;

	int x = 10;
	int y = 20;
	swap(x,y);
	cout << x <<endl;
	cout << y << endl;

	cout << max(13,18)<< endl;
	cout << min(14,18) << endl;


	// for(int i =0; i < 6; i++){
	// 	cout << arr[i] << endl;
 // 	}

	return 0;
}