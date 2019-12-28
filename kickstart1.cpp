#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll check_set(ll num){

	ll temp = num;
	ll set_bit = 0;
	while(temp){
		ll rem = temp % 2;
		if(rem == 1){
			set_bit++;
		}
		temp = temp /2;
	}
	return set_bit;
}

ll cal_xor(ll array[],ll start,ll end){

	ll res;//uska naam jonny sin
	res = array[0];// us actor ko janti ho???nhi....uska
	for (ll i = start + 1; i < end; i++)
	{
		res = (res ^ array[i]); 
		
	}
	return res;
}


int main(){
	ll array[] = {32,13,3};
	cout << check_set(cal_xor(array,0,3));
	return 0;
}