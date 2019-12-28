#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
	int size;
	cin >> size;
	int *arr = new int[size];
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}
	int x;
	cin >> x;

	// unordered_map<int,int> freq;
	// sort(arr,arr + size);

 //    int num_pairs;
	
	// for(int i = 0; i < size; i++){
        
 //        int target = x - arr[i];

 //        for(int l = i+1; l < size; l++){
 //        freq[arr[l]]++;
 //    	}
 //        for(int j = i+1, k = size-1; j < k;){
 //            if((arr[j] + arr[k]) == target){
 //                num_pairs = freq[arr[j]] * freq[arr[k]];
 //                for(int l = 0; l < num_pairs; l++)
 //                    cout << arr[i] <<" " <<arr[j] << " " << arr[k] << endl;
 //                j += freq[arr[j]];
 //                k -= freq[arr[k]];
 //            }
 //            else if((arr[j] + arr[k]) > target){
 //                k--;
 //            }
 //            else{
 //                j++;
 //            }
 //        }
    // }

    sort(arr,arr + size);
	
	 for(int i = 0; i < size-2; i++){
    	for(int j = i+1; j < size-1;j++){
            for(int k = j +1; j <size; k++){
                if((arr[i] + arr[j] + arr[k]) == x){
                    cout << arr[i] <<" "<< arr[j] <<" "<< arr[k] << endl;
                }
            }
        }
   }
    
	delete[] arr;
	return 0;
}

