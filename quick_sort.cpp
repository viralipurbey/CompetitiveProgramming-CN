#include<bits/stdc++.h>
using namespace std;

void swap(int & x, int & y ){
	int temp = x;
	x = y;
	y = temp;
}

int partition(int arr[],int si, int ei){

	int pivot = arr[si];
	int count = 0;
	for(int i = si+1; i <= ei; i++){
		if(arr[i] <= pivot){
			count++;
		}
	}
	
	int i = si;
	int j = ei;
	while(i < j){
		while((arr[i] <= pivot)&&(i < ei)){
			i++;
		}

		while(arr[j] > pivot){
			j--;
		}
		if(i < j){
			swap(arr[i],arr[j]);
		}
		
	}
	swap(arr[si],arr[j]);

	return (si+count);

}

void quick_sort(int arr[], int si, int ei){

	if(si >= ei){
		return;
	}

	int pi = partition(arr,si,ei);
	quick_sort(arr,si,pi-1);
	quick_sort(arr, pi+1, ei);
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	quick_sort(arr,0,n-1);

	for(int i = 0; i < n; i++){
		cout << arr[i] << endl;
	}
}