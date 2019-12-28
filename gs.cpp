#include<bits/stdc++.h>
using namespace std;
long solve(long X, long Y, long Z){

	long start = 0;
	long end = Z;
	long num =(long)(X/Y) ;
	long curr_dist = 0;

	while(start <= end){

		long mid = start + (end - start)/2;
		if((X - num * mid) <= Y){

			curr_dist = mid;
			end = mid -1;
		}
		else{
			start = mid +1;
		}
	}
	
	long dist_left = Z - curr_dist;
	long ans = X - num * curr_dist - dist_left;
	return ans;
}
int main(){
	cout <<solve(100,70,50) << endl;
}