#include<bits/stdc++.h>
using namespace std;
void Rotate(int arr[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    int *temp = new int[d];
    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }
    for(int i = 0;(size-i) > d && i < size; i++){
        arr[i] = arr[i+d]; 
    }
    int k = 0;
    for(int i = size-d; i < size; i++){
        arr[i] = temp[k++];
    }
    for(int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }

}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10, 11};
	int n = 11;
	int d = 0;
	Rotate(arr, d,n);
}