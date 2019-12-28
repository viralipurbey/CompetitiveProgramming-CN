#include<bits/stdc++.h>
using namespace std;
static int i = 0;
int firstIndex(int input[] , int size, int x){
    if(size==1){
        if(input[0] == x){
            return i;
        }
        else
            return -1;
    }

    if(input[0] == x){
        return i;
    }
    else{
        i++;
        return firstIndex(input+1, size-1,x);
    }
}
int main(){
	int arr[] = { 1,4,2,4,6};
	int index = firstIndex(arr,5,4);
	cout << index << endl;
	return 0;
}