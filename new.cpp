#include<bits/stdc++.h>
using namespace std;
#define ll long long 
struct pair1{
	int i;
	ll j;
};
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

	ll res;
	res = array[0];
	for (ll i = start + 1; i < end; i++)
	{
		res = (res ^ array[i]); 
		
	}
	return res;
}

int main(){

	ll T;
	cin >> T;
	while(T--){
		ll n , q;
		cin >> n >> q;

		ll *arr = new ll[n];
		for(int i = 0; i < n; i+=1){
			cin >> arr[i];
		}

		pair1 mod[q];

		for(int i = 0; i < q; i+=1){
			cin >> mod[i].i >> mod[i].j;
		}
		
		for(int i = 0; i < q; i+=1){
			arr[mod[i].i] = mod[i].j;

			for(int j = n; j > 0; j--){
				for(int l = 0; l + j <= n;l++){
				    ll xorsum = cal_xor(arr,l,l+ j);
					ll set_bit = check_set(xorsum);
					cout << xorsum <<" "<< set_bit << endl;
					if(set_bit % 2 == 0){
						cout << n << " " << endl;
						break;				
					}

				}
				
			}

		}
	}

}