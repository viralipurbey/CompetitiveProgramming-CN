#include<bits/stdc++.h>
using namespace std;

bool sorted2(int a[], int n){
	if(n==1 || n==0){
		return true;
	}
	bool small_sorted = sorted2(a+1,n-1);
	if(!small_sorted){
		return false;
	}
	if(a[0] > a[1]){
		return false;
	}
	else
		return true;
}
bool sorted(int* a,int n){

	if(n==0 || n==1){
		return true;
	}
	if(a[0] > a[1]){
		return false;
	}
	return sorted(&a[1], n-1);
	/*
	bool is_smaller_sorted = sorted(&a[1], (n-1));
	if(is_smaller_sorted)
		return true;
	else 
		return false;
		*/
}
int main(){
	int arr[] = { 1, 3,2,5,7};
	bool flag = sorted(arr, 5);
	if(flag){
		cout <<"Sorted"<< endl;
	}
	else{
		cout <<"Not Sorted"<< endl;
	}
	return 0;
}