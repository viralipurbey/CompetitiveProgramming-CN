#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
void PairSum(int *input, int n) {	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
       unordered_map<int,int> freq;
        for(int i = 0; i < n; i++){
           freq[input[i]]++;
       }
        unordered_map<int,int>::iterator it;

        for(it = freq.begin(); it != freq.end(); it++){
            cout << it->first <<" " <<it->second << endl;
         }   

        for(it = freq.begin(); it != freq.end(); it++){
            int val = it->first;

            if(freq[-(val)] > 0){
                int num_pairs = freq[val] * freq[-(val)];
                cout << num_pairs << endl;
                if(val < -(val)){
                    for(int i =0; i < num_pairs; i++){
                        cout << val <<" " <<-(val) <<endl;
                    }
                }
                else{
                    for(int i =0; i < num_pairs; i++){
                        cout << -(val)<<" " <<val <<endl;
                    }
                }
            
                freq[-(val)] = 0;
            }
            freq[val] = 0;
            
        }

        for(it = freq.begin(); it != freq.end(); it++){
            cout << it->first <<" " <<it->second << endl;
         }   
     	
     	
 	}
int main(){
	int arr[] = {2, 1 ,-2, 2, 3};
	PairSum(arr, 5);
}